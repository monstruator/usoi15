
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

int inbuf7step = STEP_MARK;

int HandlerInBuf7( void )
{
   static int ip;
   static struct packet34 *pack;
   unsigned short n;
   int i;
	printf("HIB7\n");

   if( verbose > 1 ) {
      printf( "HandlerInBuf7: save-load=%d.\n", inbuf7.save - inbuf7.load );
   }

   while( inbuf7.load != inbuf7.save ) {

      if( inbuf7step == STEP_NONE ) {
         inbuf7.save = inbuf7.load;
      }

      if( inbuf7step == STEP_MARK ) {
         if( MarkInBuf7() ) {
            ip = inbuf7.load;
            pack = (struct packet34 *)&inbuf7.data[ip];
            inbuf7step = STEP_HEADER;
         }
      }

      if( inbuf7step == STEP_HEADER ) {
         if( HeadInBuf7() ) {
            inbuf7step = STEP_DATA;
            switch( pack->head.pream ) {
            case 0x3332:
               n = 3;
               break;
            case 0x3635:
               i = inbuf7.load;
               n = inbuf7.data[i];
               break;
            default:
               n = 0;
               break;
            }
            DataInBuf7( &n );
         }
      }

      if( inbuf7step == STEP_DATA ) {
         if( DataInBuf7( NULL ) ) {
            inbuf7step = STEP_HANDLER;
         }
      }

      if( inbuf7step == STEP_HANDLER ) {
         outpack1.blk &= ~BUF3KIT_BLK7;
         outpack2.blk &= ~BUF3KIT_BLK7;
         outpack3.blk &= ~BUF3KIT_BLK7;
         outpack4.blk &= ~BUF3KIT_BLK7;
         outpack5.blk &= ~BUF3KIT_BLK7;
         outpack6.blk &= ~BUF3KIT_BLK7;
         outpack7.blk &= ~BUF3KIT_BLK7;

         HandlerInPack7( pack , inbuf7.load - ip );
         if( outpack7.nload >= outpack7.nsave ) {
            outpack7.nsave = outpack7.nload = 0;
            stat.in |= FLAG_BUF7;
            CheckStatus();
            ControlLed3( 0 );
         }
         SendOutPack7();
         inbuf7step = STEP_MARK;
      }

   }

   memset( (char *)inbuf7.data, 0, sizeof(inbuf7.data) );
   inbuf7.save = inbuf7.load = 0;

   return( inbuf7step );
}

int MarkInBuf7( void )
{
   unsigned char b;
   int i;
   static int nmark = 0;

   while( inbuf7.load < inbuf7.save ) {

      i = inbuf7.load;
      b = inbuf7.data[i];

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
         
      inbuf7.load++;

      if( nmark >= 2 ) {
         inbuf7.load -= nmark;
         nmark = 0;
         return( 1 );
      }
   }

   return( 0 );
}

int HeadInBuf7( void )
{
   static unsigned int nhead = sizeof(struct header34);

   if( inbuf7.save - inbuf7.load >= nhead) {
      inbuf7.load += nhead;
      nhead = sizeof(struct header34);
      return( 1 );
   } else {
      inbuf7.load = inbuf7.save;
      nhead -= inbuf7.save - inbuf7.load; 
      return( 0 );
   }
}

int DataInBuf7( unsigned short *nd )
{
   static unsigned int ndata = 0;

   if( nd != NULL ) {
      ndata = *nd;
      return( 0 );
   }

   if( inbuf7.save - inbuf7.load >= ndata) {
      inbuf7.load += ndata;
      ndata = 0;
      return( 1 );
   } else {
      ndata -= inbuf7.save - inbuf7.load; 
      inbuf7.load = inbuf7.save;
      return( 0 );
   }
}

int HandlerInPack7( struct packet34 *pack, int size )
{
   int i;
   struct sostrts *sr;
   struct errusoi *ko;

   if( verbose > 0 ) {
      printf( "HandlerInPack7: size=%d pream=%04x code=%02x", 
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

int SendOutPack7( void )
{
   int i,i1;
   int j;
//   printf("SOP7 l=%d s=%d blk=%d\n",outpack7.nload,outpack7.nsave,outpack7.blk);

   if( outpack7.nload >= outpack7.nsave ) {
      return( 0 );
   } else if( ! outpack7.blk ) {
      i = outpack7.nload;
      j = outbuf7.save;
      if( sizeof(outbuf7.data) - j < outpack7.buf[i].size ) {
         return( -1 );
      }
      memcpy( &outbuf7.data[j], outpack7.buf[i].data, outpack7.buf[i].size );
      outbuf7.save += outpack7.buf[i].size;
      outpack7.nload++;
      if( verbose > -1 ) {
         printf( "SendOutPack7: size=%d cmd=%08x.\n", 
            outpack7.buf[i].size, outpack7.buf[i].cmd );
		 for (i1=0;i1<outpack7.buf[i].size;i1++)
			printf(" %x ",outbuf7.data[i1]);printf("\n");

      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK0 ) {
         outpack7.blk |= BUF3KIT_BLK0;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK1 ) {
         outpack7.blk |= BUF3KIT_BLK1;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK2 ) {
         outpack7.blk |= BUF3KIT_BLK2;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK3 ) {
         outpack7.blk |= BUF3KIT_BLK3;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK4 ) {
         outpack7.blk |= BUF3KIT_BLK4;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK5 ) {
         outpack7.blk |= BUF3KIT_BLK5;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK6 ) {
         outpack7.blk |= BUF3KIT_BLK6;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLK7 ) {
         outpack7.blk |= BUF3KIT_BLK7;
      }

      if( outpack7.buf[i].cmd & BUF3KIT_CMD_BLKT ) {
         outpack7.blk |= BUF3KIT_BLKT;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT0 ) {
         SendOutPack0();
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT1 ) {
         SendOutPack1();
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT2 ) {
         SendOutPack2();
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT3 ) {
         SendOutPack3();
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT4 ) {
         SendOutPack4();
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT5 ) {
         SendOutPack5();
      }
      if( outpack4.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack6();
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack7();
      }

      if( outpack7.buf[i].cmd & BUF3KIT_CMD_DEC ) {
         outpack7.nload -= outpack7.buf[i].param;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_KRK ) {
//         outpack0.krk = outpack7.buf[i].param;
         outpack0.link = outpack7.buf[i].param;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_SVC ) {
         stat.flag |= FLAG_SVC1;
      }
      if( outpack7.buf[i].cmd & BUF3KIT_CMD_END ) {
         outpack7.nsave = outpack7.nload = 0;
         stat.in |= FLAG_BUF7;
         CheckStatus();
         ControlLed3( 0 );
      }
      return( outpack7.buf[i].size ); 
   }

   return( 0 );
}

