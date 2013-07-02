
#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

int HandlerInBuf0( void )
{
   struct header0 *h;

   h = (struct header0 *)inbuf0.data;

   if( inbuf0.size < sizeof(struct header0) ) {
      if( verbose > 1 ) {
         printf( "Invalid size message 0: %d bytes.\n", inbuf0.size );
      }
   } else if( h->type != 70 ) {
      if( verbose > 1 ) {
         printf( "Invalid type message 0: %d.\n", h->type );
      }
   } else {
      if( verbose > 1 ) {
         printf( "Ok message 70: %d byte.\n", inbuf0.size - sizeof(struct header0) ); 
      }
      memset( (char *)&inpack0, 0, sizeof(inpack0) );
      memcpy( (char *)&inpack0, (char *)h + sizeof(struct header0), 
         inbuf0.size - sizeof(struct header0) );
      HandlerInPack0();
      ControlLed5( 0 );
   }

   memset( (char *)inbuf0.data, 0, sizeof(inbuf0.data) );
   inbuf0.size = 0;

   return( 0 );
}

void HandlerInPack0( void )
{
   static unsigned short cr_com = 0;

   if( inpack0.pr_bearing ) {
      mode.kar = GetKAR( &inpack0.p, &inpack0.k );
      HandlerCmdKar( mode.kar );
   }

//   if( mode.scan1 ) {
//      HandlerCmdScan1();
//   }

//   if( mode.scan2 ) {
//      HandlerCmdScan2();
//   }

   if( inpack0.cr_com != cr_com ) {
      if( verbose > 0 ) {
         printf( "New command: %d.\n", inpack0.num_com );
      }
      cr_com = inpack0.cr_com;
      outpack0.num_com = inpack0.num_com;
      outpack0.lp2_param = inpack0.a_params[0];
      outpack0.kzv = 0;
      outpack0.k_o = 0;
      outpack0.ended_loop = 0;
      outpack0.krk = 0;
      outpack0.link = 0;

      ResetBuffers();
      ControlLed5( 0 );

      switch( outpack0.num_com ) {
      case 0:
         outpack0.cr_com++;
         break;
      case 1:
         switch( mode.pr ) {
         case 0:
            HandlerCmd1pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd1mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }            
         break;
      case 2:
         switch( mode.pr ) {
         case 0:
            HandlerCmd2pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd2mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }            
         break;
      case 3:
         switch( mode.pr ) {
         case 1:
            HandlerCmd3mo3a( inpack0.a_params[0] );
//            HandlerCmd3mo3a( inpack0.k );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }   
         break;
      case 4:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 5:
         switch( mode.pr ) {
         case 0:
            HandlerCmd5pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd5mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }            
         break;
      case 6:
         switch( mode.pr ) {
         case 1:
            HandlerCmd6mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }   
         break;
      case 7:
         switch( mode.pr ) {
         case 0:
            HandlerCmd7pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd7mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }            
         break;
      case 8:
         switch( mode.pr ) {
         case 1:
            HandlerCmd8mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }   
         break;
      case 9:
         switch( mode.pr ) {
         case 0:
            HandlerCmd9pr32( inpack0.a_params[0], inpack0.a_params[1], 
               inpack0.a_params[2] );
            break;
         case 1:
            HandlerCmd9mo3a( inpack0.a_params[0], inpack0.a_params[1], 
               inpack0.a_params[2] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }   
         break;
      case 10:
         switch( mode.pr ) {
         case 0:
            HandlerCmd10pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd10mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 11:
         switch( mode.pr ) {
         case 0:
            HandlerCmd11pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd11mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 12:
         switch( mode.pr ) {
         case 0:
            HandlerCmd12pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd12mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 13:
         switch( mode.pr ) {
         case 1:
            HandlerCmd13mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 14:
         switch( mode.pr ) {
         case 0:
            HandlerCmd14pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd14mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 15:
         switch( mode.pr ) {
         case 1:
            HandlerCmd15mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 16:
      case 17:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 18:
         switch( mode.pr ) {
         case 0:
            HandlerCmd18pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd18mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 19:
         switch( mode.pr ) {
         case 0:
            HandlerCmd19pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd19mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 20:
         switch( mode.pr ) {
         case 0:
            HandlerCmd20pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd20mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 21:
         switch( mode.pr ) {
         case 0:
            HandlerCmd21pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd21mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 22: //Заглушка!!!
         outpack0.kzv = 0;
         outpack0.cr_com++;
         break;
      case 23:
      case 24:
      case 25:
      case 26:
      case 27:
      case 28:
      case 29:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 30:
         switch( mode.pr ) {
         case 0:
            HandlerCmd30pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd30mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 31:
         switch( mode.pr ) {
         case 0:
            HandlerCmd31pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd31mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 32:
         switch( mode.pr ) {
         case 0:
            HandlerCmd32pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd32mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 33:
         switch( mode.pr ) {
         case 0:
            HandlerCmd33pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd33mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 34:
      case 35:
      case 36:
      case 37:
      case 38:
      case 39:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 40:
         switch( mode.pr ) {
         case 1:
            HandlerCmd40mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 41:
         switch( mode.pr ) {
         case 1:
            HandlerCmd41mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 42:
         switch( mode.pr ) {
         case 1:
            HandlerCmd42mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 43:
         switch( mode.pr ) {
         case 1:
            HandlerCmd43mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 44:
      case 45:
      case 46:
      case 47:
      case 48:
      case 49:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 50:
         switch( mode.pr ) {
         case 0:
            HandlerCmd50pr32();
            break;
         case 1:
            HandlerCmd50mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 51:
      case 52:
      case 53:
      case 54:
      case 55:
      case 56:
      case 57:
      case 58:
      case 59:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 60:
         switch( mode.pr ) {
         case 0:
            HandlerCmd60pr32();
            break;
         case 1:
            HandlerCmd60mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 61:
         switch( mode.pr ) {
         case 0:
            HandlerCmd61pr32();
            break;
         case 1:
            HandlerCmd61mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 62:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 63:
         switch( mode.pr ) {
         case 0:
            HandlerCmd63pr32();
            break;
         case 1:
            HandlerCmd63mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 64:
         switch( mode.pr ) {
         case 0:
            HandlerCmd64pr32();
            break;
         case 1:
            HandlerCmd64mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 65:
         switch( mode.pr ) {
         case 0:
            HandlerCmd65pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd65mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 66:
      case 67:
      case 68:
      case 69:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 70:
         switch( mode.pr ) {
         case 1:
            HandlerCmd70mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 71:
         switch( mode.pr ) {
         case 1:
            HandlerCmd71mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 72:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 73:
         switch( mode.pr ) {
         case 1:
            HandlerCmd73mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 74:
         switch( mode.pr ) {
         case 1:
            HandlerCmd74mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 75:
         switch( mode.pr ) {
         case 1:
            HandlerCmd75mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 76:
      case 77:
      case 78:
      case 79:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 80:
         switch( mode.pr ) {
         case 0:
            HandlerCmd80pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd80mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 81:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 82:
         switch( mode.pr ) {
         case 0:
            HandlerCmd82pr32();
            break;
         case 1:
            HandlerCmd82mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 83:
         switch( mode.pr ) {
         case 0:
            HandlerCmd83pr32();
            break;
         case 1:
            HandlerCmd83mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 84:
      case 85:
      case 86:
      case 87:
      case 88:
      case 89:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 90:
         switch( mode.pr ) {
         case 0:
            HandlerCmd90pr32();
            break;
         case 1:
            HandlerCmd90mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 91:
         switch( mode.pr ) {
         case 0:
            HandlerCmd91pr32();
            break;
         case 1:
            HandlerCmd91mo3a();
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 92:
         switch( mode.pr ) {
         case 0:
            HandlerCmd92pr32( inpack0.a_params[0] );
            break;
         case 1:
            HandlerCmd92mo3a( inpack0.a_params[0] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 93:
         switch( mode.pr ) {
         case 0:
            HandlerCmd93pr32( inpack0.a_params[0], inpack0.a_params[1],
               inpack0.a_params[2], inpack0.a_params[3], inpack0.a_params[4] );
            break;
         case 1:
            HandlerCmd93mo3a( inpack0.a_params[0], inpack0.a_params[1],
               inpack0.a_params[2], inpack0.a_params[3] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 94:
         switch( mode.pr ) {
         case 0:
            HandlerCmd94pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd94mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 95:
         switch( mode.pr ) {
         case 0:
            HandlerCmd95pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd95mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 96:
         switch( mode.pr ) {
         case 0:
            HandlerCmd96pr32( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         case 1:
            HandlerCmd96mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 97:
      case 98:
      case 99:
      case 100:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      case 101:
         switch( mode.pr ) {
         case 1:
            HandlerCmd101mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 102:
         switch( mode.pr ) {
         case 1:
            HandlerCmd102mo3a( inpack0.a_params[0], inpack0.a_params[1] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 103:
         switch( mode.pr ) {
         case 1:
            HandlerCmd103mo3a( inpack0.a_params[0], inpack0.a_params[1], 
               inpack0.a_params[2], inpack0.a_params[3] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      case 104:
         switch( mode.pr ) {
         case 1:
            HandlerCmd104mo3a( inpack0.a_params[0], inpack0.a_params[1], 
               inpack0.a_params[2] );
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;
      default:
         outpack0.kzv = 1;
         outpack0.cr_com++;
         break;
      }
   }

   SendOutPack1();
   SendOutPack2();
   SendOutPack3();
   SendOutPack4();
   SendOutPack5();
   SendOutPack6();

}

int SendOutPack0( void ) 
{
   static unsigned char cr_com = 0;
   static short krk = 0;
   static short link = 0;
   static unsigned char count = 0;
   unsigned int p;
   unsigned int i;
   struct header0 *h;
   unsigned int j;
   unsigned int n;

   if( sizeof(outpack0) % PART0_SIZE ) {
      p = sizeof(outpack0) / PART0_SIZE + 1;
   } else {
      p = sizeof(outpack0) / PART0_SIZE;
   }
   if( outbuf0.nsave + p > BUFFER2_MAX ) {
      return( -1 );
   }
   for( i = 1; i < p + 1 ; i++ ) {
      j = outbuf0.nsave;
      h = (struct header0 *)outbuf0.buf[j].data;
      memset( (char *)h, 0, sizeof(struct header0) );
      if( p == 1 ) {
         h->type = 70;
      } else {
         h->type = 71;
      }
      h->npack = count;
      h->npart = i;
      h->allpart = p;
      if( i < p ) {
         n = PART0_SIZE;
      } else {
         n = sizeof(outpack0) - ( p - 1 ) * PART0_SIZE;
      }
      memcpy( (char *)outbuf0.buf[j].data + sizeof(struct header0), 
         (char *)&outpack0 + ( i - 1 ) * PART0_SIZE, n );
      outbuf0.buf[j].size = sizeof(struct header0) + n;
      outbuf0.nsave ++;
   }

   if( ( outpack0.cr_com != cr_com ) || ( outpack0.krk != krk ) || 
         ( outpack0.link != link ) ) {
      cr_com = outpack0.cr_com;
      krk = outpack0.krk;
      link = outpack0.link;
      if( verbose > 0 ) {
         printf( "c_c=%u n_c=%d l_p=0x%x kzv=0x%x k_o=0x%x e_l=%d krk=0x%x link=0x%x\n",
            outpack0.cr_com, outpack0.num_com, outpack0.lp2_param, 
            outpack0.kzv, outpack0.k_o, outpack0.ended_loop, outpack0.krk, outpack0.link );
      }
   }

   count++;
   return( p );
}

int GetKAR( float *p, float *k )
{
   float ku;
   float kug;

   ku = *p - *k;
   if( ku < 0 ) {
      ku += 2 * PI;
   }

   kug = ku * 180 / PI;

   if( verbose > 1 ) {
      printf( "GetKAR: p=%f k=%f kug=%f\n", p, k, kug );
   }

   if( ( kug >= 0 ) && ( kug < 30 ) ) {
      return( 1 );
   } else if( ( kug >= 30 ) && ( kug < 90 ) ) {
      return( 2 );
   } else if( ( kug >= 90 ) && ( kug < 150 ) ) {
      return( 3 );
   } else if( ( kug >= 150 ) && ( kug < 210 ) ) {
      return( 4 );
   } else if( ( kug >= 210 ) && ( kug < 270 ) ) {
      return( 5 );
   } else if( ( kug >= 270 ) && ( kug < 330 ) ) {
      return( 6 );
   } else {
      return( 1 );
   }
}

