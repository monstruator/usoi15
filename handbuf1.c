
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

      if( inbuf1step == STEP_MARK ) {
         if( MarkInBuf1() ) {
            ip = inbuf1.load;
            pack = (struct packet12 *)&inbuf1.data[ip];
            inbuf1step = STEP_HEADER;
         }
      }

      if( inbuf1step == STEP_HEADER ) {
         if( HeadInBuf1() ) {
            if( pack->head.kss > 0 ) {
               inbuf1step = STEP_DATA;
               n = pack->head.kss;
               DataInBuf1( &n );
            } else {
               inbuf1step = STEP_HANDLER;
            }
         }
      }

      if( inbuf1step == STEP_DATA ) {
         if( DataInBuf1( NULL ) ) {
            inbuf1step = STEP_HANDLER;
         }
      }

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
         inbuf1step = STEP_MARK;
      }

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
      ndata -= inbuf1.save - inbuf1.load; 
      inbuf1.load = inbuf1.save;
      return( 0 );
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

   if( pack->head.ps == 0 ) {
      outpack1.blk |= BUF3KIT_BLK1;
   }

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
         break;
      default:
         outpack0.link = KRK_DATA_OK;
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
            printf( "SVCH1: MODE scan=%d addr=%d.\n",
               mode.scan1, mode.addr1 );
         }
         if( ( fsa != mode.addr1 ) || !mode.scan1 ) {
            if( verbose > 0 ) {
               printf( "SVCH1: Ignore packet.\n" );
            }
            break;
         }
         if( fs->nf == 18 ) {
            memcpy( &outpack0.svch1.sach18, fs, sizeof(struct sac) );
            if( fsn > 4082 ) fsn = 4082;
            outpack0.svch1.nword = fsn;
            memcpy( outpack0.svch1.word, (char *)fs + 
               sizeof(struct sac) + sizeof(short), fsn * 2 );
            outpack0.svch1.cr++;
            SendOutPack0();
            ControlLed5( 1 );
         }
         if( fs->nf == 26 ) {
            f27 = (struct sac *)b;
            memset( f27, 0, sizeof(struct sac) );
            f27->ps = 1;
            f27->vr = 0;
            f27->kvi = 2;
            f27->nf = 27;
            f27->r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
            f27->r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
            f27->r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
            f27->r3 = ( count.out1 / 10000 ) / 1000;
            f27->v0 = 0;
            f27->v1 = 0;
            f27->v2 = 0;
            f27->v3 = 0;
            f27->a0 = fs->p0;
            f27->a1 = fs->p1;
            f27->a2 = fs->p2;
            f27->a3 = fs->p3;
            f27->a4 = fs->p4;
            f27->a5 = fs->p5;
            f27->p0 = fs->a0;
            f27->p1 = fs->a1;
            f27->p2 = fs->a2;
            f27->p3 = fs->a3;
            f27->p4 = fs->a4;
            f27->p5 = fs->a5;
            SendSVC1( f27, sizeof(struct sac) );
            count.out1++;
         }
         if( fs->nf == 27 ) {
            outpack0.link = KRK_LINK_OK;
            if( stat.link ) {
               ResetBuffers();
               HandlerCmdKasrt17();
               SendOutPack1();
               outpack0.cr_com++;
            }
         }
         if( fs->nf == 193 ) {
            f199 = (struct form199 *)b;
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
            count.out1++;
         }
         if( fs->nf == 199 ) {
            f199 = (struct form199 *)fs;
            switch(f199->kfs) {
            case 34:
            case 39:
               outpack0.link = KRK_MODE_REO;
               break;
            default:
               outpack0.link = KRK_CMD_OK;
               break;
            }
            if( stat.link ) {
               ResetBuffers();
               HandlerCmdKasrt17();
               SendOutPack1();
               outpack0.cr_com++;
            }
         }
         if( fs->nf == 203 ) {
            f199 = (struct form199 *)b;
            memset( f199, 0, sizeof(struct form199) );
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
            f199->t1 = 0x00;
            f199->t2 = 0x1d;
            f199->kfs = 34;
            SendSVC1( f199, sizeof(struct form199) );
            count.out1++;
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

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 1;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 3;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->npol = 1;
   h12->nspol = 1;  
//   h12->kss = len / 2;
   h12->kss = ( len / 2 ) & 0xf; //Temp!!!
   h12->kss2 = ( len / 2 ) >> 4; //Temp!!!
   h12->kvi = 2;
   h12->ps = 1;
   h12->kzo = 5;
   memcpy( outpack1.buf[i].data + sizeof(struct header12), buf, len );
   outpack1.buf[i].size = sizeof(struct header12) + len;
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 7;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

//---------- Step 2 ----------

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 1;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 3;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

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

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 7;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   outpack1.buf[i].size = 0;
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLKT;
   outpack1.nsave++;

   i = outpack1.nsave;
   outpack1.buf[i].size = 0;
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLKT;
   outpack1.nsave++;

//---------- Step 3 ----------

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 1;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 3;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

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

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 7;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   SendOutPack1();

   return( 0 );
}

int SendOutPack1( void )
{
   int i;
   int j;

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
         printf( "SendOutPack1: size=%d cmd=%08x.\n", 
            outpack1.buf[i].size, outpack1.buf[i].cmd );
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

