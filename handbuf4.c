
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

int inbuf4step = STEP_MARK;

int HandlerInBuf4( void )
{
   static int ip;
   static struct packet34 *pack;
   unsigned short n;
   int i;
	printf("HIB4\n");
   if( verbose > 1 ) {
      printf( "HandlerInBuf4: save-load=%d.\n", inbuf4.save - inbuf4.load );
   }

   while( inbuf4.load != inbuf4.save ) {

      if( inbuf4step == STEP_NONE ) {
         inbuf4.save = inbuf4.load;
      }

      if( inbuf4step == STEP_MARK ) {
         if( MarkInBuf4() ) {
            ip = inbuf4.load;
            pack = (struct packet34 *)&inbuf4.data[ip];
            inbuf4step = STEP_HEADER;
         }
      }

      if( inbuf4step == STEP_HEADER ) {
         if( HeadInBuf4() ) {
            inbuf4step = STEP_DATA;
            switch( pack->head.pream ) {
            case 0x3332:
               n = 3;
               break;
            case 0x3635:
               i = inbuf4.load;
               n = inbuf4.data[i];
               break;
            default:
               n = 0;
               break;
            }
            DataInBuf4( &n );
         }
      }

      if( inbuf4step == STEP_DATA ) {
         if( DataInBuf4( NULL ) ) {
            inbuf4step = STEP_HANDLER;
         }
      }

      if( inbuf4step == STEP_HANDLER ) {
         outpack1.blk &= ~BUF3KIT_BLK4;
         outpack2.blk &= ~BUF3KIT_BLK4;
         outpack3.blk &= ~BUF3KIT_BLK4;
         outpack4.blk &= ~BUF3KIT_BLK4;
         outpack5.blk &= ~BUF3KIT_BLK4;
         outpack6.blk &= ~BUF3KIT_BLK4;
         outpack7.blk &= ~BUF3KIT_BLK4;

         HandlerInPack4( pack , inbuf4.load - ip );
         if( outpack4.nload >= outpack4.nsave ) {
            outpack4.nsave = outpack4.nload = 0;
            stat.in |= FLAG_BUF4;
            CheckStatus();
            ControlLed3( 0 );
         }
         SendOutPack4();
         inbuf4step = STEP_MARK;
      }

   }

   memset( (char *)inbuf4.data, 0, sizeof(inbuf4.data) );
   inbuf4.save = inbuf4.load = 0;

   return( inbuf4step );
}

int MarkInBuf4( void )
{
   unsigned char b;
   int i;
   static int nmark = 0;

   while( inbuf4.load < inbuf4.save ) {

      i = inbuf4.load;
      b = inbuf4.data[i];

      switch( nmark ) {
      case 0:
         if( ( b == 0x32 ) || ( b  == 0x35 ) ) {
            nmark = 1;
         }
         break;
      case 1:
         if( ( b == 0x33 ) || ( b == 0x36 ) ) {
            nmark = 2;
         } else {
            nmark = 0;
         }
         break;
      default:
         nmark = 0;
         break;
      }
         
      inbuf4.load++;

      if( nmark >= 2 ) {
         inbuf4.load -= nmark;
         nmark = 0;
         return( 1 );
      }
   }

   return( 0 );
}

int HeadInBuf4( void )
{
   static unsigned int nhead = sizeof(struct header34);

   if( inbuf4.save - inbuf4.load >= nhead) {
      inbuf4.load += nhead;
      nhead = sizeof(struct header34);
      return( 1 );
   } else {
      inbuf4.load = inbuf4.save;
      nhead -= inbuf4.save - inbuf4.load; 
      return( 0 );
   }
}

int DataInBuf4( unsigned short *nd )
{
   static unsigned int ndata = 0;

   if( nd != NULL ) {
      ndata = *nd;
      return( 0 );
   }

   if( inbuf4.save - inbuf4.load >= ndata) {
      inbuf4.load += ndata;
      ndata = 0;
      return( 1 );
   } else {
      ndata -= inbuf4.save - inbuf4.load; 
      inbuf4.load = inbuf4.save;
      return( 0 );
   }
}

int HandlerInPack4( struct packet34 *pack, int size )
{
   int i;
   struct sostrts *sr;
   struct errusoi *ko;

   if( verbose > 0 ) {
      printf( "HandlerInPack4: size=%d pream=%04x code=%02x", 
         size, pack->head.pream, pack->head.code );
      for( i = 0; i < size - sizeof(struct header34); i++ ) {
         printf( " data[%d]=%02x", i, pack->data[i] );
      }
      printf( "\n" ); 
   }

   sr = (struct sostrts *)&outpack0.word_sost_rts_1;
   ko = (struct errusoi *)&outpack0.k_o;

   if( ( pack->head.pream == 0x3332 ) && ( size == 6 ) )  {
      switch( pack->head.code ) {
      case 0x71:
         if( ( pack->data[0] * 256 + pack->data[1] ) < 0xc8 ) {
            outpack0.kzv = 1;
            ko->svc1 = 1;
         }
         break;
      case 0x72:
         if( pack->data[1] & 0x01 ) {
            outpack0.kzv = 1;
            ko->a1 = 1;
            ko->bu2 = 1;
         }
         if( pack->data[1] & 0x02 ) {
            outpack0.kzv = 1;
            ko->a3 = 1;
            ko->bu2 = 1;
         }
         if( pack->data[1] & 0x04 ) {
            outpack0.kzv = 1;
            ko->a4 = 1;
            ko->bu2 = 1;
         }
         if( pack->data[1] & 0x08 ) {
            outpack0.kzv = 1;
            ko->a5 = 1;
            ko->bu2 = 1;
         }
         if( pack->data[1] & 0x10 ) {
            outpack0.kzv = 1;
            ko->a7 = 1;
            ko->bu2 = 1;
         }
         if( pack->data[1] & 0x20 ) {
            outpack0.kzv = 1;
            ko->a8 = 1;
            ko->bu2 = 1;
         }
         break;
      case 0x74:
//         if( pack->data[1] & 0x3f ) {
//            outpack0.kzv = 1;
//            ko->a2 = 1;
//            ko->bu2 = 1;
//         }
         break;
      case 0x75:
         if( pack->data[1] & 0x01 ) {
            outpack0.kzv = 1;
            ko->r90_1 = 1;
            ko->bu2 = 1;
         }
         break;
      default:
         break;
      }
   }

   if( pack->head.pream == 0x3534 ) {
      stat.flag &= ~FLAG_SVC1;
   }

   if( sr->svc1 || sr->svc2 || sr->dmv || sr->usoi ) {
      sr->rts = 1;
   } else {
      sr->rts = 0;
   }

   return( 0 );
}

int SendOutPack4( void )
{
   int i;
   int j;

//   printf("SOP4 l=%d s=%d blk=%d\n",outpack4.nload,outpack4.nsave,outpack4.blk);

   if( outpack4.nload >= outpack4.nsave ) {
      return( 0 );
   } else if( ! outpack4.blk ) {
      i = outpack4.nload;
      j = outbuf4.save;
      if( sizeof(outbuf4.data) - j < outpack4.buf[i].size ) {
         return( -1 );
      }
      memcpy( &outbuf4.data[j], outpack4.buf[i].data, outpack4.buf[i].size );
      outbuf4.save += outpack4.buf[i].size;
      outpack4.nload++;
      if( verbose > -1 ) {
         printf( "SendOutPack4: size=%d cmd=%08x.\n", 
            outpack4.buf[i].size, outpack4.buf[i].cmd );
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK0 ) {
         outpack4.blk |= BUF3KIT_BLK0;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK1 ) {
         outpack4.blk |= BUF3KIT_BLK1;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK2 ) {
         outpack4.blk |= BUF3KIT_BLK2;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK3 ) {
         outpack4.blk |= BUF3KIT_BLK3;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK4 ) {
         outpack4.blk |= BUF3KIT_BLK4;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK5 ) {
         outpack4.blk |= BUF3KIT_BLK5;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLK6 ) {
         outpack4.blk |= BUF3KIT_BLK6;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_BLKT ) {
         outpack4.blk |= BUF3KIT_BLKT;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT0 ) {
         SendOutPack0();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT1 ) {
         SendOutPack1();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT2 ) {
         SendOutPack2();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT3 ) {
         SendOutPack3();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT4 ) {
         SendOutPack4();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT5 ) {
         SendOutPack5();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack6();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT7 ) {
         SendOutPack7();
      }

      if( outpack4.buf[i].cmd & BUF3KIT_CMD_DEC ) {
         outpack4.nload -= outpack4.buf[i].param;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_KRK ) {
//         outpack0.krk = outpack4.buf[i].param;
         outpack0.link = outpack4.buf[i].param;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_SVC ) {
         stat.flag |= FLAG_SVC1;
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_END ) {
         outpack4.nsave = outpack4.nload = 0;
         stat.in |= FLAG_BUF4;
         CheckStatus();
         ControlLed3( 0 );
      }
      return( outpack4.buf[i].size ); 
   }

   return( 0 );
}

