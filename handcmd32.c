
#include <time.h>
#include "globals.h"

extern int verbose;

//*************** Handler Command 1 for Pribor 3.2 ***************

int HandlerCmd1pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   if( verbose > 0 ) {
      printf( "HandlerCmd1pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd1pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param ) {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku5 = 1; //PRD-M1
      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-OFF
      f11->ku9z0 = 1; //ZAPROS-0
   } else {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 0; //PRM-OFF
      f11->ku8 = 0; //FK-OFF
      f11->ku9z0 = 0; //ZAPROS-NONE
   }
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd1pr32) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   if( param ) {
      p34->data[1] = 0x08;
   } else {
      p34->data[1] = 0x00;
   }
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack5 (cmd1pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   if( param != 0 ) {
      p56->head.code = 0x11;
   } else {
      p56->head.code = 0x10;
   }
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   if( param != 0 ) {
      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x30;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;
   }

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 2 for Pribor 3.2 ***************

int HandlerCmd2pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   if( verbose > 0 ) {
      printf( "HandlerCmd2pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd2pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param ) {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku5 = 1; //PRD-M1
      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-OFF
      f11->ku9z0 = 1; //ZAPROS-0
   } else {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 0; //PRM-OFF
      f11->ku8 = 0; //FK-OFF
      f11->ku9z0 = 0; //ZAPROS-NONE
   }
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd2pr32) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   if( param ) {
      p34->data[1] = 0x08;
   } else {
      p34->data[1] = 0x00;
   }
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack5 (cmd2pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   if( param != 0 ) {
      p56->head.code = 0x11;
   } else {
      p56->head.code = 0x10;
   }
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   if( param != 0 ) {
      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x30;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;
   }

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 5 for Pribor 3.2 ***************

int HandlerCmd5pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd5pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd5pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( ( param >= 1 ) && ( param <= 6 ) ) {
      f11->ku5 = param; //PRD-M1...M6
      f11->ku9z0 = 1; //ZAPROS-0
   }
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 7 for Pribor 3.2 ***************

int HandlerCmd7pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd7pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd7pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( ( param >= 7 ) && ( param <= 12 ) ) {
      f11->ku6 = param; //PRM-M7...M12
      f11->ku9z0 = 1; //ZAPROS-0
   }
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 9 for Pribor 3.2 ***************

int HandlerCmd9pr32( int param0, int param1, int param2 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd9pr32: p0=%08x p1=%08x p2=%08x\n", 
         param0, param1, param2 );
   }

//---------- Outpack5 (cmd9pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = param1 & 0xff;
   p56->data[2] = ( param2 - 1 ) & 0x03;
   p56->data[2] |= 0x30;
   if( param0 ) {
      p56->data[3] = 0x60; //CTZ
   } else {
      p56->data[3] = 0x1c; //CT
   }
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[0] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = ( param1 >> 8 ) & 0xff;
   p56->data[2] = ( param2 - 1 ) & 0x03;
   p56->data[2] |= 0x30;
   if( param0 ) {
      p56->data[3] = 0x60; //CTZ
   } else {
      p56->data[3] = 0x1c; //CT
   }
   p56->data[3] |= 0x02;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
   r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
   r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
   r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
   r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
   r999cfg.sp =  p56->data[2] & 0x3;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 10 for Pribor 3.2 ***************

int HandlerCmd10pr32( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd10pr32: param0=%08x param1=%08x\n", param0, param1 );
   }

//---------- Outpack5 (cmd10pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x11;
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = ( param0 % 10 ) & 0x0f;
   p56->data[1] |= ( param0 / 10 ) << 4;
   p56->data[2] = ( param1 - 1 ) & 0x03;
   p56->data[2] |= 0x30;
   p56->data[3] = 0x00;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
   r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
   r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
   r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
   r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
   r999cfg.sp =  p56->data[2] & 0x3;
   r999cfg.can = p56->data[1];

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 11 for Pribor 3.2 ***************

int HandlerCmd11pr32( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd11pr32: param0=%08x param1=%08x\n", param0, param1 );
   }

//---------- Outpack5 (cmd11pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x11;
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = ( param1 % 10 ) & 0x0f;
   p56->data[1] |= ( param1 / 10 ) << 4;;
   p56->data[2] = ( param1 - 1 ) & 0x03;
   p56->data[2] |= 0x30;
   p56->data[3] = 0x22;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
   r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
   r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
   r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
   r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
   r999cfg.sp =  p56->data[2] & 0x3;
   r999cfg.can = p56->data[1];

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//******************** Handler Command 12 for Pribor 3.2 ********************

int HandlerCmd12pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd12pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd12pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param ) {
      f11->ku3 = 1; //RLI
   } else {
      f11->ku3 = 0; //TKI
   }
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 14 for Pribor 3.2 ***************

int HandlerCmd14pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd14pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd14pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param ) {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
   } else {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 0; //PRM-OFF
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 0; //ZAPROS-NONE
   }
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd14pr32) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   if( param ) {
      p34->data[1] = 0x08;
   } else {
      p34->data[1] = 0x00;
   }
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

   return( 0 );
}

//*************** Handler Command 18 for Pribor 3.2 ***************

int HandlerCmd18pr32( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd18pr32: param0=%08x param1=%08x\n", param0, param1 );
   }

//---------- Outpack6 (cmd18pr32) ----------

   if( param0 != 0 ) {
      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0xc0;
      p56->data[0] = ( param1 - 1 ) & 0x03;
      outpack6.buf[i].size = sizeof(struct header56) + 1;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      ControlLed4( 1 );
   } else {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

//*************** Handler Command 19 for Pribor 3.2 ***************

int HandlerCmd19pr32( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd19pr32: param0=%08x param1=%08x\n", param0, param1 );
   }

//---------- Outpack6 (cmd19pr32) ----------

   if( param0 != 0 ) {
      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0xc0;
      p56->data[0] = ( param1 - 1 ) & 0x03;
      outpack6.buf[i].size = sizeof(struct header56) + 1;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = 0; //256 byte
      for( j = 0; j < 256; j++ ) {
         p56->data[j+1] = 0x00;
      }
      outpack6.buf[i].size = sizeof(struct header56) + 257;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      ControlLed4( 1 );
   } else {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

//*************** Handler Command 20 for Pribor 3.2 ***************

int HandlerCmd20pr32( int param )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd20pr32: param=%08x\n", param );
   }

//---------- Outpack5 (cmd20pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] =  r999cfg.can;
   p56->data[2] = r999cfg.sp;
   p56->data[2] |= 0x30;
   if( param ) {
      p56->data[3] = 0x21;
   } else {
      p56->data[3] = 0x00;
   }
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
   r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
   r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
   r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
   r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
   r999cfg.sp =  p56->data[2] & 0x3;
   r999cfg.can = p56->data[1];

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 21 for Pribor 3.2 ***************

int HandlerCmd21pr32( int param )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd21pr32: param=%08x\n", param );
   }

//---------- Outpack5 (cmd21pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] =  r999cfg.can;
   p56->data[2] = r999cfg.sp;
   p56->data[2] |= 0x30;
   if( param ) {
      p56->data[3] = 0x24;
   } else {
      p56->data[3] = 0x00;
   }
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
   r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
   r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
   r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
   r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
   r999cfg.sp =  p56->data[2] & 0x3;
   r999cfg.can = p56->data[1];

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 30 for Pribor 3.2 ***************

int HandlerCmd30pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd30pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd30pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( ( param >= 0 ) && ( param <= 10 ) ) {
      f11->ku7 = param; //PRD-0..10dB
   }
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//************** Handler Command 31 for Pribor 3.2 ***************

int HandlerCmd31pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd31pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd31pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param > 0 ) {
      f11->ku11 = 1;
   } else {
      f11->ku11 = 0;
   }
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 32 for Pribor 3.2 ***************

int HandlerCmd32pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd32pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd32pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param > 0 ) {
      f11->ku12 = 1;
   } else {
      f11->ku12 = 0;
   }
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 33 for Pribor 3.2 ***************

int HandlerCmd33pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd33pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd33pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( param > 0 ) {
      f11->ku13 = 1;
   } else {
      f11->ku13 = 0;
   }
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 50 for Pribor 3.2 ***************

int HandlerCmd50pr32( void )
{
   int i;
   struct packet56 *p56;
   time_t t;
   struct tm *tm;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd50pr32: no param.\n" );
   }

//---------- Outpack5 (cmd50pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   t = time( NULL );
   tm = localtime( &t );
   p56->data[1] = ( tm->tm_min % 10 ) & 0xf ; //TIME-MIN
   p56->data[1] |= ( tm->tm_min / 10 ) << 4 ; //TIME-MIN
   p56->data[2] = ( tm->tm_hour % 10 ) & 0xf; //TIME-HOUR
   p56->data[2] |= ( tm->tm_hour / 10 ) << 4; //TIME-HOUR
   p56->data[3] = 0x36; //ZV
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 60 for Pribor 3.2 ***************

int HandlerCmd60pr32( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd60pr32: no param.\n" );
   }

//---------- Outpack1 (cmd60pr32) ----------

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
   h12->ps = 0;
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd60pr32) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   p34->data[1] = 0x08;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

   return( 0 );
}

//*************** Handler Command 61 for Pribor 3.2 ***************

int HandlerCmd61pr32( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd61pr32: no param.\n" );
   }

//---------- Outpack1 (cmd61pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 63 for Pribor 3.2 ***************

int HandlerCmd63pr32( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd63pr32: no param.\n" );
   }

//---------- Outpack1 (cmd63pr63) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   f11->ku0 = 1; //FK
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
   f11->ku5 = 1; //PRD-M1
   f11->ku6 = 7; //PRM-M7
   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//*************** Handler Command 64 for Pribor 3.2 ***************

int HandlerCmd64pr32( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd64pr32: no param.\n" );
   }

//---------- Outpack1 (cmd64pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   f11->ku0 = 1; //FK
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 1; //FK-1
   f11->ku9z0 = 1; //ZAPROS-0
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd64pr32) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   p34->data[1] = 0x08;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

   return( 0 );
}

//*************** Handler Command 65 for Pribor 3.2 ***************

int HandlerCmd65pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd65pr32: param=%08x\n", param );
   }

//---------- Outpack1 (cmd65pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
   if( ( param >= 2 ) && ( param <= 9 ) ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param; //FK-2...9
      f11->ku9z0 = 1; //ZAPROS-0
   } 
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd65pr32) ----------

   if( param == 2 ) {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( ( param >= 3 ) && ( param <= 9 ) ) {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x08;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   return( 0 );
}

//*************** Handler Command 80 for Pribor 3.2 ***************

int HandlerCmd80pr32( int param )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd80pr32: param=%08x\n", param );
   }

//---------- Outpack5 (cmd80pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0;
   switch( param ) {
   case 0:
      p56->data[2] = 0x00;
      p56->data[3] = 0x3a;
      break;
   case 1:
      p56->data[2] = 0x01;
      p56->data[3] = 0x3a;
      break;   
   case 2:
      p56->data[2] = 0x02;
      p56->data[3] = 0x3a;
      break;
   case 3:
      p56->data[2] = 0x03;
      p56->data[3] = 0x3a;
      break;
   case 4:
   case 5:
      p56->data[2] = 0x00;
      p56->data[3] = 0x32;
      break;
   case 6:
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      break;
   default:
      p56->data[2] = 0x00;
      p56->data[3] = 0x3a;
      break;
   }
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 82 for Pribor 3.2 ***************

int HandlerCmd82pr32( void )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd82pr32: no param.\n");
   }

//---------- Outpack5 (cmd82pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3c;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 83 for Pribor 3.2 ***************

int HandlerCmd83pr32( void )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd83pr32: no param.\n");
   }

//---------- Outpack5 (cmd83pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x01;
   p56->data[3] = 0x3c;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x01;
   p56->data[3] = 0x3a;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 90 for Pribor 3.2 *************** 

int HandlerCmd90pr32( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd90pr32: no param.\n");
   }

//---------- Outpack1 (cmd90pr32) ----------

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
   h12->ps = 0;
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd90pr32) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   p34->data[1] = 0x08;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

   return( 0 );
}

//*************** Handler Command 91 for Pribor 3.2 *************** 

int HandlerCmd91pr32( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd91pr32: no param.\n");
   }

//---------- Outpack1 (cmd91pr32) ----------

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
   h12->ps = 0;
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack5 (cmd91pr32) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x00;
   p56->data[3] = 0x3a;
   n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
      SumBit8( p56->data[3] );
   if( ! ( n % 2 ) ) {
      p56->data[3] |= 0x80;
   } 
   outpack5.buf[i].size = sizeof(struct header56) + 4;
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );

   return( 0 );
}

//*************** Handler Command 92 for Pribor 3.2 *************** 

int HandlerCmd92pr32( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet56 *p56;
   struct packet34 *p34;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd92pr32: param=%x\n", param );
   }

//---------- Outpack1 (cmd92pr32) ----------

   if( ( param == 1 ) || ( param == 3 ) || ( param == 5 ) || ( param == 9 ) ) {
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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      switch( param ) {
      case 1: //FK1-1
         f11->ku0 = 1; //FK
         f11->ku1 = 0; //PRD-OFF
         f11->ku2 = 1; //PRM-ON
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
         f11->ku5 = 1; //PRD-M1
         f11->ku6 = 7; //PRM-M7
         f11->ku7 = 0; //PRD-0dB
         f11->ku8 = 0; //FK-0
         f11->ku9z0 = 1; //ZAPROS-0
         break;
      case 3: //FK1-GH-1
         f11->ku0 = 1; //FK
         f11->ku1 = 0; //PRD-OFF
         f11->ku2 = 1; //PRM-ON
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
         f11->ku7 = 0; //PRD-0dB
         f11->ku8 = 1; //FK-1
         f11->ku9z0 = 1; //ZAPROS-0
         break;
      case 5: //FK2-1
         f11->ku0 = 0; //RAB
         f11->ku1 = 1; //PRD-ON
         f11->ku2 = 0; //PRM-OFF
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
         f11->ku7 = 0; //PRD-0dB
         f11->ku8 = 3; //FK-3
         f11->ku9z0 = 1; //ZAPROS-0
         f11->x1 = 1;
         f11->x0 = 0;
         break;
      case 9: //FK5-1
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
         break;
      }
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

      stat.out |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack3 (cmd92pr32) ----------

   if( param == 3 ) { //FK1-GH-1
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x08;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param == 5 ) { //FK2-1
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack5 (cmd92pr32) ----------

   if( param == 7 ) { //FK3
      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x40;
      p56->data[0] = 0x1f;
      p56->data[1] = 0x00;
      p56->data[2] = 0x00;
      p56->data[3] = 0x3c;
      n = SumBit8( p56->data[0] ) + SumBit8( p56->data[1] ) + SumBit8( p56->data[2] ) + 
         SumBit8( p56->data[3] );
      if( ! ( n % 2 ) ) {
         p56->data[3] |= 0x80;
      } 
      outpack5.buf[i].size = sizeof(struct header56) + 4;
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x40;
      p56->data[0] = 0x1f;
      p56->data[1] = 0x00;
      p56->data[2] = 0x00;
      p56->data[3] = 0x3a;
      outpack5.buf[i].size = sizeof(struct header56) + 4;
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      stat.out |= FLAG_BUF5;
      ControlLed4( 1 );
   }

//--------------- Other (cmd92pr32) ---------------

   if( param == 8 ) { //FK4
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   if( ( param == 1 ) || ( param == 3 ) ) {
      outpack0.ended_loop++;
   }

   return( 0 );
}

//*************** Handler Command 93 for Pribor 3.2 ***************

int HandlerCmd93pr32( int param0, int param1, int param2, int param3, int param4 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   unsigned char *f26; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd93pr32: p0=%x p1=%x p2=%x p3=%x p4=%x\n", 
         param0, param1, param2, param3, param4 );
   }

//---------- Outpack1 (cmd93pr32) ----------

   if( param0 == 0 ) { 

   //SVC1 - Step 1

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 2

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
      h12->kss = 16 / 2;
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f26 = (char *)(outpack1.buf[i].data + sizeof(struct header12));
      memset( f26, 0, 16 );
      outpack1.buf[i].size = sizeof(struct header12) + 16;
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

   //SVC1 - Step 3

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 4

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 2; //FK-2
      f11->ku9z0 = 1; //ZAPROS-0
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

      stat.out |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack3 (cmd93pr32) ----------

   if( param0 == 0 ) { //SVC1
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd93pr32) ----------

   if( param0 == 1 ) { //DMV
      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0xc0;
      p56->data[0] = ( param4 - 1 ) & 0x03;
      outpack6.buf[i].size = sizeof(struct header56) + 1;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = 0; //256 byte
      for( j = 0; j < 256; j++ ) {
         p56->data[j+1] = 0x00;
      }
      outpack6.buf[i].size = sizeof(struct header56) + 257;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      ControlLed4( 1 );

      outpack0.kzv = 3; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   }

//---------- Other ----------

   if( param0 > 1 ) {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

//*************** Handler Command 94 for Pribor 3.2 ***************

int HandlerCmd94pr32( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   unsigned char *f26; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd94pr32: param0=%x param1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd94pr32) ----------

   if( param0 == 0 ) { 

   //SVC1 - Step 1

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 2

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
      h12->kss = 16 / 2;
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f26 = (char *)(outpack1.buf[i].data + sizeof(struct header12));
      memset( f26, 0, 16 );
      outpack1.buf[i].size = sizeof(struct header12) + 16;
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

   //SVC1 - Step 3

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 4

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 2; //FK-2
      f11->ku9z0 = 1; //ZAPROS-0
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

      stat.out |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack3 (cmd94pr32) ----------

   if( param0 == 0 ) {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   } else {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

//*************** Handler Command 95 for Pribor 3.2 ***************

int HandlerCmd95pr32( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   unsigned char *f26; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   struct packet56 *p56;

   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd95pr32: param0=%x param1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd95pr32) ----------

   if( param0 == 0 ) { 

   //SVC1 - Step 1

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 2

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
      h12->kss = 16 / 2;
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f26 = (char *)(outpack1.buf[i].data + sizeof(struct header12));
      memset( f26, 0, 16 );
      outpack1.buf[i].size = sizeof(struct header12) + 16;
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

   //SVC1 - Step 3

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 4

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 2; //FK-2
      f11->ku9z0 = 1; //ZAPROS-0
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

      stat.out |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack3 (cmd95pr32) ----------

   if( param0 == 0 ) {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   } else {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

//*************** Handler Command 96 for Pribor 3.2 ***************

int HandlerCmd96pr32( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   unsigned char *f26; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd96pr32: param0=%x param1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd96pr32) ----------

   if( param0 == 0 ) { 

   //SVC1 - Step 1

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 2

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
      h12->kss = 16 / 2;
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f26 = (char *)(outpack1.buf[i].data + sizeof(struct header12));
      memset( f26, 0, 16 );
      outpack1.buf[i].size = sizeof(struct header12) + 16;
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

   //SVC1 - Step 3

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-0
      f11->ku9z0 = 1; //ZAPROS-0
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

   //SVC1 - Step 4

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
      h12->ps = 0;
      h12->kzo = 5;
      f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 2; //FK-2
      f11->ku9z0 = 1; //ZAPROS-0
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

      stat.out |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack3 (cmd96pr32) ----------

   if( param0 == 0 ) {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   } else {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

