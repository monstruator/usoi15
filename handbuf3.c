
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

int inbuf3step = STEP_MARK;

int HandlerInBuf3( void )
{
   static int ip;
   static struct packet34 *pack;
   unsigned short n;
   int i;

	printf("HIB3\n");
   if( verbose > 1 ) {
      printf( "HandlerInBuf3: save-load=%d.\n", inbuf3.save - inbuf3.load );
   }

   while( inbuf3.load != inbuf3.save ) {

      if( inbuf3step == STEP_NONE ) {
         inbuf3.save = inbuf3.load;
      }

      if( inbuf3step == STEP_MARK ) {
         if( MarkInBuf3() ) {
            ip = inbuf3.load;
            pack = (struct packet34 *)&inbuf3.data[ip];
            inbuf3step = STEP_HEADER;
         }
      }

      if( inbuf3step == STEP_HEADER ) {
         if( HeadInBuf3() ) {
            inbuf3step = STEP_DATA;
            switch( pack->head.pream ) {
            case 0x3332:
               n = 3;
               break;
            case 0x3635:
               i = inbuf3.load;
               n = inbuf3.data[i];
               break;
            default:
               n = 0;
               break;
            }
            DataInBuf3( &n );
         }
      }

      if( inbuf3step == STEP_DATA ) {
         if( DataInBuf3( NULL ) ) {
            inbuf3step = STEP_HANDLER;
         }
      }

      if( inbuf3step == STEP_HANDLER ) {
         outpack1.blk &= ~BUF3KIT_BLK3;
         outpack2.blk &= ~BUF3KIT_BLK3;
         outpack3.blk &= ~BUF3KIT_BLK3;
         outpack4.blk &= ~BUF3KIT_BLK3;
         outpack5.blk &= ~BUF3KIT_BLK3;
         outpack6.blk &= ~BUF3KIT_BLK3;
         outpack7.blk &= ~BUF3KIT_BLK3;

         HandlerInPack3( pack , inbuf3.load - ip );
         if( outpack3.nload >= outpack3.nsave ) {
            outpack3.nsave = outpack3.nload = 0;
            stat.in |= FLAG_BUF3;
            CheckStatus();
            ControlLed3( 0 );
         }
         SendOutPack3();
         inbuf3step = STEP_MARK;
      }

   }

   memset( (char *)inbuf3.data, 0, sizeof(inbuf3.data) );
   inbuf3.save = inbuf3.load = 0;

   return( inbuf3step );
}

int MarkInBuf3( void )
{
   unsigned char b;
   int i;
   static int nmark = 0;

   while( inbuf3.load < inbuf3.save ) {

      i = inbuf3.load;
      b = inbuf3.data[i];

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
         
      inbuf3.load++;

      if( nmark >= 2 ) {
         inbuf3.load -= nmark;
         nmark = 0;
         return( 1 );
      }
   }

   return( 0 );
}

int HeadInBuf3( void )
{
   static unsigned int nhead = sizeof(struct header34);

   if( inbuf3.save - inbuf3.load >= nhead) {
      inbuf3.load += nhead;
      nhead = sizeof(struct header34);
      return( 1 );
   } else {
      inbuf3.load = inbuf3.save;
      nhead -= inbuf3.save - inbuf3.load; 
      return( 0 );
   }
}

int DataInBuf3( unsigned short *nd )
{
   static unsigned int ndata = 0;

   if( nd != NULL ) {
      ndata = *nd;
      return( 0 );
   }

   if( inbuf3.save - inbuf3.load >= ndata) {
      inbuf3.load += ndata;
      ndata = 0;
      return( 1 );
   } else {
      ndata -= inbuf3.save - inbuf3.load; 
      inbuf3.load = inbuf3.save;
      return( 0 );
   }
}

int HandlerInPack3( struct packet34 *pack, int size )
{
   int i;
   struct sostrts *sr;
   struct errusoi *ko;

   if( verbose > 0 ) {
      printf( "HandlerInPack3: size=%d pream=%04x code=%02x", 
         size, pack->head.pream, pack->head.code );
      for( i = 0; i < size - sizeof(struct header34); i++ ) {
         printf( " data[%d]=%02x", i, pack->data[i] );
      }
      printf( "\n" ); 
   }

   sr = (struct sostrts *)&outpack0.word_sost_rts_1;
   ko = (struct errusoi *)&outpack0.k_o;

   if( ( pack->head.pream == 0x3332 ) && ( size == 6 ) && ( mode.pr == 0 ) )  {
      switch( pack->head.code ) {
      case 0x71:
         if( ( pack->data[0] * 256 + pack->data[1] ) < 0xc8 ) {
            outpack0.kzv = 1;
            ko->svc2 = 1;
         }
         break;
      case 0x72:
         if( ! ( pack->data[1] & 0x01 ) ) {
            outpack0.kzv = 1;
            ko->a9 = 1;
            ko->bu1 = 1;
         }
         if( ! ( pack->data[1] & 0x02 ) ) {
            outpack0.kzv = 1;
            ko->a10 = 1;
            ko->bu1 = 1;
         }
         if( ! ( pack->data[1] & 0x04 ) ) {
            outpack0.kzv = 1;
            ko->a11 = 1;
            ko->bu1 = 1;
         }
         if( ! ( pack->data[1] & 0x08 ) ) {
            outpack0.kzv = 1;
            ko->a12 = 1;
            ko->bu1 = 1;
         }
         if( ! ( pack->data[1] & 0x10 ) ) {
            outpack0.kzv = 1;
            ko->a13 = 1;
            ko->bu1 = 1;
         }
         if( ! ( pack->data[1] & 0x20 ) ) {
            outpack0.kzv = 1;
            ko->a14 = 1;
            ko->bu1 = 1;
         }
         break;
      case 0x74:
         if( ! ( pack->data[1] & 0x01 ) ) {
            outpack0.kzv = 1;
            ko->a15 = 1;
            ko->bu1 = 1;
         }
         break;
      case 0x75:
         if( ! ( pack->data[1] & 0x01 ) ) {
            outpack0.kzv = 1;
            ko->r90_1 = 1;
            ko->bu1 = 1;
         }
         break;
      default:
         break;
      }
   }

   if( ( pack->head.pream == 0x3332 ) && ( size == 6 ) && ( mode.pr == 1 ) )  {
      switch( pack->head.code ) {
      case 0x71:
         if( ( pack->data[0] * 256 + pack->data[1] ) < 0xc8 ) {
            outpack0.kzv = 1;
            ko->svc2 = 1;
         }
         break;
      case 0x72:
//         if( pack->data[1] & 0x01 ) {
//            outpack0.kzv = 1;
//            ko->a9 = 1;
//            ko->bu1 = 1;
//         }
//         if( pack->data[1] & 0x02 ) {
//            outpack0.kzv = 1;
//            ko->a10 = 1;
//            ko->bu1 = 1;
//         }
//         if( pack->data[1] & 0x04 ) {
//            outpack0.kzv = 1;
//            ko->a11 = 1;
//            ko->bu1 = 1;
//         }
//         if( pack->data[1] & 0x08 ) {
//            outpack0.kzv = 1;
//            ko->a12 = 1;
//            ko->bu1 = 1;
//         }
//         if( pack->data[1] & 0x10 ) {
//            outpack0.kzv = 1;
//            ko->a13 = 1;
//            ko->bu1 = 1;
//         }
//         if( pack->data[1] & 0x20 ) {
//            outpack0.kzv = 1;
//            ko->a14 = 1;
//            ko->bu1 = 1;
//         }
         break;
      case 0x74:
//         if( pack->data[1] & 0x01 ) {
//            outpack0.kzv = 1;
//            ko->a15 = 1;
//            ko->bu1 = 1;
//         }
         break;
      case 0x75:
         if( pack->data[1] & 0x01 ) {
            outpack0.kzv = 1;
            ko->r90_1 = 1;
            ko->bu1 = 1;
         }
         break;
      default:
         break;
      }
   }

   if( pack->head.pream == 0x3534 ) {
      stat.flag &= ~FLAG_SVC2;
   }

   if( sr->svc1 || sr->svc2 || sr->dmv || sr->usoi ) {
      sr->rts = 1;
   } else {
      sr->rts = 0;
   }

   return( 0 );
}

int SendOutPack3( void )
{
   int i,i1;
   int j;

//   printf("SOP3 l=%d s=%d blk=%d\n",outpack3.nload,outpack3.nsave,outpack3.blk);

   if( outpack3.nload >= outpack3.nsave ) {
      return( 0 );
   } else if( ! outpack3.blk ) {
      i = outpack3.nload;
      j = outbuf3.save;
      if( sizeof(outbuf3.data) - j < outpack3.buf[i].size ) {
         return( -1 );
      }
      memcpy( &outbuf3.data[j], outpack3.buf[i].data, outpack3.buf[i].size );
      outbuf3.save += outpack3.buf[i].size;
      outpack3.nload++;
      if( verbose > -1 ) {
         printf( "SendOutPack3: size=%d cmd=%08x.", 
         outpack3.buf[i].size, outpack3.buf[i].cmd );
		 for (i1=0;i1<outpack3.buf[i].size;i1++)
			printf(" %x ",outbuf3.data[i1]);printf("\n");
	
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK0 ) {
         outpack3.blk |= BUF3KIT_BLK0;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK1 ) {
         outpack3.blk |= BUF3KIT_BLK1;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK2 ) {
         outpack3.blk |= BUF3KIT_BLK2;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK3 ) {
         outpack3.blk |= BUF3KIT_BLK3;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK4 ) {
         outpack3.blk |= BUF3KIT_BLK4;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK5 ) {
         outpack3.blk |= BUF3KIT_BLK5;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK6 ) {
         outpack3.blk |= BUF3KIT_BLK6;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLK7 ) {
         outpack3.blk |= BUF3KIT_BLK7;
      }

      if( outpack3.buf[i].cmd & BUF3KIT_CMD_BLKT ) {
         outpack3.blk |= BUF3KIT_BLKT;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT0 ) {
         SendOutPack0();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT1 ) {
         SendOutPack1();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT2 ) {
         SendOutPack2();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT3 ) {
         SendOutPack3();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT4 ) {
         SendOutPack4();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT5 ) {
         SendOutPack5();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack6();
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_OUT7 ) {
         SendOutPack7();
      }

      if( outpack3.buf[i].cmd & BUF3KIT_CMD_DEC ) {
         outpack3.nload -= outpack3.buf[i].param;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_KRK ) {
//         outpack0.krk = outpack3.buf[i].param;
         outpack0.link = outpack3.buf[i].param;
			//printf("6=%d\n",outpack0.link);
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_SVC ) {
         stat.flag |= FLAG_SVC2;
      }
      if( outpack3.buf[i].cmd & BUF3KIT_CMD_END ) {
         outpack3.nsave = outpack3.nload = 0;
         stat.in |= FLAG_BUF3;
         CheckStatus();
         ControlLed3( 0 );
      }
      return( outpack3.buf[i].size ); 
   }

   return( 0 );
}

