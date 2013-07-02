
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

int inbuf5step = STEP_MARK;

int HandlerInBuf5( void )
{
   static int ip;
   static struct packet56 *pack;
   unsigned short n;

   if( verbose > 1 ) {
      printf( "HandlerInBuf5: save-load=%d.\n", inbuf5.save - inbuf5.load );
   }

   while( inbuf5.load != inbuf5.save ) {

      if( inbuf5step == STEP_NONE ) {
         inbuf5.save = inbuf5.load;
      }

      if( inbuf5step == STEP_MARK ) {
         if( MarkInBuf5() ) {
            ip = inbuf5.load;
            pack = (struct packet56 *)&inbuf5.data[ip];
            inbuf5step = STEP_HEADER;
         }
      }

      if( inbuf5step == STEP_HEADER ) {
         if( HeadInBuf5() ) {
            switch( pack->head.code ) {
            case 0xC0:
            case 0xE0:
               n = 1;
               break;
            case 0x30:
               n = 2;
               break;
            case 0x41:
               n = 4;
               break;
            default:
               n = 0;
               break;
            }
            DataInBuf5( &n );
            inbuf5step = STEP_DATA;
         }
      }

      if( inbuf5step == STEP_DATA ) {
         if( DataInBuf5( NULL ) ) {
            inbuf5step = STEP_HANDLER;
         }
      }

      if( inbuf5step == STEP_HANDLER ) {
         outpack1.blk &= ~BUF3KIT_BLK5;
         outpack2.blk &= ~BUF3KIT_BLK5;
         outpack3.blk &= ~BUF3KIT_BLK5;
         outpack4.blk &= ~BUF3KIT_BLK5;
         outpack5.blk &= ~BUF3KIT_BLK5;
         outpack6.blk &= ~BUF3KIT_BLK5;
         HandlerInPack5( pack, inbuf5.load - ip );
         if( outpack5.nload >= outpack5.nsave ) {
            outpack5.nsave = outpack5.nload = 0;
            stat.in |= FLAG_BUF5;
            CheckStatus();
            ControlLed4( 0 );
         }
         SendOutPack5();
         inbuf5step = STEP_MARK;
      }

   }

   memset( (char *)inbuf5.data, 0, sizeof(inbuf5.data) );
   inbuf5.save = inbuf5.load = 0;

   return( inbuf5step );
}

int MarkInBuf5( void )
{
   unsigned char b;
   int i;

   while( inbuf5.load < inbuf5.save ) {
      i = inbuf5.load;
      b = inbuf5.data[i];
      if( 1 ) {
         return( 1 );
      }
      inbuf5.load++;
   }

   return( 0 );
}

int HeadInBuf5( void )
{
   static unsigned int nhead = sizeof(struct header56);

   if( inbuf5.save - inbuf5.load >= nhead) {
      inbuf5.load += nhead;
      nhead = sizeof(struct header56);
      return( 1 );
   } else {
      inbuf5.load = inbuf5.save;
      nhead -= inbuf5.save - inbuf5.load; 
      return( 0 );
   }
}

int DataInBuf5( unsigned short *nd )
{
   static unsigned int ndata = 0;

   if( nd != NULL ) {
      ndata = *nd;
      return( 0 );
   }

   if( inbuf5.save - inbuf5.load >= ndata) {
      inbuf5.load += ndata;
      ndata = 0;
      return( 1 );
   } else {
      ndata -= inbuf5.save - inbuf5.load; 
      inbuf5.load = inbuf5.save;
      return( 0 );
   }
}

int HandlerInPack5( struct packet56 *pack, int size )
{
   int i;
   struct sostrts *sr;
   struct errusoi *ko;

   if( verbose > 1 ) {
      printf( "HandlerInPack5: size=%d code=%02x", size, pack->head.code );
      for( i = 0; i < size - sizeof(struct header56); i++ ) {
         printf( " data[0]=%02x", pack->data[i] );
      }
      printf( "\n" ); 
   }

   sr = (struct sostrts *)&outpack0.word_sost_rts_1;
   ko = (struct errusoi *)&outpack0.k_o;

   switch( pack->head.code ) {
   case 0x30:
      if( pack->data[1] & 0x01 ) {
         if( verbose > 0 ) {
            printf( "HandlerInPack5: 0x30 0x%02x 0x%02x - ERROR\n", 
               pack->data[0], pack->data[1] );
         }
         outpack0.kzv = 1;
         ko->r999 = 1;
         sr->dmv = 1;
      } else {
         sr->dmv = 0;
      }
      break;
   case 0x41:
      switch( pack->data[3] & 0x7e ) {
      case 0x00:
         memcpy( (char *)&outpack0.word_sost_0, pack->data, 4 );
         if( pack->data[2] & 0x02 ) {
            if( verbose > 0 ) {
               printf( "HandlerInPack5: 0x40 0x%02x 0x%02x 0x%02x 0x%02x - ERROR\n", 
                  pack->data[0], pack->data[1], pack->data[2], pack->data[3] );
            }
            outpack0.kzv = 1;
            ko->r999 = 1;
         }
         break;
      case 0x02:
         memcpy( (char *)&outpack0.word_sost_1, pack->data, 4 );
         break;
      case 0x04:
      case 0x06:
      case 0x08:
      case 0x0a:
      case 0x0c:
      case 0x16:
      case 0x18:
         memcpy( (char *)&outpack0.word_sost_2, pack->data, 4 );
         sr->dmv_kan = ( pack->data[1] >> 4 ) * 10  + ( pack->data[1] & 0x0f ); 
         break;
      case 0x1a:
         memcpy( (char *)&outpack0.word_sost_2, pack->data, 4 );
         break;
      case 0x24:
      case 0x26:
      case 0x28:
      case 0x2a:
      case 0x2c:
      case 0x2e:
         memcpy( (char *)&outpack0.word_sost_3, pack->data, 4 );
         break;
      case 0x30:
         memcpy( (char *)&outpack0.word_sost_sec, pack->data, 4 );
         break;
      case 0x36:
         memcpy( (char *)&outpack0.word_sost_time, pack->data, 4 );
         break;
      case 0x34:
         memcpy( (char *)&outpack0.word_sost_date, pack->data, 4 );
         break;
      default:
         break;
      }
      break;
   case 0xf8:
      ReadAring();
      break;
   default:
      break;
   }

   if( sr->svc1 || sr->svc2 || sr->dmv || sr->usoi ) {
      sr->rts = 1;
   } else {
      sr->rts = 0;
   }

   return( 0 );
}

int ReadAring( void )
{
   int i;

   i = outpack5.nsave;
   outpack5.buf[i].data[0] = 0x41;
   outpack5.buf[i].size = 1;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;
   SendOutPack5();

   return( 0 );
}

int SendOutPack5( void )
{
   int i;
   int j;

   if( outpack5.nload >= outpack5.nsave ) {
      return( 0 );
   } else if( ! outpack5.blk ) {
      i = outpack5.nload;
      j = outbuf5.save;
      if( sizeof(outbuf5.data) - j < outpack5.buf[i].size ) {
         return( -1 );
      }
      memcpy( &outbuf5.data[j], outpack5.buf[i].data, outpack5.buf[i].size );
      outbuf5.save += outpack5.buf[i].size;
      outpack5.nload++;
      if( verbose > 1 ) {
         printf( "SendOutPack5: size=%d cmd=%08x.\n", 
            outpack5.buf[i].size, outpack5.buf[i].cmd );
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK0 ) {
         outpack5.blk |= BUF3KIT_BLK0;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK1 ) {
         outpack5.blk |= BUF3KIT_BLK1;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK2 ) {
         outpack5.blk |= BUF3KIT_BLK2;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK3 ) {
         outpack5.blk |= BUF3KIT_BLK3;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK4 ) {
         outpack5.blk |= BUF3KIT_BLK4;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK5 ) {
         outpack5.blk |= BUF3KIT_BLK5;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLK6 ) {
         outpack5.blk |= BUF3KIT_BLK6;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_BLKT ) {
         outpack5.blk |= BUF3KIT_BLKT;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT0 ) {
         SendOutPack0();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT1 ) {
         SendOutPack1();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT2 ) {
         SendOutPack2();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT3 ) {
         SendOutPack3();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT4 ) {
         SendOutPack4();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT5 ) {
         SendOutPack5();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack6();
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_DEC ) {
         outpack5.nload -= outpack5.buf[i].param;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_KRK ) {
//         outpack0.krk = outpack5.buf[i].param;
         outpack0.link = outpack5.buf[i].param;
      }
      if( outpack5.buf[i].cmd & BUF3KIT_CMD_END ) {
         outpack5.nsave = outpack5.nload = 0;
         stat.in |= FLAG_BUF5;
         CheckStatus();
         ControlLed4( 0 );
      }
      return( outpack5.buf[i].size ); 
   }

   return( 0 );
}

