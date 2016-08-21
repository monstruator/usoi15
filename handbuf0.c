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
   struct header12 *h12;
   struct form11 *f11;

	int i;

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

		if ((mode.rli2)||(mode.scan2))
		{
			//otklu4enie priema
			printf("\nPRM2-OFF\n");
		   i = outpack2.nsave;
		   h12 = (struct header12 *)outpack2.buf[i].data;
		   SetHeader12( h12 );
		   h12->npol = 1;
		   h12->nspol = 1;  
		   h12->kss = sizeof(struct form11) / 2;
		   h12->kvi = 1;
		   h12->ps = 1;
		   h12->kzo = 5;
		   f11 = (struct form11 *)(outpack2.buf[i].data + sizeof(struct header12));
		   memcpy( (char *)f11, (char *)&form11k2, sizeof(struct form11) );
		   f11->ku9z0 = 1;
		   f11->ku9z1 = 1;
		   f11->ku9z2 = 1;
		   f11->ku9z3 = 1;
		   f11->ku9z4 = 1;
		   f11->ku9z5 = 1;
		   f11->ku9z6 = 1;
		   f11->ku9z7 = 1;
		   f11->ku9z8 = 1;
		   f11->ku9z9 = 1;
		   f11->ku1=0;
		   f11->ku2=0;
		   f11->ku9z10 = 1;
		//   f11->ku10 = 1;
		   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
		   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
		   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
		   outpack2.nsave++;
		   SendOutPack2();
		}

		if ((mode.rli1)||(mode.scan1))
		{
			printf("\nPRM1-OFF\n");
			//otklu4enie priema
		   i = outpack1.nsave;
		   h12 = (struct header12 *)outpack1.buf[i].data;
		   SetHeader12( h12 );
		   h12->npol = 1;
		   h12->nspol = 1;  
		   h12->kss = sizeof(struct form11) / 2;
		   h12->kvi = 1;
		   h12->ps = 1;
		   h12->kzo = 5;
		   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
		   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
		   f11->ku9z0 = 1;
		   f11->ku9z1 = 1;
		   f11->ku9z2 = 1;
		   f11->ku9z3 = 1;
		   f11->ku9z4 = 1;
		   f11->ku9z5 = 1;
		   f11->ku9z6 = 1;
		   f11->ku9z7 = 1;
		   f11->ku9z8 = 1;
		   f11->ku9z9 = 1;
		   f11->ku1=0;
		   f11->ku2=0;
		   f11->ku9z10 = 1;
		//   f11->ku10 = 1;
		   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
		   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
		   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
		   outpack1.nsave++;
		   SendOutPack1();
		}

	  stat.link=mode.scan1=mode.scan2=0; //отключение сканирование с приходом новой команды	
	  mode.rli1=mode.rli2=0; //отключение сканирование с приходом новой команды	
	  mode.n_rli1=mode.n_rli2=0;	
	  mode.n_scan1=mode.n_scan2=0;	
	  mode.scan_p1=mode.scan_p2=0;	


	  memset(&outpack0.svch1,0,sizeof(outpack0.svch1));	
	  memset(&outpack0.svch2,0,sizeof(outpack0.svch2));	

		
//      ResetBuffers();
      ControlLed5( 0 );

      switch( outpack0.num_com ) {
      case 0:
         outpack0.cr_com++;
         break;
      case 1:
         switch( mode.pr ) {
         case 0:
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
      case 10:
         switch( mode.pr ) {
         case 0:
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
         switch( mode.pr ) {
         case 1:
            HandlerCmd97mo3a( inpack0.a_params[0], inpack0.a_params[1], inpack0.a_params[2]);
            break;
         default:
            outpack0.kzv = 1;
            outpack0.cr_com++;
            break;
         }
         break;

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
            HandlerCmd102mo3a( inpack0.a_params[0], inpack0.a_params[1], inpack0.a_params[2]);
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
	  case 115:
         switch( mode.pr ) {
         case 1:
            HandlerCmd115mo3a( inpack0.a_params[0], inpack0.a_params[1], 
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
   unsigned int i,i1;
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
	
	if (mode.rli1)
	{
	   printf("word=%d num=%d rli1\n",outpack0.svch1_rli.nword,outpack0.svch1_rli.num);
	   outpack0.svch1_rli.nword=outpack0.svch1_rli.num=0;
	}
	if (mode.scan1)
	{
	   printf("word=%d no_num=%d \n",outpack0.svch1_no.nword,mode.no_num1);
//	   outpack0.svch1_no.nword=0;
	}
	if (mode.rli2)
	{
	   printf("word=%d num=%d rli2\n",outpack0.svch2_rli.nword,outpack0.svch2_rli.num);
	   outpack0.svch2_rli.nword=outpack0.svch2_rli.num=0;
	}
	if (mode.scan2)
	{
	   printf("word=%d no_num=%d \n",outpack0.svch2_no.nword,mode.no_num2);
//	   outpack0.svch2_no.nword=0;
	}

   if (outpack0.svch1.cr!=0)
	{
	   printf("sach18.cr=%d nf=%x\n",outpack0.svch1.cr,outpack0.svch1.sach18[0]);
	   printf("sach18.nword=%d \n",outpack0.svch1.nword);
	   for(i1=0;i1<outpack0.svch1.nword;i1++) printf("%04x ",outpack0.svch1.word[i1]);printf("\n");
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

