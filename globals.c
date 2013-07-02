
#include <stdlib.h>
#include <sys/time.h>

#define DEFINE_GLOBALS

#include "globals.h"
extern int verbose;

void InitGlobals( void )
{
   int i;

   memset( (char *)&stat, 0, sizeof(stat) );
   memset( (char *)&tout, 0, sizeof(tout) );
   memset( (char *)&mode, 0, sizeof(mode) );
   memset( (char *)&count, 0, sizeof(count) );

   memset( (char *)&inbuf0, 0, sizeof(inbuf0) );
   memset( (char *)&outbuf0, 0, sizeof(outbuf0) );

   memset( (char *)&inbuf1, 0, sizeof(inbuf1) );
   memset( (char *)&outbuf1, 0, sizeof(outbuf1) );

   memset( (char *)&inbuf2, 0, sizeof(inbuf2) );
   memset( (char *)&outbuf2, 0, sizeof(outbuf2) );

   memset( (char *)&inbuf3, 0, sizeof(inbuf3) );
   memset( (char *)&outbuf3, 0, sizeof(outbuf3) );

   memset( (char *)&inbuf4, 0, sizeof(inbuf4) );
   memset( (char *)&outbuf4, 0, sizeof(outbuf4) );

   memset( (char *)&inbuf5, 0, sizeof(inbuf5) );
   memset( (char *)&outbuf5, 0, sizeof(outbuf5) );

   memset( (char *)&inbuf6, 0, sizeof(inbuf6) );
   memset( (char *)&outbuf6, 0, sizeof(outbuf6) );

   memset( (char *)&inpack0, 0, sizeof(inpack0) );
   memset( (char *)&outpack0, 0, sizeof(outpack0) );
   memset( (char *)&outpack1, 0, sizeof(outpack1) );
   memset( (char *)&outpack2, 0, sizeof(outpack2) );
   memset( (char *)&outpack3, 0, sizeof(outpack3) );
   memset( (char *)&outpack4, 0, sizeof(outpack4) );
   memset( (char *)&outpack5, 0, sizeof(outpack5) );
   memset( (char *)&outpack6, 0, sizeof(outpack6) );

   tstart.itog = 0xffffffff;
   tstart.bu = 0xffffffff;

   SetForm11( &form11k1 );
   SetForm11( &form11k2 );

   SetForm26( &form26k1 );
   SetForm26( &form26k2 );
   SetForm26( &form26k3 );

   r999cfg.rrc = 0;
   r999cfg.ap = 0;
   r999cfg.pwr = 0;
   r999cfg.s1i = 0;
   r999cfg.sa = 0;
   r999cfg.sp = 0;
   r999cfg.can = 1;
}

int CheckStatus( void )
{
   if( verbose > 1 ) {
      printf( "CheckStatus: out=%08x in=%08x.\n", stat.out, stat.in );
   }

   if( ( stat.out != 0 ) && ( ( stat.in & stat.out ) == stat.out ) ) {
      if( verbose > 0 ) {
         printf( "Command %d complette.\n", outpack0.num_com );
      }
      outpack0.cr_com++;
      stat.out = stat.in = 0;
      if( stat.link ) {
         if( verbose > 0 ) {
            printf( "Link Error! _Chk_status\n" );
         }
//         outpack0.kzv = 1;
//         outpack0.krk = KRK_ERR;
         outpack0.link = KRK_LINK_ERR;
         stat.link = 0;
      }
      return( 1 );
   }

   return( 0 );
}

//******************** Functions service ********************

void SetHeader12( struct header12 *head )
{
   static unsigned char nsoob = 0;
   time_t t;

   memset( (char *)head, 0, sizeof(struct header12) );
   t = time( NULL );

   head->mark1[0] = 0xffff;
   head->mark1[1] = 0xffff;
   head->key[0] = 0;
   head->key[1] = 0;
   head->key[2] = 0;
   head->key[3] = 0;
   head->mark2[0] = 0xffff;
   head->mark2[1] = 0xffff;
   head->rez9 = 0;
   head->npol = 0; //Number KASRT (1,2)
   head->rez10 = 0;
   head->notp = 1;
   head->rez11 = 0;
   head->nspol = 0; //Number AK (1,2,3,4)
   head->nsotp = 6;
   head->nsoob = nsoob++;
   head->rez12 = 0;
   head->rez13 = 0xcd;
   head->kss = 0; //Size message (word)
   head->kss2 = 0; //Temp valume!!!
   head->kvi = 0; //Type mesage
   head->sk = 0;
   head->kg = 0;
   head->kpts = 0;
   head->ps = 0; //Flag finish
   head->kzo = 0; //Type header
   head->rez14 = 0;
   head->totpm = (unsigned short)(t & 0xffff);
   head->totps = (unsigned short)(t >> 16);
}

void ResetBuffers( void ) 
{
   stat.out = stat.in = stat.link = stat.flag = 0;
   tout.stat = tout.count = 0;
   outpack1.nsave = outpack1.nload = outpack1.blk = 0;
   outpack2.nsave = outpack2.nload = outpack2.blk = 0;
   outpack3.nsave = outpack3.nload = outpack3.blk = 0;
   outpack4.nsave = outpack4.nload = outpack4.blk = 0;
   outpack5.nsave = outpack5.nload = outpack5.blk = 0;
   outpack6.nsave = outpack6.nload = outpack6.blk = 0;
   outbuf1.save = outbuf1.load = 0;
   outbuf2.save = outbuf2.load = 0;
   outbuf3.save = outbuf3.load = 0;
   outbuf4.save = outbuf4.load = 0;
   outbuf5.save = outbuf5.load = 0;
   outbuf6.save = outbuf6.load = 0;
   ControlLed1( -1 );
   ControlLed2( -1 );
   ControlLed3( -1 );
   ControlLed4( -1 );
   ControlLed5( -1 );
}

void SetForm11( struct form11 *form )
{
   memset( (char *)form, 0, sizeof(struct form11) );

   form->rez1 = 0;
   form->kdv = 1;
   form->ku7 = 0;
   form->x0 = 0;
   form->x1 = 0;
   form->rez2 = 0;
   form->ku3 = 0;
   form->ku2 = 0;
   form->ku1 = 0;
   form->ku0 = 0;
   form->ku4 = 0;
   form->rez3 = 0x1fff;
   form->ku5 = 0;
   form->rez4 = 0;
   form->ku6 = 0;
   form->rez5 = 0xaaa;
   form->rez6 = 0;
   form->ku9z10 = 0;
   form->ku9z9 = 0;
   form->ku9z8 = 0;
   form->ku9z7 = 0;
   form->ku9z6 = 0;
   form->ku9z5 = 0;
   form->ku9z4 = 0;
   form->ku9z3 = 0;
   form->ku9z2 = 0;
   form->ku9z1 = 0;
   form->ku9z0 = 0;
   form->rez7 = 0;
   form->ku13 = 0;
   form->ku12 = 0;
   form->ku11 = 0;
   form->ku10 = 0;
   form->ku8 = 0;
   form->rez8 = 0;
}

void SetForm26( struct sac *form )
{
   memset( (char *)form, 0, sizeof(struct sac) );

   form->ps = 0;
   form->vr = 0;
   form->rez1 = 0;
   form->kvi = 0;
   form->rez2 = 0;
   form->nf = 0;
   form->a0 = 0;
   form->a1 = 0;
   form->a2 = 0;
   form->a3 = 0;
   form->a4 = 0;
   form->a5 = 0;
   form->p0 = 0;
   form->p1 = 0;
   form->p2 = 0;
   form->p3 = 0;
   form->p4 = 0;
   form->p5 = 0;
   form->r0 = 0;
   form->r1 = 0;
   form->r2 = 0;
   form->r3 = 0;
   form->v0 = 0;
   form->v1 = 0;
   form->v2 = 0;
   form->v3 = 0;
}

int Sum2( unsigned char *buf, int len )
{
   int i;
   int sum = 0;

   for( i = 0; i < len; i++ ) {
      sum ^= *(buf + i);
   }

   return( sum );
}

int SumBit8( unsigned char data )
{
   int i;
   int sum = 0;

   for( i = 0; i < 8; i++ ) {
      if( data & ( 1 << i ) ) {
         sum++;
      }
   }

   return( sum );
}

