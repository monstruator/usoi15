#include <time.h>
#include "globals.h"

extern int verbose;

BLKT(int N_Chan)
{
	int i;
	switch(N_Chan)
	{
		case 1: i = outpack1.nsave;
			    outpack1.buf[i].size = 0;
			    outpack1.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack1.nsave++;
				break;
		case 2: i = outpack2.nsave;
			    outpack2.buf[i].size = 0;
			    outpack2.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack2.nsave++;
				break;
		case 3: i = outpack3.nsave;
			    outpack3.buf[i].size = 0;
			    outpack3.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack3.nsave++;
				break;
		case 4: i = outpack4.nsave;
			    outpack4.buf[i].size = 0;
			    outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack4.nsave++;
				break;
		case 5: i = outpack5.nsave;
			    outpack5.buf[i].size = 0;
			    outpack5.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack5.nsave++;
				break;
		case 6: i = outpack6.nsave;
			    outpack6.buf[i].size = 0;
			    outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack6.nsave++;
				break;
		case 7: i = outpack7.nsave;
			    outpack7.buf[i].size = 0;
			    outpack7.buf[i].cmd = BUF3KIT_CMD_BLKT;
			    outpack7.nsave++;
				break;

	}
}

kzo7_1()
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

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
}

kzo7_2()
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;
   i = outpack2.nsave;
   h12 = (struct header12 *)outpack2.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 7;
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;
}

kzo13_1()
{
   struct header12 *h12;

	int i;
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
}


kzo13_2()
{
   struct header12 *h12;

	int i;

   i = outpack2.nsave;
   h12 = (struct header12 *)outpack2.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 1;
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

   i = outpack2.nsave;
   h12 = (struct header12 *)outpack2.buf[i].data;
   SetHeader12( h12 );
   h12->kss = 0;
   h12->kvi = 0;
   h12->ps = 0;
   h12->kzo = 3;
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;
}

void BU1_K6( int kod ) //управление реле к6 в БУ1
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;	//К1-К6
   p34->data[0] = 0xff;
   p34->data[1] = kod;	//КОД ПРИ 1 
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;
}

void BU2_K6( int kod ) //управление реле к6 в БУ1
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;		//K1-K6
      p34->data[0] = 0xff;
      p34->data[1] = kod;			//КОД
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;
}

void BU1_K7( int kod ) //управление реле к6 в БУ1
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x74;	//k7
      p34->data[0] = 0xff;
	  p34->data[1] = kod;	//КОД 
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

}

void BU2_K7( int kod ) //управление реле к7 в БУ2
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
//      p34->head.code = 0x74; 	//К7
      p34->head.code = 0x73; 	//К7

      p34->data[0] = 0xff;
      p34->data[1] = kod;		//КОД
	  printf(" kod_bu2_k7=%x \n\n",kod);
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;
}

void BU3_K7( int kod ) //управление реле к7 в БУ2
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

      i = outpack7.nsave;
      p34 = (struct packet34 *)outpack7.buf[i].data;
      p34->head.pream = 0x3231;
//      p34->head.code = 0x74; 	//К7
      p34->head.code = 0x73; 	//К7

      p34->data[0] = 0xff;
      p34->data[1] = kod;		//КОД
		printf(" kod_bu3_k7=%x \n\n",kod);
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack7.buf[i].size = sizeof(struct header34) + 3;
      outpack7.buf[i].cmd = BUF3KIT_CMD_BLK7;
      outpack7.nsave++;
}

//******************** Handler Command 1 ********************

int HandlerCmd1mo3a( int param1 , int param2 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

	printf("com1 %d %d\n",param1,param2);

   if( verbose > 0 ) {
      printf( "HandlerCmd1mo3a: param1=%08x param2=%08x\n", param1, param2 );
   }

//---------- Outpack1 (cmd1) ----------// ЦПП КА
//5
	kzo13_1();

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->npol = 1;
   h12->nspol = 1;  
   h12->kss = sizeof(struct form11) / 2;
   h12->kvi = 1;
   h12->ps = 1;	//0
   h12->kzo = 5;
   f11 = (struct form11 *)(outpack1.buf[i].data + sizeof(struct header12));
   memcpy( (char *)f11, (char *)&form11k1, sizeof(struct form11) );
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
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd1) ----------//БУ-1
//3
	BU1_K6(1);
//2
	if (param2)	BU1_K7(0x01);
	
   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack4 (cmd1) ----------//БУ-2
//1
	if (param2==0)	//mo1ak
	{	
		BU2_K6(0x11); //0x11
		BU2_K7(0x01); //!!!   1
    	stat.out |= FLAG_BUF4;
    	ControlLed3( 1 );
	}
//---------- Outpack5 (cmd1) ----------//p-999
/*
   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   if( param1 ) {
      p56->head.code = 0x11;
   } else {
      p56->head.code = 0x10;
   }
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   if( param1 ) {
		BLKT(5);
		BLKT(5);

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x40;
      p56->data[0] = 0x1f;	//код в обратной последовательности 3-0
      p56->data[1] = 0x01;
      p56->data[2] = 0x00;
      p56->data[3] = 0x80;
      outpack5.buf[i].size = sizeof(struct header56) + 4;
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
      r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
      r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
      r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
      r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
      r999cfg.sp = p56->data[2] & 0x3;

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x30;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;
   }

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );
*/
//---------- Other (cmd1) ----------

   if( param1 ) {
      mode.mo1a = 1;
   } else {
      mode.mo1a = 0;
   }

   return( 0 );
}

//******************** Handler Command 2 ********************

int HandlerCmd2mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   if( verbose > 0 ) {
      printf( "HandlerCmd2mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd2) ----------

	kzo13_2();

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
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack3 (cmd2) ----------

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;
   p34->data[0] = 0xff;
   if( param ) {
      if( mode.mo1a ) {
         p34->data[1] = 0x15;
      } else {
         p34->data[1] = 0x1b;
      }
   } else {
      p34->data[1] = 0x00;
   }
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack4 (cmd2) ----------

   if( param && mode.mo1a ) {
		BU2_K6(0x11);
		//BU2_K7(0x02);
      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack5 (cmd2) ----------
/*
   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   if( param ) {
      p56->head.code = 0x11;
   } else {
      p56->head.code = 0x10;
   }
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   if( param ) {
		BLKT(5);
		BLKT(5);

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x40;
      p56->data[0] = 0x1f;
      p56->data[1] = 0x01;
      p56->data[2] = 0x00;
      p56->data[3] = 0x80;
      outpack5.buf[i].size = sizeof(struct header56) + 4;
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
      r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
      r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
      r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
      r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
      r999cfg.sp = p56->data[2] & 0x3;

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x30;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;
   }

   stat.out |= FLAG_BUF5;
   ControlLed4( 1 );
*/
//---------- Other (cmd1) ----------

   if( param ) {
      mode.mn1 = 1;
   } else {
      mode.mn1 = 0;
   }

   return( 0 );
}

//******************** Handler Command 3 ********************

int HandlerCmd3mo3a( int param )
{
   int i;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd3mo3a: param=%08x\n", param );
   }

//---------- Outpack4 (cmd3) ----------
	   switch( param ) {
	   case 1:      i=0x02;      break;
	   case 2:      i=0x04;      break;
	   case 3:      i=0x08;      break;
	   case 4:      i=0x10;      break;
	   case 5:      i=0x20;      break;
	   case 6:      i=0x40;      break;
	   default:     i=0x01;      break;
	   }

//		BU2_K7(i);
		BU2_K7(param);

   stat.out |= FLAG_BUF4;
   ControlLed3( 1 );

   return( 0 );
}


//******************** Handler Command 4 ********************
int HandlerCmd4mo3a( int param1 , int param2 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

	printf("com4 %d %d\n",param1,param2);

   if( verbose > 0 ) {
      printf( "HandlerCmd4mo3a: param1=%08x param2=%08x\n", param1, param2 );
   }

//---------- Outpack3 (cmd4) ----------//БУ-1
	switch(param2)
	{
		case 0 : BU1_K6(0x01); BU1_K7(0x00); break;
		case 1 : BU1_K6(0x0B); BU1_K7(0x00); break;
		case 2 : BU1_K6(0x03); BU1_K7(0x00); break;
		case 3 : BU1_K6(0x2B); BU1_K7(0x00); break;
	}
	
   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack4 (cmd4) ----------//БУ-2
//0.1 
	if (param2==0)	
	{
		BU2_K6(0x11);  //mo1ak

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
	}	
//---------- Outpack5 (cmd4) ----------//p-999

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   if( param1 ) {
      p56->head.code = 0x11;
   } else {
      p56->head.code = 0x10;
   }
   outpack5.buf[i].size = sizeof(struct header56);
   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
   outpack5.nsave++;

   if( param1 ) {
		BLKT(5);
		BLKT(5);

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x40;
      p56->data[0] = 0x1f;	//код в обратной последовательности 3-0
      p56->data[1] = 0x01;
      p56->data[2] = 0x00;
      p56->data[3] = 0x80;
      outpack5.buf[i].size = sizeof(struct header56) + 4;
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      r999cfg.rrc = p56->data[2] & 0x80 ? 1 : 0;
      r999cfg.ap = p56->data[2] & 0x40 ? 1 : 0;
      r999cfg.pwr = ( p56->data[2] & 0x30 ) >> 4;
      r999cfg.s1i = p56->data[2] & 0x08 ? 1 : 0;
      r999cfg.sa = p56->data[2] & 0x04 ? 1 : 0;
      r999cfg.sp = p56->data[2] & 0x3;

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

//******************** Handler Command 5 ********************

int HandlerCmd5mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd5mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd5) ----------

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
//   if( ( param >= 1 ) && ( param <= 6 ) ) {
      f11->ku5 = param; //PRD-M1...M6
      f11->ku9z0 = 1; //ZAPROS-0
//   }
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 6 ********************

int HandlerCmd6mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd6mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd6) ----------

	kzo13_2();

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
//   if( ( param >= 1 ) && ( param <= 6 ) ) {
      f11->ku5 = param; //PRD-M1...M6
      f11->ku9z0 = 1; //ZAPROS-0
//   }
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 7 ********************

int HandlerCmd7mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd7mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd7) ----------

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
//   if( ( param >= 7 ) && ( param <= 12 ) ) {
//   if( ( param >= 1 ) && ( param <= 12 ) ) {
      f11->ku6 = param; //PRM-M7...M12
      f11->ku9z0 = 1; //ZAPROS-0
//   }
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 8 ********************

int HandlerCmd8mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd8mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd8) ----------

	kzo13_2();

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
//   if( ( param >= 7 ) && ( param <= 12 ) ) {
//   if( ( param >= 1 ) && ( param <= 12 ) ) {
      f11->ku6 = param; //PRM-M7...M12
      f11->ku9z0 = 1; //ZAPROS-0
//   }
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 9 ********************

int HandlerCmd9mo3a( int param0, int param1, int param2 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd9mo3a: p0=%08x p1=%08x p2=%08x\n", param0, param1, param2 );
   }

//---------- Outpack5 (cmd9) ----------

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

//******************** Handler Command 10 ********************

int HandlerCmd10mo3a( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd10mo3a: p0=%08x p1=%08x\n", param0, param1 );
   }

//---------- Outpack5 (cmd10) ----------

//   i = outpack5.nsave;
//   p56 = (struct packet56 *)outpack5.buf[i].data;
//   p56->head.code = 0x11;
//   outpack5.buf[i].size = sizeof(struct header56);
//   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
//   outpack5.nsave++;

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = ( param0 % 10 ) & 0x0f;
   p56->data[1] |= ( param0 / 10 ) << 4;;
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

//******************** Handler Command 11 ********************

int HandlerCmd11mo3a( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd11mo3a: p0=%08x p1=%08x\n", param0, param1 );
   }

//---------- Outpack5 (cmd11) ----------

//   i = outpack5.nsave;
//   p56 = (struct packet56 *)outpack5.buf[i].data;
//   p56->head.code = 0x11;
//   outpack5.buf[i].size = sizeof(struct header56);
//   outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
//   outpack5.nsave++;

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

//******************** Handler Command 12 ********************

int HandlerCmd12mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd12mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd12) ----------

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

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 13 ********************

int HandlerCmd13mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd13mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd13) ----------

	kzo13_2();

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
   if( param ) {
      f11->ku3 = 1; //RLI
   } else {
      f11->ku3 = 0; //TKI
   }
   f11->ku9z0 = 1; //ZAPROS-0
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 14 ********************

int HandlerCmd14mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd14mo3a: param=0x%08x\n", param );
   }

//---------- Outpack1 (cmd14) ----------

   ControlLed1( 1 );

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
   if( param ) {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku7 = 0; //PRD-0dB
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
   } else {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 0; //PRM-OFF
      f11->ku8 = 0; //FK-O
      f11->ku9z0 = 0; //ZAPROS-0-NONE
      f11->ku9z1 = 0; //ZAPROS-1-NONE
      f11->ku9z2 = 0; //ZAPROS-2-NONE
      f11->ku9z3 = 0; //ZAPROS-3-NONE
      f11->ku9z4 = 0; //ZAPROS-4-NONE
      f11->ku9z5 = 0; //ZAPROS-5-NONE
      f11->ku9z6 = 0; //ZAPROS-6-NONE
      f11->ku9z7 = 0; //ZAPROS-7-NONE
      f11->ku9z8 = 0; //ZAPROS-8-NONE
      f11->ku9z9 = 0; //ZAPROS-9-NONE
      f11->ku9z10 = 0; //ZAPROS-10-NONE
   }
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;

//---------- Outpack4 (cmd14) ----------

   if( param ) {
      ControlLed3( 1 );

		BU2_K6(11);
      stat.out |= FLAG_BUF4;
   }

//--------------- Other (Cmd14) ---------------

   if( param ) {
      mode.scan1 = 1;
   } else {
      mode.scan1 = 0;
   }

//   stat.cmd |= CMD_READ_KASRT1;

   return( 0 );
}

//******************** Handler Command 15 ********************

int HandlerCmd15mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd15mo3a: param=0x%08x\n", param );
   }

//---------- Outpack2 (cmd15) ----------

   ControlLed2( 1 );

	kzo13_2();

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
   if( param ) {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = 0; //FK-OFF
      f11->ku9z0 = 1; //ZAPROS-0
      f11->ku9z1 = 1; //ZAPROS-1
      f11->ku9z2 = 1; //ZAPROS-2
      f11->ku9z3 = 1; //ZAPROS-3
      f11->ku9z4 = 1; //ZAPROS-4
      f11->ku9z5 = 1; //ZAPROS-5
      f11->ku9z6 = 1; //ZAPROS-6
      f11->ku9z7 = 1; //ZAPROS-7
      f11->ku9z7 = 1; //ZAPROS-7
      f11->ku9z8 = 1; //ZAPROS-8
      f11->ku9z9 = 1; //ZAPROS-9
      f11->ku9z10 = 1; //ZAPROS-10
   } else {
      f11->ku0 = 0; //RAB
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 0; //PRM-OFF
      f11->ku8 = 0; //FK-OFF
      f11->ku9z0 = 0; //ZAPROS-0-NONE
      f11->ku9z1 = 0; //ZAPROS-1-NONE
      f11->ku9z2 = 0; //ZAPROS-2-NONE
      f11->ku9z3 = 0; //ZAPROS-3-NONE
      f11->ku9z4 = 0; //ZAPROS-4-NONE
      f11->ku9z5 = 0; //ZAPROS-5-NONE
      f11->ku9z6 = 0; //ZAPROS-6-NONE
      f11->ku9z7 = 0; //ZAPROS-7-NONE
      f11->ku9z8 = 0; //ZAPROS-8-NONE
      f11->ku9z9 = 0; //ZAPROS-9-NONE
      f11->ku9z10 = 0; //ZAPROS-10-NONE
   }
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;

//---------- Outpack3 (cmd15) ----------

   if( param ) {
      ControlLed3( 1 );

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x1b;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
   }

   //--------------- Other ---------------

   if( param ) {
      mode.scan2 = 1;
   } else {
      mode.scan2 = 0;
   }

//   stat.cmd |= CMD_READ_KASRT2;

   return( 0 );
}

//******************** Handler Command 18 ********************

int HandlerCmd18mo3a( int param0, int param1 )
{
   int i;
   struct packet56 *p56;

   if( verbose > 0 ) {
      printf( "HandlerCmd18mo3a: p0=0x%08x p1=0x%08x\n", param0, param1 );
   }

//---------- Outpack5 (cmd18) ----------

   if( param0 ) {
        ControlLed4( 1 );

//      i = outpack5.nsave;
//      p56 = (struct packet56 *)outpack5.buf[i].data;
//      p56->head.code = 0x11;
//      outpack5.buf[i].size = sizeof(struct header56);
//      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
//      outpack5.nsave++;

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x81;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      stat.out |= FLAG_BUF5;
   }
//   } else {
//      i = outpack5.nsave;
//      p56 = (struct packet56 *)outpack5.buf[i].data;
//      p56->head.code = 0x80;
//      outpack5.buf[i].size = sizeof(struct header56);
//      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
//      outpack5.nsave++;
//   }

//---------- Outpack6 (cmd18) ----------

   if( param0 ) {
      ControlLed4( 1 );

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

      stat.out |= FLAG_BUF6;
   } 

//---------- Other (Cmd18) ----------

   if( param0 ) {
      mode.addr3 = param1;
      mode.recv3 = 1;
   } else {
      mode.recv3 = 0;
      outpack0.cr_com++;
   }

   return( 0 );
}

//******************** Handler Command 19 ********************

int HandlerCmd19mo3a( int param0, int param1 )
{
   int i;
   struct packet56 *p56;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd19mo3a: param0=%08x param1=%08x\n", param0, param1 );
   }

//---------- Outpack6 (cmd19) ----------

   if( param0 ) {
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
   }

   return( 0 );
}

//******************** Handler Command 20 ********************

int HandlerCmd20mo3a( int param )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd20mo3a: param=%08x\n", param );
   }

//---------- Outpack5 (cmd20) ----------

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

//******************** Handler Command 21 ********************

int HandlerCmd21mo3a( int param )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd21mo3a: param=%08x\n", param );
   }

//---------- Outpack5 (cmd21) ----------

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

//******************** Handler Command 30 ********************

int HandlerCmd30mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd30mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd30) ----------

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
   if( ( param >= 0 ) && ( param <= 10 ) ) {
      f11->ku7 = param; //PRD-0..10dB
   }
   f11->ku9z0 = 1; //ZAPROS-0
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 31 ********************

int HandlerCmd31mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd31mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd31) ----------

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

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 32 ********************

int HandlerCmd32mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd32mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd32) ----------

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

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 33 ********************

int HandlerCmd33mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd33mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd33) ----------

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

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 40 ********************

int HandlerCmd40mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd40mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd40) ----------

	kzo13_2();

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
   if( ( param >= 0 ) && ( param <= 10 ) ) {
      f11->ku7 = param; //PRD-0..10dB
   }
   f11->ku9z0 = 1; //ZAPROS-0
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 41 ********************

int HandlerCmd41mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd41mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd41) ----------

	kzo13_2();

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
   if( param > 0 ) {
      f11->ku11 = 1;
   } else {
      f11->ku11 = 0;
   }
   f11->ku9z0 = 1; //ZAPROS-0
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 42 ********************

int HandlerCmd42mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd42mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd42) ----------

	kzo13_2();

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
   if( param > 0 ) {
      f11->ku12 = 1;
   } else {
      f11->ku12 = 0;
   }
   f11->ku9z0 = 1; //ZAPROS-0
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 43 ********************

int HandlerCmd43mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
 
   if( verbose > 0 ) {
      printf( "HandlerCmd43mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd43) ----------

	kzo13_2();

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
   if( param > 0 ) {
      f11->ku13 = 1;
   } else {
      f11->ku13 = 0;
   }
   f11->ku9z0 = 1; //ZAPROS-0
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//*************** Handler Command 50 ***************

int HandlerCmd50mo3a( void )
{
   int i;
   struct packet56 *p56;
   time_t t;
   struct tm *tm;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd50mo3a: no param.\n" );
   }

//---------- Outpack5 (cmd50) ----------

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

//******************** Handler Command 60 ********************
int HandlerCmd60mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

//   if( verbose > 0 ) {
      printf( "HandlerCmd60mo3a p=%d\n",param );
//   }

//---------- Outpack1 (cmd60) ----------	//ЦПП КА
   //6
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
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd60) ----------//БУ-1
//3
	BU1_K6(0x01);
//4
	if (param)  BU1_K7(0x00);
	else 		BU1_K7(0x01);

    stat.out |= FLAG_BUF3;
    ControlLed3( 1 );

//---------- Outpack4 (cmd60) ----------//БУ-2
   if (param==0) //только МО1АК
   {	
   	//1
	BU2_K6(0x11);
	//2
	   i = outpack4.nsave;
	   p34 = (struct packet34 *)outpack4.buf[i].data;
	   p34->head.pream = 0x3231;
	   p34->head.code = 0x75;	//РЭС-90
	   p34->data[0] = 0xff;
	   p34->data[1] = 0x00;		//kod 00
	   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
	   outpack4.buf[i].size = sizeof(struct header34) + 3;
	   outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
	   outpack4.nsave++;
   }
   //5
   i = outpack4.nsave;
   p34 = (struct packet34 *)outpack4.buf[i].data;
   p34->head.pream = 0x3534;
   p34->head.code = 5;
   p34->data[0] = 0x01; //ADR
   p34->data[1] = 0xc1; //CMD-UM
   p34->data[2] = 0x05; //LEN
   p34->data[3] = 0xe0; //UM-OFF
   p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
   p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
   outpack4.buf[i].size = sizeof(struct header34) + 6;
   outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
   outpack4.nsave++;

   stat.out |= FLAG_BUF4;
   ControlLed3( 1 );

   return( 0 );
}

//******************** Handler Command 61 ********************

int HandlerCmd61mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd61mo3a\n" );
   }

//---------- Outpack1 (cmd61) ----------

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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 63 ********************

int HandlerCmd63mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd63mo3a\n" );
   }

//---------- Outpack1 (cmd63) ----------

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
   f11->ku0 = 1; //FK
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

   return( 0 );
}

//******************** Handler Command 64 ********************

int HandlerCmd64mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd64mo3a\n" );
   }

//---------- Outpack1 (cmd64) ----------
//4
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
   f11->ku0 = 1; //FK
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 1; //FK-1
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack3 (cmd64) ----------//БУ-1
//3
	BU1_K7(0);
    stat.out |= FLAG_BUF3;
    ControlLed3( 1 );
//---------- Outpack4 (cmd64) ---------- //БУ-2
   if (param==0) //MO1AK
   {
//1
	BU2_K6(1);
//2
		i = outpack4.nsave;
		p34 = (struct packet34 *)outpack4.buf[i].data;
		p34->head.pream = 0x3231;
		p34->head.code = 0x75;
		p34->data[0] = 0xff;
		p34->data[1] = 0x01;
		p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
		outpack4.buf[i].size = sizeof(struct header34) + 3;
		outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
		outpack4.nsave++;

   stat.out |= FLAG_BUF4;
   ControlLed3( 1 );
 }
   return( 0 );
}

//******************** Handler Command 65 ********************

int HandlerCmd65mo3a( int param1 , int param2 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd65mo3a: param1=%08x\n", param1 );
   }
	printf("com65 %d %d\n",param1,param2);

//---------- Outpack1 (cmd65) ----------
//4
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
   if( param1 == 2 ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param1; //FK-2
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 1;
      f11->x1 = 0;
   }
   if( param1 == 3 ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param1; //FK-3
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 0;
      f11->x1 = 1;
   }
   if( ( param1 >= 4 ) && (param1 <= 9 ) ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param1; //FK-4...8
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 0;
      f11->x1 = 0;
   }

   if( param1 ==5 ) {
	    f11->ku8 = 4; //для ФК5 передаем 4
   }

   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );
//---------- Outpack3 (cmd1) ----------//БУ-1
	if (param2==0) 	BU1_K7(0); //MO1AK
	else 			BU1_K7(1); //MO1K

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack4 (cmd65) ----------//БУ-2
  if (param2==0) //MO1AK
  { 
	switch(param1)	//режим ФК
	{
		case 2 : case 3 :

			printf("com65 %d %d\n",param1,param2);

			BU2_K6(0x0F);

		    i = outpack4.nsave;
	    	p34 = (struct packet34 *)outpack4.buf[i].data;
		    p34->head.pream = 0x3534;
		    p34->head.code = 5;
		    p34->data[0] = 0x01; //ADR
		    p34->data[1] = 0xc1; //CMD-UM
		    p34->data[2] = 0x05; //LEN
		    p34->data[3] = 0xe1; //UM-ON
		    p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
		    p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
		    outpack4.buf[i].size = sizeof(struct header34) + 6;
		    outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
		    outpack4.nsave++;
	
			BLKT(4);
			BLKT(4);

		    i = outpack4.nsave;
		    p34 = (struct packet34 *)outpack4.buf[i].data;
		    p34->head.pream = 0x3231;
		    p34->head.code = 0x71;	//уровень 
		    p34->data[0] = 0xff;
	    	p34->data[1] = 0xff;
		    p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
	    	outpack4.buf[i].size = sizeof(struct header34) + 3;
		    outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
		    outpack4.nsave++;
   			break;	 	
		case 4:		case 6:		case 7:		case 8:
		case 9:				BU2_K6(0x21);		break;
		case 5 : 			BU2_K6(0x11);		break;
	}
  
	stat.out |= FLAG_BUF4;
	ControlLed3( 1 );
  }

	return( 0 );
}

//******************** Handler Command 70 ********************

int HandlerCmd70mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd70mo3a\n" );
   }

//---------- Outpack2 (cmd70) ----------

	kzo13_2();

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
   f11->ku0 = 0; //RAB
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack3 (cmd70) ----------

	BU1_K6(1);

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x75;
   p34->data[0] = 0xff;
   p34->data[1] = 0x00;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3534;
   p34->head.code = 5;
   p34->data[0] = 0x01; //ADR
   p34->data[1] = 0xc1; //CMD-UM
   p34->data[2] = 0x05; //LEN
   p34->data[3] = 0xe0; //UM-OFF
   p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
   p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
   outpack3.buf[i].size = sizeof(struct header34) + 6;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

   return( 0 );
}

//******************** Handler Command 71 ********************

int HandlerCmd71mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd71mo3a\n" );
   }

//---------- Outpack2 (cmd71) ----------

	kzo13_2();

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
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 73 ********************

int HandlerCmd73mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;

   if( verbose > 0 ) {
      printf( "HandlerCmd73mo3a\n" );
   }

//---------- Outpack2 (cmd73) ----------

	kzo13_2();

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
   f11->ku0 = 1; //FK
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

   return( 0 );
}

//******************** Handler Command 74 ********************

int HandlerCmd74mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd74mo3a\n" );
   }

//---------- Outpack2 (cmd74) ----------

	kzo13_2();

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
   f11->ku0 = 1; //FK
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 1; //FK-1
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack3 (cmd74) ----------

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

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x75;
   p34->data[0] = 0xff;
   p34->data[1] = 0x01;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

   return( 0 );
}

//******************** Handler Command 75 ********************

int HandlerCmd75mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd75mo3a: param=%08x\n", param );
   }

//---------- Outpack2 (cmd75) ----------//ЦППА КА 2

	kzo13_2();

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
   if( param == 2 ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param; //FK-2
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 1;
      f11->x1 = 0;
   }
   if( param == 3 ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 1; //PRD-ON
      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param; //FK-3
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 0;
      f11->x1 = 1;
   }
   if( ( param >= 4 ) && ( param <= 9 ) ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-ON
      f11->ku2 = 1; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param; //FK-4...9
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 0;
      f11->x1 = 0;
   } 
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack3 (cmd75) ----------

   if( ( param >= 2 ) && (param <= 3 ) ) {
		BU1_K6(0);
		BU1_K7(0);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;		//трансляция БСВЧ
      p34->head.code = 5;			//размер массива
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;
	  //ожидание???
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x71;	//уровень БУ
      p34->data[0] = 0xff;
      p34->data[1] = 0xff;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( ( param >= 4 ) && ( param <= 9 ) )  {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   return( 0 );
}

//******************** Handler Command 80 ********************

int HandlerCmd80mo3a( int param )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd80mo3a: param=%08x\n", param );
   }

//---------- Outpack5 (cmd80) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
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
   p56->data[1] = 0;
   p56->data[0] = 0x1f;
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

//******************** Handler Command 82 ********************

int HandlerCmd82mo3a( void )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd82mo3a\n");
   }

//---------- Outpack5 (cmd82) ----------

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

//******************** Handler Command 83 ********************

int HandlerCmd83mo3a( void )
{
   int i;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd83mo3a\n");
   }

//---------- Outpack5 (cmd83) ----------

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

//******************** Handler Command 90 ******************** 

int HandlerCmd90mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd90mo3a\n");
   }

//---------- Outpack1 (cmd90) ----------

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
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-0
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack2 (cmd90) ----------

	kzo13_2();

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
   f11->ku0 = 0; //RAB
   f11->ku1 = 0; //PRD-OFF
   f11->ku2 = 1; //PRM-ON
   f11->ku3 = 0; //TKI
   f11->ku4 = 1; //FM1
//   f11->ku7 = 0; //PRD-0dB
   f11->ku8 = 0; //FK-OFF
   f11->ku9z0 = 1; //ZAPROS-0
   f11->x0 = 0;
   f11->x1 = 0;

   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack3 (cmd90) ----------

   i = outpack3.nsave;

		BU1_K6(0x15);
		BU1_K7(0x10);

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x75;
   p34->data[0] = 0xff;
   p34->data[1] = 0x00;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3534;
   p34->head.code = 5;
   p34->data[0] = 0x01; //ADR
   p34->data[1] = 0xc1; //CMD-UM
   p34->data[2] = 0x05; //LEN
   p34->data[3] = 0xe0; //UM-OFF
   p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
   p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
   outpack3.buf[i].size = sizeof(struct header34) + 6;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack4 (cmd90) ----------

	BU2_K6(0x11);
	BU2_K7(0x01);

   i = outpack4.nsave;
   p34 = (struct packet34 *)outpack4.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x75;
   p34->data[0] = 0xff;
   p34->data[1] = 0x00;
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack4.buf[i].size = sizeof(struct header34) + 3;
   outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
   outpack4.nsave++;

   i = outpack4.nsave;
   p34 = (struct packet34 *)outpack4.buf[i].data;
   p34->head.pream = 0x3534;
   p34->head.code = 5;
   p34->data[0] = 0x01; //ADR
   p34->data[1] = 0xc1; //CMD-UM
   p34->data[2] = 0x05; //LEN
   p34->data[3] = 0xe0; //UM-OFF
   p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
   p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
   outpack4.buf[i].size = sizeof(struct header34) + 6;
   outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
   outpack4.nsave++;

   stat.out |= FLAG_BUF4;
   ControlLed3( 1 );

   return( 0 );
}

//******************** Handler Command 91 ******************** 

int HandlerCmd91mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd91mo3a\n");
   }

//---------- Outpack1 (cmd91) ----------

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

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );

//---------- Outpack2 (cmd91) ----------

	kzo13_2();

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
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack5 (cmd91) ----------

   i = outpack5.nsave;
   p56 = (struct packet56 *)outpack5.buf[i].data;
   p56->head.code = 0x40;
   p56->data[0] = 0x1f;
   p56->data[1] = 0x00;
   p56->data[2] = 0x02;
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

//*************** Handler Command 92 *************** 

int HandlerCmd92mo3a( int param1 , int param2 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd92mo3a: param1=%x\n", param1 );
   }

//---------- Outpack1 (cmd92) ----------

   if( ( param1 == 1 ) || ( param1 == 3 ) || ( param1 == 5 ) || ( param1 == 9 ) ) {
	
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
      if ( param1 == 9 ) {
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
         f11->x0 = 0;
         f11->x1 = 0;
      } else {
         switch( param1 ) {
         case 1:
         case 3:
            f11->ku0 = 1; //FK
            f11->ku1 = 0; //PRD-OFF
            f11->ku2 = 1; //PRM-ON
            f11->x0 = 0;
            f11->x1 = 0;
            break;
         case 5:
            f11->ku0 = 0; //RAB
            f11->ku1 = 1; //PRD-ON
            f11->ku2 = 0; //PRM-OFF
            f11->x0 = 0;
            f11->x1 = 1;
            break;
         default:
            break;
         }
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
//         f11->ku7 = 0; //PRD-0dB
         switch( param1 ) {
         case 1:   f11->ku8 = 0; //FK-0
            break;
         case 3:   f11->ku8 = 1; //FK-1
            break;
         case 5:   f11->ku8 = 3; //FK-3
            break;
         default:   break;
         }
         f11->ku9z0 = 1; //ZAPROS-0
      }
      memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
      outpack1.nsave++;

	kzo7_1();

      stat.out |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd92) ----------

   if( ( param1 == 2 ) || ( param1 == 4 ) || ( param1 == 6 ) || ( param1 == 10 ) ) {
	
		kzo13_2();

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
      if ( param1 == 10 ) {
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
         f11->x0 = 0;
         f11->x1 = 0;
      } else {
         switch( param1 ) {
         case 2:
         case 4:
            f11->ku0 = 1; //FK
            f11->ku1 = 0; //PRD-OFF
            f11->ku2 = 1; //PRM-ON
            f11->x0 = 0;
            f11->x1 = 0;
            break;
         case 6:
            f11->ku0 = 0; //RAB
            f11->ku1 = 1; //PRD-ON
            f11->ku2 = 0; //PRM-OFF
            f11->x0 = 0;
            f11->x1 = 1;
            break;
         default:
            break;
         }
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
         f11->ku7 = 0; //PRD-0dB
         switch( param1 ) {
         case 2:
            f11->ku8 = 0; //FK-0
            break;
         case 4:
            f11->ku8 = 1; //FK-1
            break;
         case 6:
            f11->ku8 = 3; //FK-3
            break;
         default:
            break;
         }
         f11->ku9z0 = 1; //ZAPROS-0
      }
      memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

	kzo7_2();

      stat.out |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd92) ----------//BU1
	if((param1 == 3) || (param1==5)) 
	{
		if (param2==0)  BU1_K7(0);//MO3AK
		else 			BU1_K7(1);//MO1K

		stat.out |= FLAG_BUF3;
		ControlLed3( 1 );
	}

   if( param1 == 4 ) {

		BU1_K6(0);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x75;//RES90
      p34->data[0] = 0xff;
      p34->data[1] = 0x01; //KOD
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param1 == 6 ) {
		
		BU1_K6(0x10);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x71;
      p34->data[0] = 0xff;
      p34->data[1] = 0xff;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack4 (cmd92) ----------//BU2

   if(( param1 == 3 ) && (param2==0)) {

		BU1_K6(0x01);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x75;	//RES90
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

	if(( param1 == 5 ) && (param2==0)) {
		BU1_K6(0x01);

		    i = outpack4.nsave;
	    	p34 = (struct packet34 *)outpack4.buf[i].data;
		    p34->head.pream = 0x3534;
		    p34->head.code = 5;
		    p34->data[0] = 0x01; //ADR
		    p34->data[1] = 0xc1; //CMD-UM
		    p34->data[2] = 0x05; //LEN
		    p34->data[3] = 0xe1; //UM-ON
		    p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
		    p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
		    outpack4.buf[i].size = sizeof(struct header34) + 6;
		    outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
		    outpack4.nsave++;
	
			BLKT(4);
			BLKT(4);

		    i = outpack4.nsave;
		    p34 = (struct packet34 *)outpack4.buf[i].data;
		    p34->head.pream = 0x3231;
		    p34->head.code = 0x71;	//уровень 
		    p34->data[0] = 0xff;
	    	p34->data[1] = 0xff;
		    p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
	    	outpack4.buf[i].size = sizeof(struct header34) + 3;
		    outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
		    outpack4.nsave++;

	}

//---------- Outpack5 (cmd92) ----------

   if( param1 == 7 ) {
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
      p56->data[2] = 0x02; // ARING SLOVO=2
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
   }

//--------------- Other (cmd92) ---------------

   if( param1 == 8 ) {
      outpack0.cr_com++;
      stat.out = stat.in = 0;
   }

   return( 0 );
}

//*************** Handler Command 93 ***************

int HandlerCmd93mo3a( int param0, int param1, int param2, int param3 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct sac *f26;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   //if( verbose > 0 ) 
	{
      printf( "HandlerCmd93mo3a: p0=%x p1=%x p2=%x p3=%x\n", 
         param0, param1, param2, param3 );
   }

//---------- Outpack1 (cmd93mo3a) ----------

   if(( param0 == 0 ) || (param0==3)) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct sac) / 2;
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f26 = (struct sac *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f26, (char *)&form26k1, sizeof(struct sac) );
      f26->ps = 1;
      if( param1 ) {
         f26->vr = 1;
      } else {
         f26->vr = 0;
      }
      f26->kvi = 2;
      f26->nf = 26;
      f26->r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f26->r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f26->r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f26->r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f26->v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f26->v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f26->v2 = ( param1 / 3600 ) % 10 ;
         f26->v3 = ( param1 / 3600 ) / 10;
      } else {
         f26->v0 = f26->v1 = f26->v2 = f26->v3 = 0;
      }
      f26->a0 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
      f26->a1 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
      f26->a2 = ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) / 100;
      f26->a3 = ( ( param2 % 100000 ) % 10000 ) / 1000;
      f26->a4 = ( param2 % 100000 ) / 10000;
      f26->a5 = param2 / 100000;
      f26->p0 = ( ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
      f26->p1 = ( ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
      f26->p2 = ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) / 100;
      f26->p3 = ( ( param3 % 100000 ) % 10000 ) / 1000;
      f26->p4 = ( param3 % 100000 ) / 10000;
      f26->p5 = param3 / 100000;
      memcpy( (char *)&form26k1, (char *)f26, sizeof(struct sac) );
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct sac);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
      f11->ku10 = 1; 

      memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
      outpack1.nsave++;

		kzo7_1();
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
	  if (param0==3)
	  {			
      	outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1 | BUF3KIT_CMD_KRK;
      	outpack1.buf[i].param = KRK_SWITCH_RECV;
	  }
      outpack1.nsave++;

		kzo7_1();
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) { //14
 
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
	      f11->ku10 = 1; 

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
         outpack1.nsave++;

		kzo7_1();
		BLKT(1);

      } //for(j)

      i = outpack1.nsave;
      outpack1.buf[i].size = 0;
      outpack1.buf[i].cmd = BUF3KIT_CMD_END;
      outpack1.nsave++;
	
      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd93mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct sac) / 2;
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f26 = (struct sac *)(outpack2.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f26, (char *)&form26k2, sizeof(struct sac) );
      f26->ps = 1;
      if( param1 ) {
         f26->vr = 1;
      } else {
         f26->vr = 0;
      }
      f26->kvi = 2;
      f26->nf = 26;
      f26->r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f26->r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f26->r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f26->r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f26->v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f26->v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f26->v2 = ( param1 / 3600 ) % 10 ;
         f26->v3 = ( param1 / 3600 ) / 10;
      } else {
         f26->v0 = f26->v1 = f26->v2 = f26->v3 = 0;
      }
      f26->a0 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
      f26->a1 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
      f26->a2 = ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) / 100;
      f26->a3 = ( ( param2 % 100000 ) % 10000 ) / 1000;
      f26->a4 = ( param2 % 100000 ) / 10000;
      f26->a5 = param2 / 100000;
      f26->p0 = ( ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) % 100) % 10;
      f26->p1 = ( ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
      f26->p2 = ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) / 100;
      f26->p3 = ( ( param3 % 100000 ) % 10000 ) / 1000;
      f26->p4 = ( param3 % 100000 ) / 10000;
      f26->p5 = param3 / 100000;
      memcpy( (char *)&form26k2, (char *)f26, sizeof(struct sac) );
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct sac);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3
	
		kzo13_2();
	
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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {

			kzo13_2();
		
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
	      f11->ku10 = 1; 
         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

		kzo7_2();
		BLKT(2);

      } //for(j)

      i = outpack2.nsave;
      outpack2.buf[i].size = 0;
      outpack2.buf[i].cmd = BUF3KIT_CMD_END;
      outpack2.nsave++;

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd93mo3a) ----------
   if( param0 == 0 ) BU1_K7(0x00); //MO1AK
   if( param0 == 3 ) BU1_K7(0x01); //MO1K

   if( param0 == 1 ) { //SVC-2
		BU1_K6(0x01);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;
   }

   if( param0 != 2 ) { //DMV (R-999)
	stat.out |= FLAG_BUF3;
	ControlLed3( 1 );	
   }
   


//---------- Outpack4 (cmd93mo32a) ----------

   if( param0 == 0 ) { //SVC-1
	  BU2_K6(0x0d);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

		BU2_K6(0x11);

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack5 (cmd93mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x81;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      for( j = 0; j < 16; j++ ) {
		BLKT(5);
      }

      i = outpack5.nsave;
      outpack5.buf[i].size = 0;
      outpack5.buf[i].cmd = BUF3KIT_CMD_END;
      outpack5.nsave++;

      stat.out |= FLAG_BUF5;

   }

//---------- Outpack6 (cmd93mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct sac) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct sac);
      f26 = (struct sac *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memcpy( (char *)f26, (char *)&form26k3, sizeof(struct sac) );
      f26->ps = 1;
      if( param1 ) {
         f26->vr = 1;
      } else {
         f26->vr = 0;
      }
      f26->kvi = 2;
      f26->nf = 26;
      f26->r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f26->r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f26->r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f26->r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f26->v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f26->v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f26->v2 = ( param1 / 3600 ) % 10;
         f26->v3 = ( param1 / 3600 ) / 10;
      } else {
         f26->v0 = f26->v1 = f26->v2 = f26->v3 = 0;
      }
      f26->a0 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
      f26->a1 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
      f26->a2 = ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) / 100;
      f26->a3 = ( ( param2 % 100000 ) % 10000 ) / 1000;
      f26->a4 = ( param2 % 100000 ) / 10000;
      f26->a5 = param2 / 100000;
      f26->p0 = ( ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
      f26->p1 = ( ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
      f26->p2 = ( ( ( param3 % 100000 ) % 10000 ) % 1000 ) / 100;
      f26->p3 = ( ( param3 % 100000 ) % 10000 ) / 1000;
      f26->p4 = ( param3 % 100000 ) / 10000;
      f26->p5 = param3 / 100000;
      memcpy( (char *)&form26k3, (char *)f26, sizeof(struct sac) );
      outpack6.buf[i].size = sizeof(struct header56) + 5 + sizeof(struct sac);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

//      for( j = 0; j < 14; j++ ) {
 //        i = outpack6.nsave;
   //      outpack6.buf[i].size = 0;
     //    outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
       //  outpack6.nsave++;
  //    }

//      i = outpack6.nsave;
  //    outpack6.buf[i].size = 0;
    //  outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      //outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }


//---------- Outpack7 (cmd93mo3a) ----------
   if( param0 == 1 ) { //SVC-2

		BLKT(7);

      i = outpack7.nsave;
      p34 = (struct packet34 *)outpack7.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack7.buf[i].size = sizeof(struct header34) + 6;
      outpack7.buf[i].cmd = BUF3KIT_CMD_BLK7 | BUF3KIT_CMD_SVC;
      outpack7.nsave++;

		BLKT(7);
		BLKT(7);
		BLKT(7);

      i = outpack7.nsave;
      p34 = (struct packet34 *)outpack7.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack7.buf[i].size = sizeof(struct header34) + 6;
      outpack7.buf[i].cmd = BUF3KIT_CMD_BLK7 | BUF3KIT_CMD_KRK;
      outpack7.buf[i].param = KRK_SWITCH_RECV;
      outpack7.nsave++;

      stat.out |= FLAG_BUF7;
      ControlLed3( 1 );
   }
//---------- Other (cmd93mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.addr1 = param3;
     // mode.scan1 = 1;
      break;
   case 1:
      mode.addr2 = param3;
  //    mode.scan2 = 1;
      break;
   case 2:
      mode.addr3 = param3;
      mode.recv3 = 1;
      break;
   case 3:
      mode.addr3 = param3;
//    mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 94 ***************

int HandlerCmd94mo3a( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct sac *f203;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd94mo3a: p0=%x p1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd94mo3a) ----------

   if(( param0 == 0 ) || (param0==3)) { //SVC-1
   //SVC-1 -> Step 1
		
		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct sac) / 2;
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f203 = (struct sac *)(outpack1.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f203, (char *)&form26k1, sizeof(struct sac) );
      f203->ps = 1;
      if( param1 ) {
         f203->vr = 1;
      } else {
         f203->vr = 0;
      }
      f203->kvi = 2;
      f203->nf = 203;
      f203->r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f203->r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f203->r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f203->r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f203->v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f203->v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f203->v2 = ( param1 / 3600 ) % 10 ;
         f203->v3 = ( param1 / 3600 ) / 10;
      } else {
         f203->v0 = f203->v1 = f203->v2 = f203->v3 = 0;
      }
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct sac);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
	  if (param0==3)
	  {			
      	outpack1.buf[i].cmd   = BUF3KIT_CMD_BLK1 | BUF3KIT_CMD_KRK;
      	outpack1.buf[i].param = KRK_SWITCH_RECV;
	  }
      outpack1.nsave++;

		kzo7_1();
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
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
         f11->ku9z10 = 1;//ZAPROS-10
         f11->ku10 = 1;  //ZAPROS-10
         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
         outpack1.nsave++;

			kzo7_1();
			BLKT(1);

      } //for(j)

      i = outpack1.nsave;
      outpack1.buf[i].size = 0;
      outpack1.buf[i].cmd = BUF3KIT_CMD_END;
      outpack1.nsave++;

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd94mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct sac) / 2;
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f203 = (struct sac *)(outpack2.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f203, (char *)&form26k2, sizeof(struct sac) );
      f203->ps = 1;
      if( param1 ) {
         f203->vr = 1;
      } else {
         f203->vr = 0;
      }
      f203->kvi = 2;
      f203->nf = 203;
      f203->r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f203->r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f203->r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f203->r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f203->v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f203->v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f203->v2 = ( param1 / 3600 ) % 10 ;
         f203->v3 = ( param1 / 3600 ) / 10;
      } else {
         f203->v0 = f203->v1 = f203->v2 = f203->v3 = 0;
      }
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct sac);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2 | BUF3KIT_CMD_KRK;
      outpack2.buf[i].param = KRK_SWITCH_RECV;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
			kzo13_2();

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
         f11->ku10 = 1; //ZAPROS-10
         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

			kzo7_2();
			BLKT(2);

      } //for(j)

      i = outpack2.nsave;
      outpack2.buf[i].size = 0;
      outpack2.buf[i].cmd = BUF3KIT_CMD_END;
      outpack2.nsave++;

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }
//---------- Outpack3 (cmd93mo3a) ----------
   if( param0 == 0 ) BU1_K7(0x00); //MO1AK
   if( param0 == 3 ) BU1_K7(0x01); //MO1K

   if( param0 == 1 ) { //SVC-2
		BU1_K6(0x01);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;
   }

   if( param0 == 2 ) { //DMV (R-999)
		BU1_K6(0x3b);
		BU1_K7(0x01);

		BLKT(3);
		BLKT(3);
		BLKT(3);

		BU1_K6(0x10);
		BU1_K7(0);
   }
   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );


//---------- Outpack4 (cmd93mo32a) ----------

   if( param0 == 0 ) { //SVC-1
	  BU2_K6(0x0d);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

		BU2_K6(0x11);

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack5 (cmd93mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

      i = outpack5.nsave;
      p56 = (struct packet56 *)outpack5.buf[i].data;
      p56->head.code = 0x81;
      outpack5.buf[i].size = sizeof(struct header56);
      outpack5.buf[i].cmd = BUF3KIT_CMD_BLK5;
      outpack5.nsave++;

      for( j = 0; j < 16; j++ ) {
		BLKT(5);
      }

      i = outpack5.nsave;
      outpack5.buf[i].size = 0;
      outpack5.buf[i].cmd = BUF3KIT_CMD_END;
      outpack5.nsave++;

      stat.out |= FLAG_BUF5;

   }
//---------- Outpack6 (cmd94mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct sac) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct sac);
      f203 = (struct sac *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memcpy( (char *)f203, (char *)&form26k3, sizeof(struct sac) );
      f203->ps = 1;
      if( param1 ) {
         f203->vr = 1;
      } else {
         f203->vr = 0;
      }
      f203->kvi = 2;
      f203->nf = 203;
      f203->r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f203->r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f203->r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f203->r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f203->v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f203->v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f203->v2 = ( param1 / 3600 ) % 10;
         f203->v3 = ( param1 / 3600 ) / 10;
      } else {
         f203->v0 = f203->v1 = f203->v2 = f203->v3 = 0;
      }
      outpack6.buf[i].size = sizeof(struct header56) + 5 + sizeof(struct sac);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      for( j = 0; j < 14; j++ ) {
		BLKT(6);
      }

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }
//---------- Outpack7 (cmd93mo3a) ----------
   if( param0 == 1 ) { //SVC-2

		BLKT(7);

      i = outpack7.nsave;
      p34 = (struct packet34 *)outpack7.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack7.buf[i].size = sizeof(struct header34) + 6;
      outpack7.buf[i].cmd = BUF3KIT_CMD_BLK7 | BUF3KIT_CMD_SVC;
      outpack7.nsave++;

		BLKT(7);
		BLKT(7);
		BLKT(7);

      i = outpack7.nsave;
      p34 = (struct packet34 *)outpack7.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack7.buf[i].size = sizeof(struct header34) + 6;
      outpack7.buf[i].cmd = BUF3KIT_CMD_BLK7 | BUF3KIT_CMD_KRK;
      outpack7.buf[i].param = KRK_SWITCH_RECV;
      outpack7.nsave++;

      stat.out |= FLAG_BUF7;
      ControlLed3( 1 );
   }
//---------- Other (cmd94mo3a) ----------

   switch( param0 ) {
   case 0:
   //   mode.scan1 = 1;
      break;
   case 1:
   //   mode.scan2 = 1;
      break;
   case 2:
   //   mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 95 ***************

int HandlerCmd95mo3a( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd95mo3a: p0=%x p1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd95mo3a) ----------

   if( param0 == 0 ) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack1.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k1, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 39;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
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
			BLKT(1);

      } //for(j)

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd95mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k2, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 39;
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
			kzo13_2();

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
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

			kzo7_2();
			BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd95mo3a) ----------

   if( param0 == 1 ) { //SVC-2
		BU1_K6(0x01);
		BU1_K7(0x00);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param0 == 2 ) { //DMV (R-999)

	if( !mode.mo1a && mode.mn1 ) {
		BU1_K6(0x3b);
		BU1_K7(0x01);
		BLKT(3);
		BLKT(3);
		BLKT(3);
		BU1_K6(0x1b);
		BU1_K7(0x00);
    }

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack4 (cmd95mo32a) ----------

   if( param0 == 0 ) { //SVC-1
		BU2_K6(0x0d);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x11;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd95mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct form193) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct form193);
      f193 = (struct form193 *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k3, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f193->s.v2 = ( param1 / 3600 ) % 10;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 39;
      outpack6.buf[i].size = sizeof(struct header56) + 5 + 
         sizeof(struct form193);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      for( j = 0; j < 14; j++ ) {
		BLKT(6);
      }

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd95mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.scan1 = 1;
      break;
   case 1:
      mode.scan2 = 1;
      break;
   case 2:
      mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 96 ***************

int HandlerCmd96mo3a( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd96mo3a: p0=%x p1=%x\n", param0, param1 );
   }

//---------- Outpack1 (cmd96mo3a) ----------

   if( param0 == 0 ) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack1.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k1, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 43;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
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
			BLKT(1);

      } //for(j)

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd96mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k2, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f193->s.v2 = ( param1 / 3600 ) % 10;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 43;
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
			kzo13_2();

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
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

		kzo7_2();
		BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd96mo3a) ----------

   if( param0 == 1 ) { //SVC-2
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x74;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param0 == 2 ) { //DMV (R-999)

      if( !mode.mo1a && mode.mn1 ) {
         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x3b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x01;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

			BLKT(3);
			BLKT(3);
			BLKT(3);

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x1b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
         outpack3.buf[i].param = KRK_SWITCH_RECV;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x00;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;
      }

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack4 (cmd96mo32a) ----------

   if( param0 == 0 ) { //SVC-1
      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x0d;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x11;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd96mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct form193) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct form193);
      f193 = (struct form193 *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k3, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f193->s.v2 = ( param1 / 3600 ) % 10;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 43;
      outpack6.buf[i].size = sizeof(struct header56) + 5 + sizeof(struct form193);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      for( j = 0; j < 14; j++ ) {
		BLKT(6);  
	  }

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd96mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.scan1 = 1;
      break;
   case 1:
     mode.scan2 = 1;
     break;
   case 2:
      mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
      break;
   }

   return( 0 );
}

//*************** Handler Command 101 ***************

int HandlerCmd101mo3a( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd101mo3a: p0=%x p1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd101mo3a) ----------

   if( param0 == 0 ) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack1.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k1, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 36;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
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
			BLKT(1);

      } //for(j)

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd101mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_1();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k2, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 36;
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
			kzo13_2();

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
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

			kzo7_2();
			BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd101mo3a) ----------

   if( param0 == 1 ) { //SVC-2
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x74;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param0 == 2 ) { //DMV (R-999)

      if( !mode.mo1a && mode.mn1 ) {
         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x3b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x01;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

			BLKT(3);
			BLKT(3);
			BLKT(3);

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x1b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
         outpack3.buf[i].param = KRK_SWITCH_RECV;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x00;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }

   }

//---------- Outpack4 (cmd101mo32a) ----------

   if( param0 == 0 ) { //SVC-1
      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x0d;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x11;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd101mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct form193) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct form193);
      f193 = (struct form193 *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k3, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f193->s.v2 = ( param1 / 3600 ) % 10;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 36;
      outpack6.buf[i].size = sizeof(struct header56) + 5 + 
         sizeof(struct form193);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      for( j = 0; j < 14; j++ ) BLKT(6);

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd101mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.scan1 = 1;
      break;
   case 1:
      mode.scan2 = 1;
      break;
   case 2:
      mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 102 ***************

int HandlerCmd102mo3a( int param0, int param1 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd102mo3a: p0=%x p1=%x\n", 
         param0, param1 );
   }

//---------- Outpack1 (cmd102mo3a) ----------

   if( param0 == 0 ) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack1.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k1, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 37;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
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
			BLKT(1);	

      } //for(j)

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd102mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k2, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 37;
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
			kzo13_2();

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
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd102mo3a) ----------

   if( param0 == 1 ) { //SVC-2
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x74;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param0 == 2 ) { //DMV (R-999)

      if( !mode.mo1a && mode.mn1 ) {
         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x3b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x01;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

			BLKT(3);
			BLKT(3);
			BLKT(3);

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x1b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
         outpack3.buf[i].param = KRK_SWITCH_RECV;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x00;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }

   }

//---------- Outpack4 (cmd102mo32a) ----------

   if( param0 == 0 ) { //SVC-1
      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x0d;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x11;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd102mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct form193) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct form193);
      f193 = (struct form193 *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k3, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f193->s.v2 = ( param1 / 3600 ) % 10;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 37;
      outpack6.buf[i].size = sizeof(struct header56) + 5 + 
         sizeof(struct form193);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      for( j = 0; j < 14; j++ ) BLKT(6);

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd102mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.scan1 = 1;
      break;
   case 1:
      mode.scan2 = 1;
      break;
   case 2:
      mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 103 ***************

int HandlerCmd103mo3a( int param0, int param1, int param2, int param3 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd103mo3a: p0=%x p1=%x p2=%x p3=%x\n", 
         param0, param1, param2, param3 );
   }

//---------- Outpack1 (cmd103mo3a) ----------

   if( param0 == 0 ) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack1.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k1, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 38;
      if( param2 & 0x8000 ) {
         f193->pn |= 0x01;
      }
      if( param3 & 0x8000 ) {
         f193->pn |= 0x02;
      }
      f193->v2_2 = param2 / ( 0x4000 / 45.0 );
      f193->v3_2 = param3 / ( 0x4000 / 90.0 );
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
      outpack1.nsave++;
      count.out1++;

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
		BLKT(1);

   //SVC-1 -> Step 2

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
		BLKT(1);
		BLKT(1);

   //SVC-1 -> Step 3

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
		BLKT(1);

   //SVC-1 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
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
			BLKT(1);

      } //for(j)

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd103mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
//      h12->kss = sizeof(struct form193) / 2;
      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 1;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
         sizeof(struct header12));
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k2, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out2 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out2 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out2 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 38;
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
      count.out2++;

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 2

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		BLKT(2);

   //SVC-2 -> Step 3

		kzo13_2();

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
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) {
 
			kzo13_2();

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
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

			kzo7_2();
			BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd103mo3a) ----------

   if( param0 == 1 ) { //SVC-2
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x74;
      p34->data[0] = 0xff;
      p34->data[1] = 0x00;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_SVC;
      outpack3.nsave++;

		BLKT(3);
		BLKT(3);
		BLKT(3);

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack3.buf[i].size = sizeof(struct header34) + 6;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
      outpack3.buf[i].param = KRK_SWITCH_RECV;
      outpack3.nsave++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

   if( param0 == 2 ) { //DMV (R-999)

      if( !mode.mo1a && mode.mn1 ) {
         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x3b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x01;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

			BLKT(3);
			BLKT(3);
			BLKT(3);

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x72;
         p34->data[0] = 0xff;
         p34->data[1] = 0x1b;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3 | BUF3KIT_CMD_KRK;
         outpack3.buf[i].param = KRK_SWITCH_RECV;
         outpack3.nsave++;

         i = outpack3.nsave;
         p34 = (struct packet34 *)outpack3.buf[i].data;
         p34->head.pream = 0x3231;
         p34->head.code = 0x74;
         p34->data[0] = 0xff;
         p34->data[1] = 0x00;
         p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
         outpack3.buf[i].size = sizeof(struct header34) + 3;
         outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
         outpack3.nsave++;

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }

   }

//---------- Outpack4 (cmd103mo32a) ----------

   if( param0 == 0 ) { //SVC-1
      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x0d;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe1; //UM-ON
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

		BLKT(4);
		BLKT(4);
		BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3534;
      p34->head.code = 5;
      p34->data[0] = 0x01; //ADR
      p34->data[1] = 0xc1; //CMD-UM
      p34->data[2] = 0x05; //LEN
      p34->data[3] = 0xe0; //UM-OFF
      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
      outpack4.buf[i].size = sizeof(struct header34) + 6;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x11;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd103mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)

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

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x80;
      p56->data[0] = sizeof(struct form193) + 4;
      p56->data[1] = 0xd5;
      p56->data[2] = 0x00;
      p56->data[3] = 0x30;
      p56->data[4] = sizeof(struct form193);
      f193 = (struct form193 *)(outpack6.buf[i].data + 
         sizeof(struct header56) + 5 );
      memset( (char *)f193, 0, sizeof(struct form193) );
      memcpy( (char *)f193, (char *)&form26k3, sizeof(struct sac) );
      f193->s.ps = 1;
      if( param1 ) {
         f193->s.vr = 1;
      } else {
         f193->s.vr = 0;
      }
      f193->s.kvi = 2;
      f193->s.nf = 193;
      f193->s.r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out6 / 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;
         f193->s.v2 = ( param1 / 3600 ) % 10;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 38;
      outpack6.buf[i].size = sizeof(struct header56) + 5 + 
         sizeof(struct form193);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;
      count.out6++;

		BLKT(6);

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

      for( j = 0; j < 14; j++ ) BLKT(6);

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd103mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.scan1 = 1;
      break;
   case 1:
      mode.scan2 = 1;
      break;
   case 2:
      mode.recv3 = 1;
      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 104 ***************

int HandlerCmd104mo3a( int param0, int param1, int param2 )
{
   int i;
   struct packet34 *p34;
   struct packet56 *p56;
   struct sac *f18;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd104mo3a: p0=%x p1=%x p2=%x nform=%d (size=%d)\n", 
         param0, param1, param2, inpack0.nform, 
         sizeof(struct header56) + 5 + sizeof(struct sac) +
         sizeof(short) + sizeof(struct formrls) * inpack0.nform );
   }

//---------- Outpack3 (cmd104mo3a) ----------

   if( !mode.mo1a && mode.mn1 ) {
      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x72;
      p34->data[0] = 0xff;
      p34->data[1] = 0x3b;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;
      count.out3++;

      i = outpack3.nsave;
      p34 = (struct packet34 *)outpack3.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x74;
      p34->data[0] = 0xff;
      p34->data[1] = 0x01;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;
      count.out3++;

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack6 (cmd104mo3a) ----------

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

   i = outpack6.nsave;
   p56 = (struct packet56 *)outpack6.buf[i].data;
   p56->head.code = 0x80;
   p56->data[0] = 4 + sizeof(struct sac) + sizeof(short) + 
      sizeof(struct formrls) * inpack0.nform;
   p56->data[1] = 0xd5;
   p56->data[2] = 0x00;
   p56->data[3] = 0x30;
   p56->data[4] = sizeof(struct sac) + sizeof(short) + 
      sizeof(struct formrls) * inpack0.nform;
   f18 = (struct sac *)( outpack6.buf[i].data + sizeof(struct header56) + 5 );
   memset( (char *)f18, 0, sizeof(struct sac) );
   f18->ps = 1;
   if( param0 ) {
      f18->vr = 1;
   } else {
      f18->vr = 0;
   }
   f18->kvi = 9;
   f18->nf = 18;
   f18->r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
   f18->r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
   f18->r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
   f18->r3 = ( count.out6 / 10000 ) / 1000;
   if( param0 ) {
      f18->v0 = ( ( param0 % 3600 ) / 60 ) % 10;
      f18->v1 = ( ( param0 % 3600 ) / 60 ) / 10;
      f18->v2 = ( param0 / 3600 ) % 10;
      f18->v3 = ( param0 / 3600 ) / 10;
   } else {
      f18->v0 = f18->v1 = f18->v2 = f18->v3 = 0;
   }
   f18->a0 = ( ( ( ( param1 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
   f18->a1 = ( ( ( ( param1 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
   f18->a2 = ( ( ( param1 % 100000 ) % 10000 ) % 1000 ) / 100;
   f18->a3 = ( ( param1 % 100000 ) % 10000 ) / 1000;
   f18->a4 = ( param1 % 100000 ) / 10000;
   f18->a5 = param1 / 100000;
   f18->p0 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) % 10;
   f18->p1 = ( ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) % 100 ) / 10;
   f18->p2 = ( ( ( param2 % 100000 ) % 10000 ) % 1000 ) / 100;
   f18->p3 = ( ( param2 % 100000 ) % 10000 ) / 1000;
   f18->p4 = ( param2 % 100000 ) / 10000;
   f18->p5 = param2 / 100000;
   memcpy( (char *)( outpack6.buf[i].data + sizeof(struct header56) + 5 + 
      sizeof(struct sac) ), 
      (char *)&inpack0.nform, sizeof(short) );
   for( j = 0; j < inpack0.nform; j++ ) {
      memcpy( (char *)( outpack6.buf[i].data + sizeof(struct header56) + 5 + 
         sizeof(struct sac) + sizeof(short) + sizeof(struct formrls) * j ), 
         (char *)&inpack0.form[j], sizeof(struct formrls) );
   }
   outpack6.buf[i].size = sizeof(struct header56) + 5 + sizeof(struct sac) +
      sizeof(short) + sizeof(struct formrls) * inpack0.nform;
   outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
   outpack6.nsave++;
   count.out6++;

		BLKT(6);

   i = outpack6.nsave;
   p56 = (struct packet56 *)outpack6.buf[i].data;
   p56->head.code = 0x40;
   outpack6.buf[i].size = sizeof(struct header56);
   outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
   outpack6.nsave++;

   for( j = 0; j < 4; j++ )	BLKT(6);

   i = outpack6.nsave;
   outpack6.buf[i].size = 0;
   outpack6.buf[i].cmd = BUF3KIT_CMD_KRK | BUF3KIT_CMD_END;
   if( !mode.mo1a && mode.mn1 ) {
      outpack6.buf[i].param = KRK_SWITCH_RECV;
   } else {
      outpack6.buf[i].param = KRK_CMD_OK;
   }
   outpack6.nsave++;

   stat.out |= FLAG_BUF6;
   ControlLed4( 1 );

//---------- Other (cmd104mo3a) ----------

   mode.addr3 = param2;
   mode.recv3 = 1;

   return( 0 );
}

