
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

void HandlerTimeout( void )
{
   static unsigned short cr_com;
   static unsigned int count = 0;
   static unsigned int count1 = 0;
   static unsigned int count2 = 0;
   struct errusoi *ko;

   if( mode.scan1 ) {
      if( outpack1.nload == outpack1.nsave ) {
         outpack1.nload = outpack1.nsave = outpack1.blk = count1 = 0;
         HandlerCmdScan1();
      } else {
         if( ++count1 > 24 ) {
            outpack1.nload = outpack1.nsave = outpack1.blk = count1 = 0;
         }
      }
   }

   if( mode.rli1 ) {
		printf("HandlerTimeout nload=%d nsave=%d\n",outpack1.nload,outpack1.nsave);
      if( outpack1.nload == outpack1.nsave ) {
         outpack1.nload = outpack1.nsave = outpack1.blk = count1 = 0;
         HandlerCmdRli1();
      } else {
         if( ++count1 > 24 ) {
            outpack1.nload = outpack1.nsave = outpack1.blk = count1 = 0;
         }
      }
   }

   if( mode.rli2 ) {
		printf("HandlerTimeout nload=%d nsave=%d\n",outpack2.nload,outpack2.nsave);
      if( outpack2.nload == outpack2.nsave ) {
         outpack2.nload = outpack2.nsave = outpack1.blk = count2 = 0;
         HandlerCmdRli2();
      } else {
         if( ++count2 > 24 ) {
            outpack2.nload = outpack2.nsave = outpack2.blk = count2 = 0;
         }
      }
   }


   if( mode.scan2 ) {
      if( outpack2.nload == outpack2.nsave ) {
         outpack2.nload = outpack2.nsave = outpack2.blk = count2 = 0;
         HandlerCmdScan2();
      } else {
         if( ++count2 > 24 ) {
            outpack1.nload = outpack1.nsave = outpack2.blk = count2 = 0;
         }
      }
   }

   outpack1.blk &= ~BUF3KIT_BLKT;
   outpack2.blk &= ~BUF3KIT_BLKT;
   outpack3.blk &= ~BUF3KIT_BLKT;
   outpack4.blk &= ~BUF3KIT_BLKT;
   outpack5.blk &= ~BUF3KIT_BLKT;
   outpack6.blk &= ~BUF3KIT_BLKT;

   SendOutPack1();
   SendOutPack2();
   SendOutPack3();
   SendOutPack4();
   SendOutPack5();
   SendOutPack6();

   if( ( cr_com == outpack0.cr_com ) && ( stat.out != 0 ) ) {
      count++;
   } else {
      cr_com = outpack0.cr_com;
      count = 0;
   }

   if( count > 42 ) {
      if( verbose > 0 ) {
         printf( "Command %d abort timeout. stat.out=%x \n", outpack0.num_com,stat.out );
      }
      outpack0.kzv = 1;
      ko = (struct errusoi *)&outpack0.k_o;
//      ko->to = 1;
      if( ( stat.out & FLAG_BUF1 ) && ! ( stat.in & FLAG_BUF1 ) ) {
         ko->cpp1 = 1;
      }
      if( ( stat.out & FLAG_BUF2 ) && ! ( stat.in & FLAG_BUF2 ) ) {
         ko->cpp2 = 1;
      }
      if( ( stat.out & FLAG_BUF3 ) && ! ( stat.in & FLAG_BUF3 ) ) {
         if( stat.flag & FLAG_SVC2 ) {
            ko->svc2 = 1;
         } else {
            ko->bu1 = 1;
         }
      }
      if( ( stat.out & FLAG_BUF4 ) && ! ( stat.in & FLAG_BUF4 ) ) {
         if( stat.flag & FLAG_SVC1 ) {
            ko->svc1 = 1;
         } else {
            ko->bu2 = 1;
         }
      }
      if( ( stat.out & FLAG_BUF5 ) && ! ( stat.in & FLAG_BUF5 ) ) {
         ko->r999 = 1;
      }
      outpack0.cr_com++;
      ResetBuffers();
      ControlLed1( 0 );
      ControlLed2( 0 );
      ControlLed3( 0 );
      ControlLed4( 0 );
      ControlLed5( 0 );
   }

   SendOutPack0();
   ControlLed5( 1 );
}

