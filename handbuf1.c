#include <stdio.h>
#include <errno.h>
#include <sys/time.h>

#include "globals.h"
extern int verbose;

int inbuf1step = STEP_MARK;


int HandlerInBuf1( void )
{
   static int ip;
   static struct packet12 *pack;
   unsigned short n;

   if( verbose > 1 ) {
      printf( "HandlerInBuf1: save-load=%d.\n", inbuf1.save - inbuf1.load );
   }

   while( inbuf1.load != inbuf1.save ) {
      if( inbuf1step == STEP_NONE ) {
         inbuf1.save = inbuf1.load;
      }
//	printf("inbuf1step=%d\n",inbuf1step);

      if( inbuf1step == STEP_MARK ) {
         if( MarkInBuf1() ) {
            ip = inbuf1.load;
            pack = (struct packet12 *)&inbuf1.data[ip];
            inbuf1step = STEP_HEADER;
         }
      }
//	printf("inbuf1step=%d\n",inbuf1step);

      if( inbuf1step == STEP_HEADER ) {
         if( HeadInBuf1() ) {
			//printf("kss=%d rez13=%d \n",pack->head.kss,pack->head.rez13);
            if( pack->head.kss > 0 ) {
               inbuf1step = STEP_DATA;
               n = pack->head.kss;
               DataInBuf1( &n );
            } else {
               inbuf1step = STEP_HANDLER;
            }
         }
      }
//	printf("inbuf1step=%d\n",inbuf1step);

      if( inbuf1step == STEP_DATA ) {
		switch( DataInBuf1( NULL ) ) {
            case 1 : inbuf1step = STEP_HANDLER; break;
			case 2 : inbuf1step = STEP_MARK;
					 return 0;
         }
      }
//	printf("inbuf1step=%d\n",inbuf1step);

      if( inbuf1step == STEP_HANDLER ) {
         outpack1.blk &= ~BUF3KIT_BLK1;
         outpack2.blk &= ~BUF3KIT_BLK1;
         outpack3.blk &= ~BUF3KIT_BLK1;
         outpack4.blk &= ~BUF3KIT_BLK1;
         outpack5.blk &= ~BUF3KIT_BLK1;
         outpack6.blk &= ~BUF3KIT_BLK1;
 
         HandlerInPack1( pack , inbuf1.load - ip );
         if( outpack1.nload >= outpack1.nsave ) {
            outpack1.nsave = outpack1.nload = 0;
            stat.in |= FLAG_BUF1;
            CheckStatus();
            ControlLed1( 0 );
         }
         SendOutPack1();
		//	printf("SendOutPack\n");
         inbuf1step = STEP_MARK;
      }
//	printf("inbuf1step=%d\n",inbuf1step);

   }

   memset( (char *)inbuf1.data, 0, sizeof(inbuf1.data) );
   inbuf1.save = inbuf1.load = 0;

   return( inbuf1step );
}

int MarkInBuf1( void )
{
   unsigned char b;
   int i;
   static int nmark = 0;

   while( inbuf1.load < inbuf1.save ) {

      i = inbuf1.load;
      b = inbuf1.data[i];

      switch( nmark ) {
      case 0:
         if( b == 0xff ) {
            nmark = 1;
         }
         break;
      case 1:
         if( b == 0xff ) {
            nmark = 2;
         } else {
            nmark = 0;
         }
         break;
      case 2:
         if( b == 0xff ) {
            nmark = 3;
         } else {
            nmark = 0;
         }
         break;
      case 3:
         if( b == 0xff ) {
            nmark = 4;
         } else {
            nmark = 0;
         }
         break;
      default:
         nmark = 0;
         break;
      }
         
      inbuf1.load++;

      if( nmark >= 4 ) {
         inbuf1.load -= nmark;
         nmark = 0;
         return( 1 );
      }
   }

   return( 0 );
}

int HeadInBuf1( void )
{
   static unsigned int nhead = sizeof(struct header12);

   if( inbuf1.save - inbuf1.load >= nhead) {
      inbuf1.load += nhead;
      nhead = sizeof(struct header12);
      return( 1 );
   } else {
      inbuf1.load = inbuf1.save;
      nhead -= inbuf1.save - inbuf1.load; 
      return( 0 );
   }
}

int DataInBuf1( unsigned short *nd )
{
   static unsigned int ndata = 0;

   if( nd != NULL ) {
      ndata = *nd * 2;
      return( 0 );
   }

   if( inbuf1.save - inbuf1.load >= ndata) {
      inbuf1.load += ndata;
      ndata = 0;
      return( 1 );
   } else {
  	  //printf("ndata=%d s=%d l=%d\n",ndata,inbuf1.save,inbuf1.load);
      //ndata -= inbuf1.save - inbuf1.load; 
      inbuf1.load -= 32; //вернули назад голову
		memcpy(&inbuf1.data[0],&inbuf1.data[inbuf1.load],inbuf1.save-inbuf1.load);
		inbuf1.save-=inbuf1.load;
		inbuf1.load=0;
		//printf("ndata=%d s=%d l=%d\n",ndata,inbuf1.save,inbuf1.load);
      return( 2 ); //не полностью принят пакет
   }
}

int HandlerInPack1( struct packet12 *pack, int size )
{
   struct statkasrt *sk;
   struct sostrts *sr;
   struct errusoi *ko;
   struct form12 *f12;
   struct sac *fs;
   struct sac *f27;
   struct form199 *f199;
   unsigned fsa;
   unsigned fsp;
   unsigned fsr;
   unsigned fsv;
   unsigned fsn;
   int i;
   char b[sizeof(struct form199)];

   if( verbose > 0 ) {
      printf( "HandlerInPack1: size=%d kzo=%d kss=%d kvi=%d ps=%d\n",
         size, pack->head.kzo, pack->head.kss, pack->head.kvi, pack->head.ps );
      printf( "HandlerInPack1: wf= %04x %04x %04x %04x %04x %04x %04x\n",
         pack->wf[0], pack->wf[1], pack->wf[2], pack->wf[3], pack->wf[4],
         pack->wf[5], pack->wf[6] ); 
   }

   sk = (struct statkasrt *)&outpack0.word_sost_kasrt1_1;
   sr = (struct sostrts *)&outpack0.word_sost_rts_1;
   ko = (struct errusoi *)&outpack0.k_o;

   //********* (24.06.2011) *********

 //  if( pack->head.ps == 0 ) {
 //     outpack1.blk |= BUF3KIT_BLK1;
 //  }

   //*********************************

   if( size > sizeof(struct header12) ) {
      switch( pack->head.kvi ) {
      case 3:
         f12 = (struct form12 *)pack->wf;
         sk->s0got = f12->s0got;
         sk->s0prm = f12->s0prm;
         sk->s0prd = f12->s0prd;
         sk->s0cpp = f12->s0cpp;
         sk->s1fk = f12->s1tr;
         sk->s1fm = f12->s1m > 1 ? 1 : 0;
         sk->s1prm = f12->s1rp;
         sk->s1rab = f12->s1vr;
//         sk->s1rab = ~f12->s1vr; //???????????????????
         sk->s2prd = ( f12->s2prd ) & 0x7;
         sk->s2prm = ( f12->s2prm ) & 0xf;
         sk->rez1 = 0;
         sk->s3prd = ( f12->s3 ) & 0xf;
         sk->s4fk = ( f12->s4 ) & 0xf;
         sk->s5ss = f12->s5ss;
         sk->s5mi = f12->s5mi;
         sk->s5ib = f12->s5ib;
         sk->s5erib = f12->s5erib;
         sk->s6upr = f12->s6upr;
         sk->s6inf = f12->s6inf; //s6inf=1 - error write data for SVC 
         sk->s6prd = f12->kprd;
         sk->s7inf = f12->s7;
         sk->s8erib = ( f12->s8 ) & 0xff;
         sk->s9pream = ( f12->s9pr ) & 0xffff;
         sk->rez2 = 0;
//         sk->s9ss = ( f12->s9ss ) & 0xffff;
//         sk->s9mi = ( f12->s9mi ) & 0xffff;
         sr->svc1_rej = f12->s1tr;
         sr->svc1_m = f12->s1m > 1 ? 1 : 0;
         sr->svc1_rejprm = f12->s1rp;
         sr->svc1_rab = f12->s1vr;
         sr->svc1_prd = ( f12->s2prd ) & 0xf;
         sr->svc1_prm = ( f12->s2prm ) & 0xf;
         sr->svc1_oslprd = ( f12->s3 ) & 0xf;
         sr->svc1_fk = ( f12->s4 ) & 0xf;
         if( sk->s0cpp == 1 ) {
            outpack0.kzv = 1;
            ko->cpp1 = 1;
         }
			printf("prd=%d prm=%d 9pr=%d s1tr=%d s1m=%d s1rp=%d s1vr=%d \n",
	         sk->s2prd,sk->s2prm,sk->s9pream,sk->s1fk,sk->s1fm,sk->s1prm,sk->s1rab);
		printf("s6upr=%d sk->s6inf=%d sk->s6prd=%d \n",
         sk->s6upr, 
         sk->s6inf,  
         sk->s6prd);
			if ((mode.rli1) || (mode.scan1))
			{
				kzo7_1();	
				//stat.out|=FLAG_BUF1; //не надо т.к. вне команды
			}
         break;
      default:
         outpack0.link = KRK_DATA_OK; //всегда линк=6 при приходе данных (потом проверить на кви)
         fs = (struct sac *)pack->wf;
         fsa = fs->a0 + fs->a1 * 10 + fs->a2 * 100 + fs->a3 * 1000 + 
            fs->a4 * 10000 + fs->a5 * 100000;
         fsp = fs->p0 + fs->p1 * 10 + fs->p2 * 100 + fs->p3 * 1000 + 
            fs->p4 * 10000 + fs->p5 * 100000;
         fsr = fs->r0 + fs->r1 * 10 + fs->r2 * 100 + fs->r3 * 1000;
         fsv = fs->v0 + fs->v1 * 10 + fs->v2 * 100 + fs->v3 * 1000;
         fsn = *(short *)( (char *)fs + sizeof(struct sac) );
         if( verbose > 0 ) {
            printf( "SVCH1: SAC f=%d k=%d a=%d p=%d r=%d v=%d n=%d.\n", 
               fs->nf, fs->kvi, fsa, fsp, fsr, fsv, fsn );
            printf( "SVCH1: MODE scan=%d rli=%d addr=%d.\n",
               mode.scan1, mode.rli1, mode.addr1 );
         }
//         if( ( fsa != mode.addr1 ) || !mode.scan1 ) {
/*         if( fsa != mode.addr1 ) {
            if( verbose > 0 ) {
               printf( "SVCH1: Ignore packet.\n" );
            }
            break;
         }
*/
        if( fs->nf == 18 ) 
		{
            memcpy( &outpack0.svch1.sach18, fs, sizeof(struct sac) );
       	    outpack0.svch1.cr++;
            if( fsn > 4082 ) fsn = 4082;
			if ((mode.rli1)&&(fs->kvi==9)) //включен режим опросов РЛИ и пришел РЛИ
			{
				if (outpack0.svch1_rli.nword==0)  //первая строка
				{
					//outpack0.svch1.nword = fsn+1;//размер пакета + num ()
					outpack0.svch1_rli.nword = fsn; //пока без нума
				}
				else 
				{
					//скопировать потом еще последний form5
					outpack0.svch1_rli.nword += fsn-6; //добавляем только строки (подыгрыш) //было 21
					//outpack0.svch1.nword += fsn; //добавляем только строки (реальное РЛИ)
				}
	            memcpy( &outpack0.svch1_rli.form6[outpack0.svch1_rli.num*203],(char *)fs+sizeof(struct sac) + 14 , 406); //form6 //44
	            memcpy( &outpack0.svch1_rli.form5, (char *)fs+sizeof(struct sac) + 2 , 12); //form5

				for(i=0;i<10;i++) outpack0.svch1_rli.form1[i]=mode.cf1_svch1[i];
				for(i=0;i<5;i++)  outpack0.svch1_rli.form2[i]=mode.cf2_svch1[i];break;
				
//	            memcpy( &outpack0.svch1_rli.form6[outpack0.svch1_rli.num*203],(char *)fs, 406); //form6 //24
	            for (i=0;i<203;i++) printf(" %04x ",outpack0.svch1_rli.form6[outpack0.svch1_rli.num*203+i]);printf("\n");
	            printf(" %04x ",outpack0.svch1_rli.form6[outpack0.svch1_rli.num*203+1]>>7);printf("\n");

//	            for (i=0;i<203;i++) printf(" %04x ",*pack->wf+i);printf("\n");

				printf("nword=%d\n",outpack0.svch1_rli.nword);					
				printf("%d пакет. fsn=%d\n",outpack0.svch1_rli.num,fsn);
				outpack0.svch1_rli.num++;
			}
			else if (mode.scan1)
				switch (fs->kvi)
				{
					case 5 : 
						if ((fs->r0==1)&&(fs->r1==0)&&(fs->r2==0)&&(fs->r3==0)) //pervoe reg soobwenie
						{
							if (outpack0.svch1_no.nword==0)  //первая строка
								outpack0.svch1_no.nword = fsn; //
							else outpack0.svch1_no.nword += fsn-30; 
							memcpy( &outpack0.svch1_no.form3[mode.no_num*11],(char *)fs+sizeof(struct sac) + 32 , 22); //form6 //44	
						}
						else 
						{
							if (outpack0.svch1_no.nword==0)  //первая строка
								outpack0.svch1_no.nword = fsn; //
							else outpack0.svch1_no.nword += fsn-20; 
							memcpy( &outpack0.svch1_no.form3[mode.no_num*11],(char *)fs+sizeof(struct sac) + 22 , 22); //form6 //44   
			            }
					
						for(i=0;i<10;i++) outpack0.svch1_no.form1[i]=mode.cf1_svch1[i];
					
						if (fs->kvi==5) for(i=0;i<5;i++)  outpack0.svch1_no.form2[i]=mode.cf2_svch1[i];break;
	
			            for (i=0;i<11;i++) printf(" %04x ",outpack0.svch1_no.form3[mode.no_num*11+i]);printf("\n");
						mode.no_num++;
						printf("no_num=%d nword=%d tki kvi=5 recieve\n",mode.no_num,outpack0.svch1_rli.nword);					
						break;					
/*					case 6 :
						if ((fs->r0==1)&&(fs->r1==0)&&(fs->r2==0)&&(fs->r3==0)) //pervoe reg soobwenie
						{
							if (outpack0.svch1_no.nword==0)  //первая строка
								outpack0.svch1_rli.nword = fsn; //
							else outpack0.svch1_rli.nword += fsn-30; 
							memcpy( &outpack0.svch1_no.form3[mode.no_num*11],(char *)fs+sizeof(struct sac) + 32 , 22); //form6 //44	
						}
						else 
						{
							if (outpack0.svch1_no.nword==0)  //первая строка
								outpack0.svch1_rli.nword = fsn; //
							else outpack0.svch1_rli.nword += fsn-20; 
							memcpy( &outpack0.svch1_no.form3[mode.no_num*11],(char *)fs+sizeof(struct sac) + 22 , 22); //form6 //44   
			            }
					
						for(i=0;i<10;i++) outpack0.svch1_rli.form1[i]=mode.cf1_svch1[i];
					
			            for (i=0;i<11;i++) printf(" %04x ",outpack0.svch1_no.form3[mode.no_num*11+i]);printf("\n");
						mode.no_num++;
						printf("no_num=%d nword=%d tki recieve\n",mode.no_num,outpack0.svch1_rli.nword);					
						break;
*/
					case 7 : case 8 :
							if (outpack0.svch1_reo.nword==0)  //первая строка
								outpack0.svch1_reo.nword = fsn; //
							else outpack0.svch1_reo.nword += fsn-20; 
							memcpy( &outpack0.svch1_reo.form4[0],(char *)fs+sizeof(struct sac) + 22 , 72); //form6 //44   
//							memcpy( &outpack0.svch1_reo.form4[mode.no_num*12],(char *)fs+sizeof(struct sac) + 22 , 24); //form6 //44   

					
						for(i=0;i<10;i++) outpack0.svch1_reo.form1[i]=mode.cf1_svch1[i];
					
			            for (i=0;i<12;i++) printf(" %04x ",outpack0.svch1_reo.form4[mode.no_num*12+i]);printf("\n");
						mode.no_num++;
						printf("no_num=%d nword=%d tki kvi=7,8 recieve\n",mode.no_num,outpack0.svch1_rli.nword);					
						break;
				}
        }
        if( fs->nf == 27 ) {
            outpack0.link = KRK_LINK_OK;

            //if(( stat.link )||(stat.rli)) {
			if( stat.link ) {
               ResetBuffers1();
               HandlerCmdKasrt17();
               SendOutPack1();
               outpack0.cr_com++;
            }
        }
        if( fs->nf == 193 ) {
            /*f199 = (struct form199 *)b;
            memset( f199, 0, sizeof(struct form199) );
            memcpy( f199, fs, sizeof(struct form193) );
            f199->s.ps = 1;
            f199->s.vr = 0;
            f199->s.kvi = 2;
            f199->s.nf = 199;
            f199->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
            f199->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
            f199->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
            f199->s.r3 = ( count.out1 / 10000 ) / 1000;
            f199->s.v0 = 0;
            f199->s.v1 = 0;
            f199->s.v2 = 0;
            f199->s.v3 = 0;
            f199->s.a0 = fs->p0;
            f199->s.a1 = fs->p1;
            f199->s.a2 = fs->p2;
            f199->s.a3 = fs->p3;
            f199->s.a4 = fs->p4;
            f199->s.a5 = fs->p5;
            f199->s.p0 = fs->a0;
            f199->s.p1 = fs->a1;
            f199->s.p2 = fs->a2;
            f199->s.p3 = fs->a3;
            f199->s.p4 = fs->a4;
            f199->s.p5 = fs->a5;
            SendSVC1( f199, sizeof(struct form199) );
            count.out1++; */
        }
        if( fs->nf == 199 ) {
            f199 = (struct form199 *)fs;

            /*switch(f199->kfs) {
            case 34: case 39: outpack0.link = KRK_MODE_REO;  break;
            default: outpack0.link = KRK_CMD_OK; break;
            }*/
			
			for(i=0;i<10;i++) printf(" %x ",f199->cf1[i]);printf(" *199.1\n");
			for(i=0;i<5;i++)  printf(" %x ",f199->cf2[i]);printf(" *199.2\n");

//            memcpy( mode,cf1_svch1[0] , f199 +24, 20 );
  //          memcpy( mode,cf2_svch1[0] , f199 +44, 10 );

			for(i=0;i<10;i++) mode.cf1_svch1[i]=f199->cf1[i];
			for(i=0;i<5;i++)  mode.cf2_svch1[i]=f199->cf2[i];
			
            if( stat.link ) {
				//ResetBuffers1(); 
				//HandlerCmdKasrt17(); SendOutPack1();
				outpack1.nload = outpack1.nsave = outpack1.blk = 0;
				outpack0.cr_com++;
				mode.scan1=1;	//вкюлчение запросов ТКИ
				stat.link =0;
				printf("mode.scan1=1\n");
                outpack0.link = KRK_CMD_OK;
            }
            if( stat.rli ) {
                //ResetBuffers1();
				outpack1.nload = outpack1.nsave = outpack1.blk = 0;
				outpack0.cr_com++;				
				mode.rli1=1; //вкюлчение запросов РЛИ
				stat.rli=0;
				printf("mode.rli1=1\n");
				outpack0.link = KRK_MODE_REO;
            }

         }
         if( fs->nf == 203 ) {
            f199 = (struct form199 *)b;
            memset( f199, 0, sizeof(struct form199) );
            /*f199->s.ps = 1;
            f199->s.vr = 0;
            f199->s.kvi = 2;
            f199->s.nf = 199;
            f199->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
            f199->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
            f199->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
            f199->s.r3 = ( count.out1 / 10000 ) / 1000;
            f199->s.v0 = 0;
            f199->s.v1 = 0;
            f199->s.v2 = 0;
            f199->s.v3 = 0;
            f199->s.a0 = fs->p0;
            f199->s.a1 = fs->p1;
            f199->s.a2 = fs->p2;
            f199->s.a3 = fs->p3;
            f199->s.a4 = fs->p4;
            f199->s.a5 = fs->p5;
            f199->s.p0 = fs->a0;
            f199->s.p1 = fs->a1;
            f199->s.p2 = fs->a2;
            f199->s.p3 = fs->a3;
            f199->s.p4 = fs->a4;
            f199->s.p5 = fs->a5;
            f199->t1 = 0x00;
            f199->t2 = 0x1d;
            f199->kfs = 34;
            SendSVC1( f199, sizeof(struct form199) );
            count.out1++;*/
         }
         break;
      }
   }

   if( sr->svc1 || sr->svc2 || sr->dmv || sr->usoi ) {
      sr->rts = 1;
   } else {
      sr->rts = 0;
   }

   return( 0 );
}

int SendSVC1( const void *buf, unsigned len )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "SendSVC1: %d bytes.\n", len );
   }

//---------- Step-1 ----------

	kzo13_1();

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->npol = 1;
   h12->nspol = 1;  
   h12->kss = len / 2;
//   h12->kss = ( len / 2 ) & 0xf; //Temp!!!
 //  h12->kss2 = ( len / 2 ) >> 4; //Temp!!!
   h12->kvi = 2;
   h12->ps = 1;
   h12->kzo = 5;
   memcpy( outpack1.buf[i].data + sizeof(struct header12), buf, len );
   outpack1.buf[i].size = sizeof(struct header12) + len;
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();
//---------- Step 2 ----------

	kzo13_1();	

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
   f11->ku0 = 0; //RAB
   f11->ku1 = 1; //PRD-ON
   f11->ku2 = 0; //PRM-OFF
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->ku9z1 = 1; //ZAPROS-1
   f11->ku9z2 = 1; //ZAPROS-2
   f11->ku9z3 = 1; //ZAPROS-3
   f11->ku9z4 = 1; //ZAPROS-4
   f11->ku9z5 = 1; //ZAPROS-5
   f11->ku9z6 = 1; //ZAPROS-6
   f11->ku9z7 = 1; //ZAPROS-7
   f11->ku9z8 = 1; //ZAPROS-8
   f11->ku9z9 = 1; //ZAPROS-9
   f11->ku9z10 = 1; //ZAPROS-10
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

	BLKT(1);	BLKT(1);

//---------- Step 3 ----------

	kzo13_1();

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
   f11->ku0 = 0; //RAB
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->ku9z1 = 1; //ZAPROS-1
   f11->ku9z2 = 1; //ZAPROS-2
   f11->ku9z3 = 1; //ZAPROS-3
   f11->ku9z4 = 1; //ZAPROS-4
   f11->ku9z5 = 1; //ZAPROS-5
   f11->ku9z6 = 1; //ZAPROS-6
   f11->ku9z7 = 1; //ZAPROS-7
   f11->ku9z8 = 1; //ZAPROS-8
   f11->ku9z9 = 1; //ZAPROS-9
   f11->ku9z10 = 1; //ZAPROS-10
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();	

   SendOutPack1();

   return( 0 );
}

int SendOutPack1( void )
{
   int i;
   int j;
   struct header12 *h12; //!

   if( outpack1.nload >= outpack1.nsave ) {
      return( 0 );
   } else if( ! outpack1.blk ) {
      i = outpack1.nload;
      j = outbuf1.save;
      if( sizeof(outbuf1.data) - j < outpack1.buf[i].size ) {
         return( -1 );
      }
      memcpy( &outbuf1.data[j], outpack1.buf[i].data, outpack1.buf[i].size );
      outbuf1.save += outpack1.buf[i].size;
      outpack1.nload++;
      if( verbose > 1 ) {
			h12 = (struct header12 *)outpack1.buf[i].data;
			//SetHeader12( h12 );
	        printf( "SendOutPack1: size=%d cmd=%08x kvi=%d kzo=%d.\n", 
            outpack1.buf[i].size, outpack1.buf[i].cmd, h12->kvi, h12->kzo );
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK0 ) {
         outpack1.blk |= BUF3KIT_BLK0;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK1 ) {
         outpack1.blk |= BUF3KIT_BLK1;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK2 ) {
         outpack1.blk |= BUF3KIT_BLK2;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK3 ) {
         outpack1.blk |= BUF3KIT_BLK3;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK4 ) {
         outpack1.blk |= BUF3KIT_BLK4;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK5 ) {
         outpack1.blk |= BUF3KIT_BLK5;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLK6 ) {
         outpack1.blk |= BUF3KIT_BLK6;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_BLKT ) {
         outpack1.blk |= BUF3KIT_BLKT;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT0 ) {
         SendOutPack0();
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT1 ) {
         SendOutPack1();
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT2 ) {
         SendOutPack2();
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT3 ) {
         SendOutPack3();
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT4 ) {
         SendOutPack4();
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT5 ) {
         SendOutPack5();
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack6();
      }
 
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_DEC ) {
         outpack1.nload -= outpack1.buf[i].param;
      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_KRK ) {
//         outpack0.krk = outpack1.buf[i].param;
         outpack0.link = outpack1.buf[i].param;

      }
      if( outpack1.buf[i].cmd & BUF3KIT_CMD_END ) {
         outpack1.nsave = outpack1.nload = 0;
         stat.in |= FLAG_BUF1;
         CheckStatus();
         ControlLed1( 0 );
      }
      return( outpack1.buf[i].size ); 
   }

   return( 0 );
}

