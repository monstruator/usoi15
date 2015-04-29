#include <stdio.h>
#include <errno.h>
#include <sys/time.h>
#include "globals.h"

extern int verbose;

int inbuf6step = STEP_MARK;

int HandlerInBuf6( void )
{
   static int ip;
   static struct packet56 *pack;
   unsigned short n;
   int i;

   if( verbose > 1 ) printf( "HandlerInBuf6: save=%d load=%d save-load=%d.\n", inbuf6.save, inbuf6.load, inbuf6.save - inbuf6.load );

   while( inbuf6.load != inbuf6.save ) {

      if( inbuf6step == STEP_NONE ) inbuf6.save = inbuf6.load;

      if( inbuf6step == STEP_MARK ) {
         if( MarkInBuf6() ) {
            ip = inbuf6.load;
            pack = (struct packet56 *)&inbuf6.data[ip];
            inbuf6step = STEP_HEADER;
         }
      }

      if( inbuf6step == STEP_HEADER ) {
         if( HeadInBuf6() ) {
            inbuf6step = STEP_DATA;
            switch( pack->head.code ) {
            case 0xE0: n = 1; break;
            case 0x90:
               i = inbuf6.load;
               n = inbuf6.data[i];
               if( n == 0 ) n = 256;
               n++;
               break;
            default: n = 0;
            }
            DataInBuf6( &n );
         }
      }

      if(( inbuf6step == STEP_DATA ) && ( DataInBuf6( NULL ) ) ) inbuf6step = STEP_HANDLER;

      if( inbuf6step == STEP_HANDLER ) {
         outpack1.blk &= ~BUF3KIT_BLK6;
         outpack2.blk &= ~BUF3KIT_BLK6;
         outpack3.blk &= ~BUF3KIT_BLK6;
         outpack4.blk &= ~BUF3KIT_BLK6;
         outpack5.blk &= ~BUF3KIT_BLK6;
         outpack6.blk &= ~BUF3KIT_BLK6;
         HandlerInPack6( pack , inbuf6.load - ip );
         if( outpack6.nload >= outpack6.nsave ) {
            outpack6.nsave = outpack6.nload = 0;
            stat.in |= FLAG_BUF6;
            ControlLed4( 0 );
            CheckStatus();
         }
         SendOutPack6();
         inbuf6step = STEP_MARK;
         if( inbuf6.save == inbuf6.load ) inbuf6.save = inbuf6.load = 0;
      }
   }

//   memset( (char *)inbuf6.data, 0, sizeof(inbuf6.data) );
//   inbuf6.save = inbuf6.load = 0;
   return( inbuf6step );
}

int MarkInBuf6( void )
{
   unsigned char b;
   int i;

   while( inbuf6.load < inbuf6.save ) {
      i = inbuf6.load;
      b = inbuf6.data[i];
      if( 1 ) return( 1 );
      inbuf6.load++;
   }
   return( 0 );
}

int HeadInBuf6( void )
{
   static unsigned int nhead = sizeof(struct header56);

   if( inbuf6.save - inbuf6.load >= nhead) {
      inbuf6.load += nhead;
      nhead = sizeof(struct header56);
      return( 1 );
   } else {
      inbuf6.load = inbuf6.save;
      nhead -= inbuf6.save - inbuf6.load; 
      return( 0 );
   }
}

int DataInBuf6( unsigned short *nd )
{
   static unsigned int ndata = 0;
   int r;

   if( nd != NULL ) {
      ndata = *nd;
      r = 0;
   } else {
      if( inbuf6.save - inbuf6.load >= ndata) {
         inbuf6.load += ndata;
         ndata = 0;
         r = 1;
      } else {
         ndata -= inbuf6.save - inbuf6.load; 
         inbuf6.load = inbuf6.save;
         r = 0;
      }
   }

   if( verbose > 1 ) printf( "DataInBuf6: ndata=%d rez=%d.\n", ndata, r );
   return( r );
}

int HandlerInPack6( const void *buf, unsigned len )
{
   int i;
   struct packet56 *pack;
   struct sostrts *srts;
   struct errusoi *ko;
   unsigned n;
   struct sac *s;
   struct sac *f27;
   struct form199_dmv *f199;
   unsigned sa;
   unsigned sp;
   unsigned sr;
   unsigned sv;
   unsigned sn;
   char b[sizeof(struct form199_dmv)];

   if( verbose > 0 ) {
      printf( "HandlerInPack6(%d):", len );
      for( i = 0; i < len; i++ ) printf( " %02x", *( (char *)buf + i ) );
      printf( "\n" ); 
   }

   pack = (struct packet56 *)buf;
   srts = (struct sostrts *)&outpack0.word_sost_rts_1;
   ko = (struct errusoi *)&outpack0.k_o;

   switch( pack->head.code ) {
   case 0x41:
      if( verbose > 0 ) printf( "R999: Output abort (41)!\n" );
      break;
   case 0x90:
      outpack0.link = KRK_DATA_OK;
      n = pack->data[0];
      if( n == 0 ) n = 256;
      s = (struct sac *)&pack->data[1];
      sa = s->a0 + s->a1 * 10 + s->a2 * 100 + s->a3 * 1000 + s->a4 * 10000 + 
         s->a5 * 100000;
      sp = s->p0 + s->p1 * 10 + s->p2 * 100 + s->p3 * 1000 + s->p4 * 10000 + 
         s->p5 * 100000;
      sr = s->r0 + s->r1 * 10 + s->r2 * 100 + s->r3 * 1000;
      sv = s->v0 + s->v1 * 10 + s->v2 * 100 + s->v3 * 1000;
      sn = *(short *)( (char *)s + sizeof(struct sac) );
      if( verbose > 0 ) {
		 printf("sa=%d\n",sa);
         printf( "R999(%d): SAC f=%d k=%d a=%d p=%d r=%d v=%d n=%d.\n",  n, s->nf, s->kvi, sa, sp, sr, sv, sn );
         printf( "R999: MODE recv=%d addr=%d sa=%d .\n",  mode.recv3, mode.addr3, sa );
      }
		//бортовой номер
	    mode.a0 = s->p0;		mode.a1 = s->p1;
		mode.a2 = s->p2;		mode.a3 = s->p3;
		mode.a4 = s->p4;		mode.a5 = s->p5;
		mode.p0 = s->a0;		mode.p1 = s->a1;
		mode.p2 = s->a2;		mode.p3 = s->a3;
		mode.p4 = s->a4;		mode.p5 = s->a5;
		
      if( ( sa != mode.addr3 ) || !mode.recv3 ) { if( verbose > 0 ) printf( "R999: Ignore packet.\n" );  break;  }
      if( s->nf == 18 ) {
         if( s->kvi == 10 ) {
            memcpy( &outpack0.r999_cu2.sach18, s, sizeof(short) );
            if( sn > 3 ) sn = 3;
            outpack0.r999_cu2.nform = sn;
			printf("nform=%d to Danya\n",sn);
            for( i = 0; i < sn; i++ ) {
               memcpy( &outpack0.r999_cu2.form[i], (char *)s + 
                  sizeof(struct sac) + sizeof(short) + 
                  sizeof(struct formrls) * i, sizeof(struct formrls) );
            }
            outpack0.r999.cr++;
			if( !mode.mo1a && mode.mn1 ) outpack0.link = KRK_DATA_AND_TRANS;
			else
			{
				f27 = (struct sac *)b;
				memset( f27, 0, sizeof(struct sac) );
				f27->ps = 1;
				f27->vr = 0;
				f27->kvi = 2;
				f27->nf = 27;
				f27->r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
				f27->r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
				f27->r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
				f27->r3 = ( count.out6 / 10000 ) / 1000;
				f27->v0 = f27->v1 = f27->v2 = f27->v3 = 0;
				f27->a0 = s->p0;//бортовой номер
				f27->a1 = s->p1;
				f27->a2 = s->p2;
				f27->a3 = s->p3;
				f27->a4 = s->p4;
				f27->a5 = s->p5;
				f27->p0 = s->a0;
				f27->p1 = s->a1;
				f27->p2 = s->a2;
				f27->p3 = s->a3;
				f27->p4 = s->a4;
				f27->p5 = s->a5;
				WriteC2( f27, sizeof(struct sac) );
				count.out6++;
			}
         } else {
            memcpy( &outpack0.r999.sach18, s, sizeof(struct sac) );
//            if( sn > 121 ) sn = 121;
            if( sn > 103 ) sn = 103;
            outpack0.r999.nword = sn;
            memcpy( outpack0.r999.word, (char *)s + 
               sizeof(struct sac) + sizeof(short), sn * 2 );
            outpack0.r999.cr++;
         }
         SendOutPack0();
         ControlLed5( 1 );
      }
      if( s->nf == 26 ) {
		if( !mode.mo1a && mode.mn1 ) outpack0.link = KRK_SWITCH_TRANS;
		else
		{
			outpack0.link = KRK_LINK_OK;
			f27 = (struct sac *)b;
			memset( f27, 0, sizeof(struct sac) );
			f27->ps = 1;
			f27->vr = 0;
			f27->kvi = 2;
			f27->nf = 27;
			f27->r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
			f27->r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
			f27->r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
			f27->r3 = ( count.out6 / 10000 ) / 1000;
			f27->v0 = f27->v1 = f27->v2 = f27->v3 = 0;
			f27->a0 = s->p0;
			f27->a1 = s->p1;
			f27->a2 = s->p2;
			f27->a3 = s->p3;
			f27->a4 = s->p4;
			f27->a5 = s->p5;
			f27->p0 = s->a0;
			f27->p1 = s->a1;
			f27->p2 = s->a2;
			f27->p3 = s->a3;
			f27->p4 = s->a4;
			f27->p5 = s->a5;
			WriteC2( f27, sizeof(struct sac) );
			count.out6++;
		}
      }
      if( s->nf == 27 ) {
         outpack0.link = KRK_LINK_OK;
         if( stat.link ) {
            ResetBuffers();
            outpack0.cr_com++;
         }
      }
      if( s->nf == 193 ) {
         f199 = (struct form199_dmv *)b;
         memset( f199, 0, sizeof(struct form199_dmv) );
         memcpy( f199, s, sizeof(struct form193) );
         f199->s.ps = 1;
         f199->s.vr = 0;
         f199->s.kvi = 2;
         f199->s.nf = 199;
         f199->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
         f199->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
         f199->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
         f199->s.r3 = ( count.out6 / 10000 ) / 1000;
         f199->s.v0 = f199->s.v1 = f199->s.v2 = f199->s.v3 = 0;
         f199->s.a0 = s->p0;
         f199->s.a1 = s->p1;
         f199->s.a2 = s->p2;
         f199->s.a3 = s->p3;
         f199->s.a4 = s->p4;
         f199->s.a5 = s->p5;
         f199->s.p0 = s->a0;
         f199->s.p1 = s->a1;
         f199->s.p2 = s->a2;
         f199->s.p3 = s->a3;
         f199->s.p4 = s->a4;
         f199->s.p5 = s->a5;
         WriteC2( f199, sizeof(struct form199_dmv) );
         count.out6++;
      }
      if( s->nf == 199 ) {
         f199 = (struct form199_dmv *)s;
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
            outpack0.cr_com++;
         }
      }
      if( s->nf == 203 ) {
         f199 = (struct form199_dmv *)b;
         memset( f199, 0, sizeof(struct form199_dmv) );
         f199->s.ps = 1;
         f199->s.vr = 0;
         f199->s.kvi = 2;
         f199->s.nf = 199;
         f199->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
         f199->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
         f199->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
         f199->s.r3 = ( count.out6 / 10000 ) / 1000;
         f199->s.v0 = f199->s.v1 = f199->s.v2 = f199->s.v3 = 0;
         f199->s.a0 = s->p0;
         f199->s.a1 = s->p1;
         f199->s.a2 = s->p2;
         f199->s.a3 = s->p3;
         f199->s.a4 = s->p4;
         f199->s.a5 = s->p5;
         f199->s.p0 = s->a0;
         f199->s.p1 = s->a1;
         f199->s.p2 = s->a2;
         f199->s.p3 = s->a3;
         f199->s.p4 = s->a4;
         f199->s.p5 = s->a5;
         f199->t1 = 0x00;
         f199->t2 = 0x1d;
         f199->kfs = 34;
         WriteC2( f199, sizeof(struct form199_dmv) );
         count.out6++;
      }
      break;
   case 0xf0:
      if( verbose > 0 ) {
         printf( "R999: Input flag (F0).\n" );
      }
      ReadStC2();
      break;
   case 0xf1:
      if( verbose > 0 ) {
         printf( "R999: Input overload (F1)!\n" );
      }
      ReadStC2();
      break;
   default:
      break;
   }

   if( srts->svc1 || srts->svc2 || srts->dmv || srts->usoi ) {
      srts->rts = 1;
   } else {
      srts->rts = 0;
   }

   return( 0 );
}

int ReadStC2( void )
{
   int i;

   i = outpack6.nsave;
   outpack6.buf[i].data[0] = 0x90;
   outpack6.buf[i].size = 1;
   outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
   outpack6.nsave++;

   SendOutPack6();

   return( 0 );
}

int WriteC2( const void *buf, unsigned len )
{
    int i,i1,col=4;
	struct packet56 *p56;
	 
	if( verbose > 0 ) printf( "WriteC2: %d bytes.\n", len );
	//if( !mode.mo1a && mode.mn1 ) col=4;
	for(i1=0;i1<col;i1++)
	{
		i = outpack6.nsave;
		outpack6.buf[i].size = 0;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
		outpack6.nsave++;
	}
   
	for(i1=0;i1<2;i1++)
	{
		i = outpack6.nsave;
		outpack6.buf[i].data[0] = 0xc0;
		outpack6.buf[i].data[1] = r999cfg.sp;
		outpack6.buf[i].size = 2;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
		outpack6.nsave++;

		i = outpack6.nsave;
		outpack6.buf[i].data[0] = 0xb0;
		outpack6.buf[i].data[1] = 0x00;
		outpack6.buf[i].data[2] = 0x30;
		outpack6.buf[i].size = 3;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
		outpack6.nsave++;

		i = outpack6.nsave;
		outpack6.buf[i].data[0] = 0x80;
		if( len + 4 >= 256 ) {
		outpack6.buf[i].data[1] = 0;
		len = 256 - 4;
		} else outpack6.buf[i].data[1] = len + 4;
   
		outpack6.buf[i].data[2] = 0xd5;
		outpack6.buf[i].data[3] = 0x00;
		outpack6.buf[i].data[4] = 0x30;
		outpack6.buf[i].data[5] = len;
		memcpy( &outpack6.buf[i].data[6], buf, len );
		outpack6.buf[i].size = len + 6;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
		outpack6.nsave++;

		i = outpack6.nsave;
		outpack6.buf[i].size = 0;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
		outpack6.nsave++;
		
		i = outpack6.nsave;
		outpack6.buf[i].data[0] = 0x40;
		outpack6.buf[i].size = 1;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
		outpack6.nsave++;
	}
	
	  i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
      outpack6.nsave++;

	  i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0xc0;
      p56->data[0] = r999cfg.sp;
      outpack6.buf[i].size = sizeof(struct header56) + 1;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0xb0;
      p56->data[0] = 0x00;
      p56->data[1] = 0x30;
      outpack6.buf[i].size = sizeof(struct header56) + 2;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

   SendOutPack6();
   return( 0 );
}

int SendOutPack6( void )
{
   int i,j,i1;

   if( outpack6.nload >= outpack6.nsave ) return( 0 );
   else if( ! outpack6.blk ) {
		i = outpack6.nload;
		j = outbuf6.save;
		if( sizeof(outbuf6.data) - j < outpack6.buf[i].size ) return( -1 );
    
      memcpy( &outbuf6.data[j], outpack6.buf[i].data, outpack6.buf[i].size );
      outbuf6.save += outpack6.buf[i].size;
      outpack6.nload++;
      if( verbose > 1 ) {
         printf( "SendOutPack6: size=%d cmd=%08x.\n", 
            outpack6.buf[i].size, outpack6.buf[i].cmd );
		for(i1=0;i1<outpack6.buf[i].size;i1++) printf("%x ",outbuf6.data[j+i1]); printf("\n");
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK0 ) outpack6.blk |= BUF3KIT_BLK0;
      
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK1 ) outpack6.blk |= BUF3KIT_BLK1;
      
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK2 ) outpack6.blk |= BUF3KIT_BLK2;
     
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK3 ) outpack6.blk |= BUF3KIT_BLK3;
      
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK4 ) outpack6.blk |= BUF3KIT_BLK4;
      
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK5 ) {
         outpack6.blk |= BUF3KIT_BLK5;
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLK6 ) {
         outpack6.blk |= BUF3KIT_BLK6;
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_BLKT ) {
         outpack6.blk |= BUF3KIT_BLKT;
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT0 ) {
         SendOutPack0();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT1 ) {
         SendOutPack1();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT2 ) {
         SendOutPack2();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT3 ) {
         SendOutPack3();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT4 ) {
         SendOutPack4();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT5 ) {
         SendOutPack5();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_OUT6 ) {
         SendOutPack6();
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_DEC ) {
         outpack6.nload -= outpack6.buf[i].param;
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_KRK ) {
//         outpack0.krk = outpack6.buf[i].param;
         outpack0.link = outpack6.buf[i].param;
      }
      if( outpack6.buf[i].cmd & BUF3KIT_CMD_END ) {
         outpack6.nsave = outpack6.nload = 0;
         stat.in |= FLAG_BUF6;
         ControlLed4( 0 );
         CheckStatus();
      }
      return( outpack6.buf[i].size ); 
   }

   return( 0 );
}

