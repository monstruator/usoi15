
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

int ControlLed1( int cmd )
{
   static int sled = -1;
   int i;

   switch( cmd ) {
   case 0:
      if( ( sled == 1 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x23;
         outpack5.buf[i].data[1] = 0x00;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 0;
         return( 1 );
      }
      break;
   case 1:
      if( ( sled == 0 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x23;
         outpack5.buf[i].data[1] = 0x10;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 1;
         return( 1 );
      }
      break;
   case -1:
      sled = -1;
      break;
   default:
      break;
   }

   return( 0 );
}

int ControlLed2( int cmd )
{
   static int sled = -1;
   int i;

   switch( cmd ) {
   case 0:
      if( ( sled == 1 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x27;
         outpack5.buf[i].data[1] = 0x00;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 0;
         return( 1 );
      }
      break;
   case 1:
      if( ( sled == 0 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x27;
         outpack5.buf[i].data[1] = 0x10;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 1;
         return( 1 );
      }
      break;
   case -1:
      sled = -1;
      break;
   default:
      break;
   }

   return( 0 );
}

int ControlLed3( int cmd )
{
   static int sled = -1;
   int i;

   switch( cmd ) {
   case 0:
      if( ( sled == 1 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x25;
         outpack5.buf[i].data[1] = 0x00;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 0;
         return( 1 );
      }
      break;
   case 1:
      if( ( sled == 0 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x25;
         outpack5.buf[i].data[1] = 0x10;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 1;
         return( 1 );
      }
      break;
   case -1:
      sled = -1;
      break;
   default:
      break;
   }

   return( 0 );
}

int ControlLed4( int cmd )
{
   static int sled = -1;
   int i;

   switch( cmd ) {
   case 0:
      if( ( sled == 1 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x24;
         outpack5.buf[i].data[1] = 0x00;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 0;
         return( 1 );
      }
      break;
   case 1:
      if( ( sled == 0 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x24;
         outpack5.buf[i].data[1] = 0x10;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 1;
         return( 1 );
      }
      break;
   case -1:
      sled = -1;
      break;
   default:
      break;
   }

   return( 0 );
}

int ControlLed5( int cmd )
{
   static int sled = -1;
   int i;

   switch( cmd ) {
   case 0:
      if( ( sled == 1 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x26;
         outpack5.buf[i].data[1] = 0x00;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 0;
         return( 1 );
      }
      break;
   case 1:
      if( ( sled == 0 ) || (sled == -1 ) ) {
         i = outpack5.nsave;
         outpack5.buf[i].data[0] = 0x26;
         outpack5.buf[i].data[1] = 0x10;
         outpack5.buf[i].size = 2;
         outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
         outpack5.nsave++;
         SendOutPack5();
         sled = 1;
         return( 1 );
      }
      break;
   case -1:
      sled = -1;
      break;
   default:
      break;
   }

   return( 0 );
}

