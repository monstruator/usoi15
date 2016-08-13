//вопрос по k15 //k65 //k70 //k74 //k75 //90 //92
#include <time.h>
#include "globals.h"
//#include "aes.h"
extern unsigned char in_aes[16], out_aes[16], state[4][4];


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
	}
}

SpeedR999()
{
	int i;
	struct packet56 *p56;
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
}

kzo7_1()
{

/*	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss =   h12->kvi =   h12->ps = 0;
   h12->kzo = 7;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;
*/
}

kzo7_2()
{
/*	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;
   i = outpack2.nsave;
   h12 = (struct header12 *)outpack2.buf[i].data;
   SetHeader12( h12 );
   h12->kss =  h12->kvi = h12->ps = 0;
   h12->kzo = 7;
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;
*/
}

kzo13_1()
{
/*   struct header12 *h12;

	int i;
   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss =  h12->kvi = h12->ps = 0;
   h12->kzo = 1;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   i = outpack1.nsave;
   h12 = (struct header12 *)outpack1.buf[i].data;
   SetHeader12( h12 );
   h12->kss =  h12->kvi = h12->ps = 0;
   h12->kzo = 3;
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;
*/
}


kzo13_2()
{
  /* struct header12 *h12;

	int i;

   i = outpack2.nsave;
   h12 = (struct header12 *)outpack2.buf[i].data;
   SetHeader12( h12 );
   h12->kss =  h12->kvi = h12->ps = 0;
   h12->kzo = 1;
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

   i = outpack2.nsave;
   h12 = (struct header12 *)outpack2.buf[i].data;
   SetHeader12( h12 );
   h12->kss =  h12->kvi = h12->ps = 0;
   h12->kzo = 3;
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;
*/
}

void BU1_K6( int kod ) //гЇа ў«Ґ­ЁҐ аҐ«Ґ Є6 ў Ѓ“1
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   i = outpack3.nsave;
   p34 = (struct packet34 *)outpack3.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x72;	//Љ1-Љ6
   p34->data[0] = 0xff;
   p34->data[1] = kod;	//ЉЋ„ Џђ€ 1 
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack3.buf[i].size = sizeof(struct header34) + 3;
   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
   outpack3.nsave++;
}

void BU2_K6( int kod ) //гЇа ў«Ґ­ЁҐ аҐ«Ґ Є6 ў Ѓ“1
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
      p34->data[1] = kod;			//ЉЋ„
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;
}

void BU1_K7( int kod ) //гЇа ў«Ґ­ЁҐ аҐ«Ґ Є6 ў Ѓ“1
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
	  p34->data[1] = kod;	//ЉЋ„ 
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack3.buf[i].size = sizeof(struct header34) + 3;
      outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
      outpack3.nsave++;

}

void BU2_K7( int kod ) //гЇа ў«Ґ­ЁҐ аҐ«Ґ Є7 ў Ѓ“2
{
	int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
//      p34->head.code = 0x74; 	//Љ7
      p34->head.code = 0x73; 	//Љ7

      p34->data[0] = 0xff;
      p34->data[1] = kod;		//ЉЋ„
//	  printf(" kod_bu2_k7=%x \n\n",kod);
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;
}
//******************** Handler Command 1 ********************

int HandlerCmd1mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;

   if( verbose > 0 ) {
      printf( "HandlerCmd1mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd1) ----------

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


//---------- Outpack4 (cmd1) ----------

	if( param ) {
		BU2_K6(0x11);
      	BU2_K7(0x01);
	
        stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
	}

//---------- Outpack5 (cmd1) ----------

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
      BLKT(5);BLKT(5);

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

//---------- Other (cmd1) ----------

   if( param ) {
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
      f11->ku9z0 = 1; //ZAPROS-NONE
   }

   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;
   ControlLed2( 1 );

//---------- Outpack3 (cmd2) ----------

//   i = outpack3.nsave;
         	
   if( param ) 
      if( mode.mo1a ) BU1_K6(0x15);
      else       	  BU1_K6(0x1b);
    else       		  BU1_K6(0x00);
   
//   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
//   outpack3.buf[i].size = sizeof(struct header34) + 3;
//   outpack3.buf[i].cmd = BUF3KIT_CMD_BLK3;
//   outpack3.nsave++;

   stat.out |= FLAG_BUF3;
   ControlLed3( 1 );

//---------- Outpack4 (cmd2) ----------

   if( param && mode.mo1a ) {
      BU2_K6(0x11);
      BU2_K7(0x01);//2
      
      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack5 (cmd2) ----------

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
      BLKT(5);BLKT(5);

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

//---------- Other (cmd1) ----------
   if( param ) mode.mn1 = 1;
   else        mode.mn1 = 0;

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

   BU2_K7(param);

   stat.out |= FLAG_BUF4;
   ControlLed3( 1 );

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
		mode.prd1=param;
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
		mode.prd2=param;
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
		mode.prm1=param;

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
		mode.prm2=param;
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
   p56->data[1] = ( param0 % 10 ) & 0x0f;
   p56->data[1] |= ( param0 / 10 ) << 4;;
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
      f11->ku9z0 = 1; //ZAPROS-0-NONE
      f11->ku9z1 = 1; //ZAPROS-1-NONE
      f11->ku9z2 = 1; //ZAPROS-2-NONE
      f11->ku9z3 = 1; //ZAPROS-3-NONE
      f11->ku9z4 = 1; //ZAPROS-4-NONE
      f11->ku9z5 = 1; //ZAPROS-5-NONE
      f11->ku9z6 = 1; //ZAPROS-6-NONE
      f11->ku9z7 = 1; //ZAPROS-7-NONE
      f11->ku9z8 = 1; //ZAPROS-8-NONE
      f11->ku9z9 = 1; //ZAPROS-9-NONE
      f11->ku9z10 = 1; //ZAPROS-10-NONE
   }
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;


//---------- Outpack4 (cmd14) ----------

   if( param ) {
    BU2_K6(0x11);
    ControlLed3( 1 );
    stat.out |= FLAG_BUF4;
   }

//--------------- Other (Cmd14) ---------------

   if( param )  {mode.scan1 = mode.scan_p1=1;}
   else         {mode.scan1 = mode.scan_p1=0;}
   
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
      f11->ku9z0 = 1; //ZAPROS-0-NONE
      f11->ku9z1 = 1; //ZAPROS-1-NONE
      f11->ku9z2 = 1; //ZAPROS-2-NONE
      f11->ku9z3 = 1; //ZAPROS-3-NONE
      f11->ku9z4 = 1; //ZAPROS-4-NONE
      f11->ku9z5 = 1; //ZAPROS-5-NONE
      f11->ku9z6 = 1; //ZAPROS-6-NONE
      f11->ku9z7 = 1; //ZAPROS-7-NONE
      f11->ku9z8 = 1; //ZAPROS-8-NONE
      f11->ku9z9 = 1; //ZAPROS-9-NONE
      f11->ku9z10 = 1; //ZAPROS-10-NONE
   }
   memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

	kzo7_2();

   stat.out |= FLAG_BUF2;

//---------- Outpack3 (cmd15) ----------

   if( param ) {
      BU1_K6(0x1b); // 0x00;
      ControlLed3( 1 );
      stat.out |= FLAG_BUF3;
   }

   //--------------- Other ---------------

   if( param )  {mode.scan2 = mode.scan_p2=1;}
   else         {mode.scan2 = mode.scan_p2=0;}
   
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
   int i,i1;
   struct packet56 *p56;
   int j;
   struct sac *f27;
   struct packet34 *p34;
   char b[sizeof(struct form199)];

   if( verbose > 0 ) {
      printf( "HandlerCmd19mo3a: param0=%08x param1=%08x\n", param0, param1 );
   }
//---------- Outpack3 (cmd19mo3a) ----------
	//if( !mode.mo1a && mode.mn1 ) 
	{
        BU1_K6(0x3b);
        BU1_K7(0x01);
         
        for(i1=0;i1<8;i1++) BLKT(3);

        BU1_K6(0x1b);
        BU1_K7(0x00);

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
    }

//---------- Outpack6 (cmd19) ----------

   if( param0 ) {
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
		f27->a0 = mode.a0;//бортовой номер
		f27->a1 = mode.a1;
		f27->a2 = mode.a2;
		f27->a3 = mode.a3;
		f27->a4 = mode.a4;
		f27->a5 = mode.a5;
		f27->p0 = mode.p0;
		f27->p1 = mode.p1;
		f27->p2 = mode.p2;
		f27->p3 = mode.p3;
		f27->p4 = mode.p4;
		f27->p5 = mode.p5;
		WriteC2( f27, sizeof(struct sac) );
		count.out6++;

		i = outpack6.nsave;
		outpack6.buf[i].size = 0;
		outpack6.buf[i].cmd = BUF3KIT_CMD_END | BUF3KIT_CMD_KRK;
		outpack6.buf[i].param = KRK_SWITCH_RECV;
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
   if( param > 1 ) {
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
   if( param > 1 ) {
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
   if( param > 1 ) {
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
   if( param > 1 ) {
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
   if( param > 1 ) {
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
   if( param > 1 ) {
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

int HandlerCmd60mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd60mo3a\n" );
   }

//---------- Outpack1 (cmd60) ----------
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
//---------- Outpack4 (cmd60) ----------

   BU2_K6(0x11);
   BU2_K7(0x00);
   
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

int HandlerCmd64mo3a( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd64mo3a\n" );
   }

//---------- Outpack1 (cmd64) ----------

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

//---------- Outpack3 (cmd64) ----------

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

  
//---------- Outpack4 (cmd64) ----------

   BU2_K6(0x01);
   BU2_K7(0x01);
   
   stat.out |= FLAG_BUF4;
   ControlLed3( 1 );

   return( 0 );
}

//******************** Handler Command 65 ********************

int HandlerCmd65mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmd65mo3a: param=%08x\n", param );
   }

//---------- Outpack1 (cmd65) ----------

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
   if( ( param >= 4 ) && (param <= 9 ) ) {
      f11->ku0 = 1; //FK
      f11->ku1 = 0; //PRD-OFF
      f11->ku2 = 1; //PRM-ON
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku7 = 0; //PRD-0dB
      f11->ku8 = param; //FK-4...8
      f11->ku9z0 = 1; //ZAPROS-0
      f11->x0 = 0;
      f11->x1 = 0;
   }

   if( param ==5 ) {
	    f11->ku8 = 4; //¤«п ”Љ5 ЇҐаҐ¤ Ґ¬ 4
   }

   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

	kzo7_1();

   stat.out |= FLAG_BUF1;
   ControlLed1( 1 );
   
//---------- Outpack4 (cmd65) ----------

   if( ( param >= 2 ) && (param <= 3 ) ) {
      BU2_K6(0x0f);
      
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

      BLKT(4);BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x71;
      p34->data[0] = 0xff;
      p34->data[1] = 0xff;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

   if( ( param >= 4 ) && (param <= 7 ) ) {
      BU2_K6(0x21);
      
      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

   if( param == 8 ) {
       BU2_K6(0x11);

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

   if( param == 9 ) {
       BU2_K6(0x21);

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

   BU1_K6(0x1b);

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

    BU1_K6(0x00);

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

//---------- Outpack2 (cmd75) ----------

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
      BU1_K6(0x00);
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

      BLKT(3);BLKT(3);

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

   if( ( param >= 4 ) && ( param <= 9 ) )  {
      BU1_K6(0x01);

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

int HandlerCmd92mo3a( int param )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct packet34 *p34;
   struct packet56 *p56;
   int n;

   if( verbose > 0 ) {
      printf( "HandlerCmd92mo3a: param=%x\n", param );
   }

//---------- Outpack1 (cmd92) ----------

    if( ( param == 1 ) || ( param == 3 ) || ( param == 5 ) || ( param == 9 ) ) {
	
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
      if ( param == 9 ) {
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
         switch( param ) {
         case 1:
         case 3:
            f11->ku0 = 1; //FK
            f11->ku1 = 0; //PRD-OFF
            f11->ku2 = 1; //PRM-ON
            f11->x0 = 0;
            f11->x1 = 0;
            break;
         case 5:
		      f11->ku0 = 1; //FK
		      f11->ku1 = 1; //PRD-ON
		      f11->ku2 = 0; //PRM-OFF
		      f11->ku3 = 0; //TKI
		      f11->ku4 = 1; //FM1
		//      f11->ku7 = 0; //PRD-0dB
		      f11->ku9z0 = 1; //ZAPROS-0
		      f11->x0 = 1;
		      f11->x1 = 0;
            break;
         default:
            break;
         }
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
//         f11->ku7 = 0; //PRD-0dB
         switch( param ) {
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

   if( ( param == 2 ) || ( param == 4 ) || ( param == 6 ) || ( param == 10 ) ) {
	
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
      if ( param == 10 ) {
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
         switch( param ) {
         case 2:
         case 4:
            f11->ku0 = 1; //FK
            f11->ku1 = 0; //PRD-OFF
            f11->ku2 = 1; //PRM-ON
            f11->x0 = 0;
            f11->x1 = 0;
            break;
         case 6:
		      f11->ku0 = 1; //FK
		      f11->ku1 = 1; //PRD-ON
		      f11->ku2 = 0; //PRM-OFF
		      f11->ku3 = 0; //TKI
		      f11->ku4 = 1; //FM1
		//      f11->ku7 = 0; //PRD-0dB
		      f11->ku9z0 = 1; //ZAPROS-0
		      f11->x0 = 1;
		      f11->x1 = 0;

            break;
         default:            break;
         }
         f11->ku3 = 0; //TKI
         f11->ku4 = 1; //FM1
         f11->ku7 = 0; //PRD-0dB
         switch( param ) {
         case 2:            f11->ku8 = 0; //FK-0
							break;
         case 4:            f11->ku8 = 1; //FK-1
							break;
         case 6:            f11->ku8 = 3; //FK-3
							break;
         default:           break;
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

//---------- Outpack3 (cmd92) ----------

   if( param == 4 ) {
      BU1_K6(0x00);

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
   }

   if( param == 6 ) {
     //BU1_K6(0x10);
      BU1_K6(0x00);
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

      BLKT(3);BLKT(3);

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

//---------- Outpack4 (cmd92) ----------

   if( param == 3 ) {
      BU2_K6(0x01);

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

   if( param == 5 ) {
//     BU2_K6(0x01);
     BU2_K6(0x0f);

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

      BLKT(4);BLKT(4);

      i = outpack4.nsave;
      p34 = (struct packet34 *)outpack4.buf[i].data;
      p34->head.pream = 0x3231;
      p34->head.code = 0x71;
      p34->data[0] = 0xff;
      p34->data[1] = 0xff;
      p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
      outpack4.buf[i].size = sizeof(struct header34) + 3;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
      outpack4.nsave++;

//      i = outpack4.nsave;
//      p34 = (struct packet34 *)outpack4.buf[i].data;
//      p34->head.pream = 0x3534;
//      p34->head.code = 5;
//      p34->data[0] = 0x01; //ADR
//      p34->data[1] = 0xc1; //CMD-UM
//      p34->data[2] = 0x05; //LEN
//      p34->data[3] = 0xe0; //UM-OFF
//      p34->data[4] = Sum2( (unsigned char *)p34->data, 4 ); //KS-DATA
//      p34->data[5] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 5 );
//      outpack4.buf[i].size = sizeof(struct header34) + 6;
//      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
//      outpack4.nsave++;

      stat.out |= FLAG_BUF4;
      ControlLed3( 1 );
   }

//---------- Outpack5 (cmd92) ----------

   if( param == 7 ) {
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
   }

//--------------- Other (cmd92) ---------------

   if( param == 8 ) {
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

   if( verbose > 0 ) {
      printf( "HandlerCmd93mo3a: p0=%x p1=%x p2=%x p3=%x\n", 
         param0, param1, param2, param3 );
   }

//---------- Outpack1 (cmd93mo3a) ----------

   if( param0 == 0 ) { //SVC-1
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
      count.out1++;
      f26->kvi = 2;
      f26->nf = 26;
      f26->r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f26->r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f26->r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f26->r3 = ( count.out1 % 10000 ) / 1000;

	  //printf("\n count.out1=%d r0=%x r1=%x r2=%x r3=%x\n",count.out1,f26->r0,f26->r1,f26->r2,f26->r3);
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

		mode.a0=f26->a0;  //бортовой номер
		mode.a1=f26->a1;
		mode.a2=f26->a2;
		mode.a3=f26->a3;
		mode.a4=f26->a4;
		mode.a5=f26->a5;
		mode.p0=f26->p0;
		mode.p1=f26->p1;
		mode.p2=f26->p2;
		mode.p3=f26->p3;
		mode.p4=f26->p4;
		mode.p5=f26->p5;

      memcpy( (char *)&form26k1, (char *)f26, sizeof(struct sac) );
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct sac);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
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
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

      f11->ku2 = 1; //perevod bloka v priem
	
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
  //    f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
 //     f11->ku10 = 1; 

      memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
      outpack1.nsave++;

		kzo7_1();
		BLKT(1);
		//BLKT(1);

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
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
      h12->ps = 0;
      h12->kzo = 5;
      f26 = (struct sac *)(outpack2.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f26, (char *)&form26k1, sizeof(struct sac) );
      f26->ps = 1;
      if( param1 ) {
         f26->vr = 1;
      } else {
         f26->vr = 0;
      }
      f26->kvi = 2;
      f26->nf = 26;
      count.out1++;
      f26->r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f26->r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f26->r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f26->r3 = ( count.out1 % 10000 ) / 1000;
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

		mode.a0=f26->a0;  //бортовой номер
		mode.a1=f26->a1;
		mode.a2=f26->a2;
		mode.a3=f26->a3;
		mode.a4=f26->a4;
		mode.a5=f26->a5;
		mode.p0=f26->p0;
		mode.p1=f26->p1;
		mode.p2=f26->p2;
		mode.p3=f26->p3;
		mode.p4=f26->p4;
		mode.p5=f26->p5;


      memcpy( (char *)&form26k1, (char *)f26, sizeof(struct sac) );
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct sac);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;

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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
 //     f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
      //f11->ku10 = 1; 

      memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		//BLKT(2);

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
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
	  if (param0==3)
	  {			
      	outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2 | BUF3KIT_CMD_KRK;
      	outpack2.buf[i].param = KRK_SWITCH_RECV;
	  }
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);

   //SVC-2 -> Step 4

      for( j = 0; j < 14; j++ ) { //14
 
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
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);//BLKT(3);

         BU1_K6(0x1b);
         BU1_K7(0x00);
		 
         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }

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
//      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
      outpack4.buf[i].cmd = BUF3KIT_CMD_BLKT | BUF3KIT_CMD_SVC;

      outpack4.nsave++;

      BLKT(4);BLKT(4);//BLKT(4);

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

      for( j = 0; j < 18; j++ ) BLKT(5);

      i = outpack5.nsave;
      outpack5.buf[i].size = 0;
      outpack5.buf[i].cmd = BUF3KIT_CMD_END;
      outpack5.nsave++;

      stat.out |= FLAG_BUF5;

   }

//---------- Outpack6 (cmd93mo3a) ----------

   if( param0 == 2 ) { //DMV (R-999)
		if( !mode.mo1a && mode.mn1 ) { //одидание переключения реле
			BLKT(6);
		}
		
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

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

//      for( j = 0; j < 14; j++ ) {
//         i = outpack6.nsave;
//         outpack6.buf[i].size = 0;
//         outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
//         outpack6.nsave++;
//      }

//      i = outpack6.nsave;
//      outpack6.buf[i].size = 0;
//      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
//      outpack6.nsave++;
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

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd93mo3a) ----------

   switch( param0 ) {
   case 0:
      mode.addr1 = param3;
      mode.scan1 = 0;
      break;
   case 1:
      mode.addr2 = param3;
      mode.scan2 = 0;
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

   if( param0 == 0 ) { //SVC-1
   //SVC-1 -> Step 1

	mode.no_num1=0;

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
	  count.out1++;
      f203->r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f203->r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f203->r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f203->r3 = ( count.out1 % 10000 ) / 1000;
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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
//      f11->ku7 = 0; //PRD-0dB
//      f11->ku8 = 0; //FK-0
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7
 
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
		//BLKT(1);

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
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
         f11->ku9z10 = 1;//ZAPROS-10
         f11->ku10 = 1;  //ZAPROS-10
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
     // stat.link |= FLAG_BUF1;
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
      h12->ps = 0;
      h12->kzo = 5;
      f203 = (struct sac *)(outpack2.buf[i].data + sizeof(struct header12));
      memcpy( (char *)f203, (char *)&form26k1, sizeof(struct sac) );
      f203->ps = 1;
      if( param1 ) {
         f203->vr = 1;
      } else {
         f203->vr = 0;
      }
      f203->kvi = 2;
      f203->nf = 203;
	  count.out1++;

      f203->r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f203->r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f203->r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f203->r3 = ( count.out1 % 10000 ) / 1000;
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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
//      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
//      f11->ku7 = 0; //PRD-0dB
//      f11->ku8 = 0; //FK-0
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
		BLKT(2);BLKT(2);

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
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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

   //SVC-1 -> Step 4

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
         f11->ku9z10 = 1;//ZAPROS-10
         f11->ku10 = 1;  //ZAPROS-10
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
//      stat.link |= FLAG_BUF2;
      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd94mo3a) ----------

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

      BLKT(3);BLKT(3);
		//BLKT(3);

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

         BLKT(3);BLKT(3);BLKT(3);

         BU1_K6(0x1b);
         BU1_K7(0x00);
      }

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack4 (cmd94mo32a) ----------

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

      BLKT(4);BLKT(4);
		//BLKT(4);

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

      for( j = 0; j < 14; j++ ) BLKT(6);

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd94mo3a) ----------

    switch( param0 ) {
    case 0:   		   mode.scan1 = 1;
  					   for(i=0;i<10;i++) outpack0.svch1_no.form1[i]=0;
					   for(i=0;i<5;i++)  outpack0.svch1_no.form2[i]=0;
					   break;
	case 1:   		   mode.scan2 = 1;
  					   for(i=0;i<10;i++) outpack0.svch2_no.form1[i]=0;
					   for(i=0;i<5;i++)  outpack0.svch2_no.form2[i]=0;
					   break;
	case 2:   		//   mode.recv3 = 1;
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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
  //    h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
		//	BLKT(1);

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
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
         f11->ku10 = 1;  //ZAPROS-10
	      f11->ku5 = mode.prd1; //PRD-M1
    	  f11->ku6 = mode.prm1; //PRM-M7

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

	mode.no_num2=0;

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
//      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;
      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
		//BLKT(2);

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
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
         f11->ku10 = 1;  //ZAPROS-10
	      f11->ku5 = mode.prd2; //PRD-M1
    	  f11->ku6 = mode.prm2; //PRM-M7

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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);BLKT(3);

         BU1_K6(0x1b);
		 BU1_K7(0x00);
      }

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack4 (cmd95mo32a) ----------

   if( param0 == 0 ) { //SVC-1
//      BU2_K6(0x0b);
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

      BLKT(4);BLKT(4);
		//BLKT(4);

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

      for( j = 0; j < 14; j++ ) BLKT(6);

      i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_END;
      outpack6.nsave++;

      stat.out |= FLAG_BUF6;
      stat.link |= FLAG_BUF6;
      ControlLed4( 1 );
   }

//---------- Other (cmd95mo3a) ----------

    switch( param0 ) 
	{
    case 0:  mode.scan1 = 1;
  			 for(i=0;i<10;i++) outpack0.svch1_no.form1[i]=0;
			 break;
	case 1:  mode.scan2 = 1;
  			 for(i=0;i<10;i++) outpack0.svch2_no.form1[i]=0;
			 break;
	case 2:  mode.recv3 = 1;      break;
   	default: outpack0.cr_com++;
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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
//      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
      f193->kfs = 42;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
		//BLKT(1);

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
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
         f11->ku10 = 1; //ZAPROS-10
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
//      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;
      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
      f193->kfs = 42;
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;

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
      f11->ku2 = 1; //perevod bloka v priem
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
		//BLKT(2);

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
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
         f11->ku10 = 1; //ZAPROS-10
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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);BLKT(3);

         BU1_K6(0x1b);
         BU1_K7(0x00);
      }

      stat.out |= FLAG_BUF3;
      ControlLed3( 1 );
   }

//---------- Outpack4 (cmd96mo32a) ----------

   if( param0 == 0 ) { //SVC-1
//      BU2_K6(0x0b);
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

      BLKT(4);BLKT(4);//BLKT(4);

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

      for( j = 0; j < 14; j++ ) BLKT(6);

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
   case 0:      mode.scan1 = 1;      break;
   case 1:      mode.scan2 = 1;      break;
   case 2:      mode.recv3 = 1;      break;
   default:     outpack0.cr_com++;
				outpack0.kzv = 1;
				stat.out = stat.in = stat.link = 0;
				break;
   }

   return( 0 );
}

//*************** Handler Command 97 ***************

int HandlerCmd97mo3a( int param0, int param1, int param2 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd97mo3a: p0=%x p1=%x p2=%x\n", 
         param0, param1, param2);
   }

//---------- Outpack1 (cmd97mo3a) ----------

    if( param0 == 0 ) { //SVC-1

   //SVC-1 -> Step 1

		kzo13_1();

      i = outpack1.nsave;
      h12 = (struct header12 *)outpack1.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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

      f193->v1_3 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->v1_2 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->v1_1 = ( ( param2 % 10000 ) % 1000 ) / 100;
      f193->v1_0 = ( param2 % 10000 ) / 1000;

		printf("\nparam2 %x %x %x %x\n", f193->v1_0, f193->v1_1, f193->v1_2, f193->v1_3);
      f193->kfs = 40;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
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
      f11->ku2 = 1; //perevod bloka v priem

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
		//BLKT(1);

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
         f11->ku10 = 1; //ZAPROS-10 !!!

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
         outpack1.nsave++;

			kzo7_1();
			BLKT(1);	

      } //for(j)

      stat.out |= FLAG_BUF1;
      stat.link |= FLAG_BUF1;
    //  stat.rli |= FLAG_BUF1;

      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd97mo3a) ----------

   if( param0 == 1 ) { //SVC-2

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
//      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;
      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
      f193->kfs = 40;

      f193->v1_3 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->v1_2 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->v1_1 = ( ( param2 % 10000 ) % 1000 ) / 100;
      f193->v1_0 = ( param2 % 10000 ) / 1000;

      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;

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
      f11->ku2 = 1; //perevod bloka v priem

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
		//BLKT(2);

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
         f11->ku10 = 1; //ZAPROS-10 !!!

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		//BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
     stat.link |= FLAG_BUF2;
   //   stat.rli |= FLAG_BUF2;

      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd97mo3a) ----------

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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);BLKT(3);

        BU1_K6(0x1b);
		BU1_K7(0x00);

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }
   }
//---------- Outpack4 (cmd97mo32a) ----------

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

      BLKT(4);BLKT(4);//BLKT(4);

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

//---------- Outpack6 (cmd97mo3a) ----------

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

//---------- Other (cmd97mo3a) ----------

   switch( param0 ) {
   case 0:      //mode.scan1 = 1;      
				break;
   case 1:      //mode.scan2 = 1;      
				break;
   case 2:      mode.recv3 = 1;      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0; //1
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
      f11->ku5=mode.prd1;
      f11->ku6=mode.prm1;
      f11->ku2 = 1; //perevod bloka v priem

		f11->ku3=0; //!!!!!!!!!!
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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5=mode.prd1;
      f11->ku6=mode.prm1;
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
		//BLKT(1);
	
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
      f11->ku5=mode.prd1;
      f11->ku6=mode.prm1;

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
//			f11->ku10=10; //!!!!!!!!!!! ��  �뫮 � ࠡ ���ᨨ

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
         f11->ku10 = 1; //ZAPROS-10 !!!

    	  f11->ku5=mode.prd1;
	      f11->ku6=mode.prm1;

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
         outpack1.nsave++;

			kzo7_1();
			BLKT(1);

      } //for(j)

		i=outpack1.nsave;
		outpack1.buf[i].size=0;
		outpack1.buf[i].cmd=BUF3KIT_CMD_END;
		outpack1.nsave++;
			

      stat.out |= FLAG_BUF1;
 //     stat.link |= FLAG_BUF1;
      stat.rli |= FLAG_BUF1;
      ControlLed1( 1 );
   }

//---------- Outpack2 (cmd101mo3a) ----------
 if( param0 == 1 ) { //SVC-1

   //SVC-2 -> Step 1

		kzo13_2();

      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0; //1
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
		f11->ku3=0; //!!!!!!!!!!
      f11->ku2 = 1; //perevod bloka v priem

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
		//BLKT(2);

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
//			f11->ku10=10; //!!!!!!!!!!! ͥ  «ˮ  ࠡ ¥ᡨȍ

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
         f11->ku10 = 1; //ZAPROS DANNIH

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

			kzo7_2();
			BLKT(2);

      } //for(j)

		i=outpack2.nsave;
		outpack2.buf[i].size=0;
		outpack2.buf[i].cmd=BUF3KIT_CMD_END;
		outpack2.nsave++;
			

      stat.out |= FLAG_BUF2;
 //     stat.link |= FLAG_BUF1;
      stat.rli |= FLAG_BUF2;
      ControlLed1( 2 );
   }

//---------- Outpack3 (cmd101mo3a) ----------

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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);BLKT(3);

        BU1_K6(0x1b);
		BU1_K7(0x00);
		
         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }
   }

//---------- Outpack4 (cmd101mo32a) ----------

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


      BLKT(4);BLKT(4);//BLKT(4);

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
//			   	mode.scan1 = 1; 
	   			break; 
 case 1:    
//				mode.scan2 = 1;	
			    break;
   case 2:      mode.recv3 = 1;      break;
   default:
      outpack0.cr_com++;
      outpack0.kzv = 1;
      stat.out = stat.in = stat.link = 0;
   }

   return( 0 );
}

//*************** Handler Command 102 ***************

int HandlerCmd102mo3a( int param0, int param1, int param2 )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
   struct form193 *f193;
   struct packet56 *p56;
   struct packet34 *p34;
   int j;

   if( verbose > 0 ) {
      printf( "HandlerCmd102mo3a: p0=%x p1=%x p2=%x\n", 
         param0, param1, param2);
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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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

      f193->v1_3 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->v1_2 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->v1_1 = ( ( param2 % 10000 ) % 1000 ) / 100;
      f193->v1_0 = ( param2 % 10000 ) / 1000;

		printf("\nparam2 %x %x %x %x\n", f193->v1_0, f193->v1_1, f193->v1_2, f193->v1_3);
      f193->kfs = 37;
      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
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
      f11->ku2 = 1; //perevod bloka v priem

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
		//BLKT(1);

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
         f11->ku10 = 1; //ZAPROS-10 !!!

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
         outpack1.nsave++;

			kzo7_1();
			BLKT(1);	

      } //for(j)

      stat.out |= FLAG_BUF1;
    //  stat.link |= FLAG_BUF1;
      stat.rli |= FLAG_BUF1;

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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
//      h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;
      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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

      f193->v1_3 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->v1_2 = ( ( ( param2 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->v1_1 = ( ( param2 % 10000 ) % 1000 ) / 100;
      f193->v1_0 = ( param2 % 10000 ) / 1000;

      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;

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
      f11->ku2 = 1; //perevod bloka v priem

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
		//BLKT(2);

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
         f11->ku10 = 1; //ZAPROS-10 !!!

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		//BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
   //   stat.link |= FLAG_BUF2;
      stat.rli |= FLAG_BUF2;

      ControlLed2( 1 );
   }

//---------- Outpack3 (cmd102mo3a) ----------

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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);BLKT(3);

        BU1_K6(0x1b);
		BU1_K7(0x00);

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }
   }
//---------- Outpack4 (cmd102mo32a) ----------

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

      BLKT(4);BLKT(4);//BLKT(4);

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
   case 0:      //mode.scan1 = 1;      
				break;
   case 1:      //mode.scan2 = 1;      
				break;
   case 2:      mode.recv3 = 1;      break;
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
	float min=0;

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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
			param2 = param2 & 0x7fff;
      }
      if( param3 & 0x8000 ) {
         f193->pn |= 0x02;
			param3 = param3 & 0x7fff;

      }

      f193->v2_2 = param2 / ( 0x8000 / 90.0 ); //+  
	  min = f193->v2_2 / 0.00274658;	//	printf("min0=%f\n",min); 
      min = param2 - min;	//	printf("min1=%f\n",min); 
	  min = min * 60 * 0.00274658;
      f193->v2_1 = min; //+	//	printf("min2=%f\n",min); 
	  min =  min - f193->v2_1;	//printf("min3=%f\n",min); 
      f193->v2_0 = min * 60;  

      f193->v3_2 = param3 / ( 0x8000 / 180.0 );
	  min = f193->v3_2 / 0.00549316;	//	printf("min0=%f\n",min); 
      min = param3 - min;	//	printf("min1=%f\n",min);   
	  min = min * 60 * 0.00549316;
      f193->v3_1 = min;
	  min =  min - f193->v3_1;	
      f193->v3_0 = min * 60;  

  	  printf("\nshir=%d %d %d ",  f193->v2_2,f193->v2_1,f193->v2_0);
  	  printf("dolg=%d %d %d ",f193->v3_2,f193->v3_1,f193->v3_0);
  	  printf("\nnum=%d %d %d ",f193->s.a0,f193->s.a1,f193->s.a2);
  	  printf("num=%d %d %d \n",f193->s.p0,f193->s.p1,f193->s.p2);


      outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack1.buf[i].cmd = BUF3KIT_CMD_OUT1;
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
      f11->ku2 = 1; //perevod bloka v priem

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
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd1; //PRD-M1
      f11->ku6 = mode.prm1; //PRM-M7

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
		//BLKT(1);

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
         f11->ku10 = 1; //ZAPROS-10

         memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
         outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
         outpack1.nsave++;

			kzo7_1();
			BLKT(1);

      } //for(j)

      stat.out |= FLAG_BUF1;
//      stat.link |= FLAG_BUF1;
      stat.rli |= FLAG_BUF1;

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
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
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
			param2 = param2 & 0x7fff;
      }
      if( param3 & 0x8000 ) {
         f193->pn |= 0x02;
			param3 = param3 & 0x7fff;

      }

      f193->v2_2 = param2 / ( 0x8000 / 90.0 ); //+  
	  min = f193->v2_2 / 0.00274658;	//	printf("min0=%f\n",min); 
      min = param2 - min;	//	printf("min1=%f\n",min); 
	  min = min * 60 * 0.00274658;
      f193->v2_1 = min; //+	//	printf("min2=%f\n",min); 
	  min =  min - f193->v2_1;	//printf("min3=%f\n",min); 
      f193->v2_0 = min * 60;  

      f193->v3_2 = param3 / ( 0x8000 / 180.0 );
	  min = f193->v3_2 / 0.00549316;	//	printf("min0=%f\n",min); 
      min = param3 - min;	//	printf("min1=%f\n",min);   
	  min = min * 60 * 0.00549316;
      f193->v3_1 = min;
	  min =  min - f193->v3_1;	
      f193->v3_0 = min * 60;  

  	  printf("\shir=%d %d %d ",  f193->v2_2,f193->v2_1,f193->v2_0);
  	  printf("\dolg=%d %d %d \n",f193->v3_2,f193->v3_1,f193->v3_0);
  	  printf("\num=%d %d %d \n",f193->s.a0,f193->s.a1,f193->s.a2);
  	  printf("\num=%d %d %d \n",f193->s.p0,f193->s.p1,f193->s.p2);

		f193->s.a0 = mode.a0;//бортовой номер
		f193->s.a1 = mode.a1;
		f193->s.a2 = mode.a2;
		f193->s.a3 = mode.a3;
		f193->s.a4 = mode.a4;
		f193->s.a5 = mode.a5;
		f193->s.p0 = mode.p0;
		f193->s.p1 = mode.p1;
		f193->s.p2 = mode.p2;
		f193->s.p3 = mode.p3;
		f193->s.p4 = mode.p4;
		f193->s.p5 = mode.p5;

  	  printf("\num=%d %d %d \n",f193->s.a0,f193->s.a1,f193->s.a2);
  	  printf("\num=%d %d %d \n",f193->s.p0,f193->s.p1,f193->s.p2);

      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;

/*      i = outpack2.nsave;
      h12 = (struct header12 *)outpack2.buf[i].data;
      SetHeader12( h12 );
      h12->npol = 1;
      h12->nspol = 1;  
      h12->kss = sizeof(struct form193) / 2;
//      h12->kss = ( sizeof(struct form193) / 2 ) & 0xf; //Temp!!!
 //     h12->kss2 = ( sizeof(struct form193) / 2 ) >> 4; //Temp!!!
      h12->kvi = 2;
      h12->ps = 0;
      h12->kzo = 5;
      f193 = (struct form193 *)(outpack2.buf[i].data + 
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
      count.out1++;

      f193->s.r0 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) % 10;
      f193->s.r1 = ( ( ( count.out1 % 10000 ) % 1000 ) % 100 ) / 10;
      f193->s.r2 = ( ( count.out1 % 10000 ) % 1000 ) / 100;
      f193->s.r3 = ( count.out1 % 10000 ) / 1000;
      if( param1 ) {
         f193->s.v0 = ( ( param1 % 3600 ) / 60 ) % 10;
         f193->s.v1 = ( ( param1 % 3600 ) / 60 ) / 10;;
         f193->s.v2 = ( param1 / 3600 ) % 10 ;
         f193->s.v3 = ( param1 / 3600 ) / 10;
      } else {
         f193->s.v0 = f193->s.v1 = f193->s.v2 = f193->s.v3 = 0;
      }
      if( param2 & 0x8000 ) {
         f193->pn |= 0x01;
			param2 = param2 & 0x7fff;
      }
      if( param3 & 0x8000 ) {
         f193->pn |= 0x02;
			param3 = param3 & 0x7fff;

      }

      f193->t1 = 0x00;
      f193->t2 = 0x1d;
      f193->kfs = 38;

      f193->v2_2 = param2 / ( 0x8000 / 90.0 );   
	  min = f193->v2_2 / 0.00274658;	//	printf("min0=%f\n",min); 
      min = param2 - min;	//	printf("min1=%f\n",min); 
	  min = min * 60 * 0.00274658;
      f193->v2_1 = min; //	printf("min2=%f\n",min); 
	  min =  min - f193->v2_1;	//printf("min3=%f\n",min); 
      f193->v2_0 = min * 60;  

      f193->v3_2 = param3 / ( 0x8000 / 180.0 );
	  min = f193->v3_2 / 0.00549316;	//	printf("min0=%f\n",min); 
      min = param3 - min;	//	printf("min1=%f\n",min);   
	  min = min * 60 * 0.00549316;
      f193->v3_1 = min;
	  min =  min - f193->v3_1;	
      f193->v3_0 = min * 60;  

  	  printf("\shir=%d %d %d ",  f193->v2_2,f193->v2_1,f193->v2_0);
  	  printf("\dolg=%d %d %d \n",f193->v3_2,f193->v3_1,f193->v3_0);

      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form193);
      outpack2.buf[i].cmd = BUF3KIT_CMD_OUT2;
      outpack2.nsave++;
*/
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
      f11->ku2 = 1; //perevod bloka v priem

      memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
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
      memcpy( (char *)f11, (char *)&form11k2, sizeof(struct form11) );
      f11->ku0 = 0; //RAB
      f11->ku1 = 1; //PRD-ON
//      f11->ku2 = 0; //PRM-OFF
      f11->ku3 = 0; //TKI
      f11->ku4 = 1; //FM1
//      f11->ku5 = 1; //PRD-M1
//      f11->ku6 = 7; //PRM-M7
      f11->ku5 = mode.prd2; //PRD-M1
      f11->ku6 = mode.prm2; //PRM-M7

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
      memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
      outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
      outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
      outpack2.nsave++;

		kzo7_2();
		BLKT(2);
		//BLKT(2);

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
      memcpy( (char *)f11, (char *)&form11k2, sizeof(struct form11) );
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
      memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
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
         f11->ku10 = 1; //ZAPROS-10 !!!

         memcpy( (char *)&form11k2, (char *)f11, sizeof(struct form11) );
         outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
         outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
         outpack2.nsave++;

			kzo7_2();
			BLKT(2);

      } //for(j)

      stat.out |= FLAG_BUF2;
//      stat.link |= FLAG_BUF2;
      stat.rli |= FLAG_BUF2;

      ControlLed2( 1 );
   }


//---------- Outpack3 (cmd103mo3a) ----------

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

      BLKT(3);BLKT(3);//BLKT(3);

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

         BLKT(3);BLKT(3);//BLKT(3);

          BU1_K6(0x1b);
		  BU1_K7(0x00);

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }
	}   

//---------- Outpack4 (cmd103mo32a) ----------

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
//      outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4 | BUF3KIT_CMD_SVC;
      outpack4.nsave++;

      BLKT(4);BLKT(4);//BLKT(4);

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
    case 0:      //mode.scan1 = 1;
			     break;
	case 1:      //mode.scan2 = 1;
			     break;
    case 2:      mode.recv3 = 1;      break;
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
	short mod_type;

   if( verbose > 0 ) {
      printf( "HandlerCmd104mo3a: p0=%x p1=%x p2=%x nform=%d (size=%d)\n", 
         param0, param1, param2, inpack0.nform, 
         sizeof(struct header56) + 5 + sizeof(struct sac) +
         sizeof(short) + sizeof(struct formrls) * inpack0.nform );
   }

//---------- Outpack3 (cmd104mo3a) ----------
	if( !mode.mo1a && mode.mn1 ) {
          BU1_K6(0x3b);
		  BU1_K7(0x01);


        BLKT(3);BLKT(3);//BLKT(3);

          BU1_K6(0x1b);
		  BU1_K7(0x00);

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }
//---------- Outpack6 (cmd104mo3a) ----------
	if( !mode.mo1a && mode.mn1 ) { //одидание переключения реле
		i = outpack6.nsave;
		outpack6.buf[i].size = 0;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
		outpack6.nsave++;
	}
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
   if( param0 )	f18->vr = 1;
   else 		f18->vr = 0;
   f18->kvi = 10;
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
   } else      f18->v0 = f18->v1 = f18->v2 = f18->v3 = 0;
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

	//printf("form=%d\n",inpack0.nform);	for(j=0;j<194;j++) printf("%x ",outpack6.buf[i].data[j]);printf("\n");

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
      

		//stat.link |= FLAG_BUF6;
		stat.out |= FLAG_BUF6;
		ControlLed4( 1 );

//---------- Other (cmd104mo3a) ----------
		
   mode.addr3 = param2;
   mode.recv3 = 1;

   return( 0 );
}



//*************** Handler Command 115 ***************

int HandlerCmd115mo3a( int param0, int param1, int param2 )
{
   int i,j1,j;
   //struct packet34 *p34;
   struct packet56 *p56;
   struct sac *f18, *f27;
   short b[sizeof(struct form199_dmv)];

//	short mod_type;

   if( verbose > 0 ) {
      printf( "HandlerCmd115mo3a: p0=%x p1=%x p2=%x nform=%d (size=%d)\n", 
         param0, param1, param2, inpack0.nform, 
         sizeof(struct header56) + 5 + sizeof(struct sac) +
         sizeof(short) + 80 );
   }

//---------- Outpack3 (cmd115mo3a) ----------
	if( !mode.mo1a && mode.mn1 ) {
          BU1_K6(0x3b);
		  BU1_K7(0x01);


        BLKT(3);BLKT(3);//BLKT(3);

          BU1_K6(0x1b);
		  BU1_K7(0x00);

         stat.out |= FLAG_BUF3;
         ControlLed3( 1 );
      }
//---------- Outpack6 (cmd115mo3a) ----------
	if( !mode.mo1a && mode.mn1 ) { //одидание переключения реле
		i = outpack6.nsave;
		outpack6.buf[i].size = 0;
		outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
		outpack6.nsave++;
	}
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
   p56->data[0] = 4 + sizeof(struct sac) + sizeof(short) + 80;
   p56->data[1] = 0xd5;
   p56->data[2] = 0x00;
   p56->data[3] = 0x30;
   p56->data[4] = sizeof(struct sac) + sizeof(short) + 80;
   f18 = (struct sac *)( outpack6.buf[i].data + sizeof(struct header56) + 5 );
   memset( (char *)f18, 0, sizeof(struct sac) );
   f18->ps = 1;
   if( param0 ) {
      f18->vr = 1;
   } else {
      f18->vr = 0;
   }
   f18->kvi = 15;
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

	for(j=0;j<5;j++) 
	{
		for(j1=0;j1<16;j1++) in_aes[j1]=inpack0.sms[j1+j*16];
		Cipher();
		for(j1=0;j1<16;j1++) inpack0.sms[j1+j*16]=out_aes[j1];		
	}

   memcpy( (char *)( outpack6.buf[i].data + sizeof(struct header56) + 5 + 
      sizeof(struct sac) + sizeof(short)), (char *)&inpack0.sms[0], 80 );

//	printf("SMS out:");	for(j=0;j<100;j++) printf("%02x ",outpack6.buf[i].data[j+20]);printf("\n");
//	printf("SMS out:");	for(j=0;j<80;j++) printf("%c ",inpack0.sms[j]);printf("\n");
//------------------
/*  
    memcpy(&outpack0.r999_sms.sms[0],(char *)&inpack0.sms[0], 80 );
				
				f27 = (struct sac *)b;
				memset( f27, 0, sizeof(struct sac) );
				f27->ps = 1;
				f27->vr = 0;
				f27->kvi = 15;
				f27->nf = 27;
				f27->r0 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) % 10;
				f27->r1 = ( ( ( count.out6 / 10000 ) % 1000 ) % 100 ) / 10;
				f27->r2 = ( ( count.out6 / 10000 ) % 1000 ) / 100;
				f27->r3 = ( count.out6 / 10000 ) / 1000;
				f27->v0 = f27->v1 = f27->v2 = f27->v3 = 0;
				f27->a0 = f18->p0;
				f27->a1 = f18->p1;
				f27->a2 = f18->p2;
				f27->a3 = f18->p3;
				f27->a4 = f18->p4;
				f27->a5 = f18->p5;
				f27->p0 = f18->a0;
				f27->p1 = f18->a1;
				f27->p2 = f18->a2;
				f27->p3 = f18->a3;
				f27->p4 = f18->a4;
				f27->p5 = f18->a5;
		printf("\nSACH:");
	  for(j=0;j<6;j++)  {outpack0.r999_sms.sach18[j]=b[j];printf("%04x ",b[j]);}printf("\n");
      outpack0.r999.cr++;
*/
//------------------
   outpack6.buf[i].size = sizeof(struct header56) + 5 + sizeof(struct sac) +
      sizeof(short) + 80;
   outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
   outpack6.nsave++;
   count.out6++;

		i = outpack6.nsave;
      outpack6.buf[i].size = 0;
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLKT;
      outpack6.nsave++;

      i = outpack6.nsave;
      p56 = (struct packet56 *)outpack6.buf[i].data;
      p56->head.code = 0x40;
      outpack6.buf[i].size = sizeof(struct header56);
      outpack6.buf[i].cmd = BUF3KIT_CMD_BLK6;
      outpack6.nsave++;

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
      

		//stat.link |= FLAG_BUF6;
		stat.out |= FLAG_BUF6;
		ControlLed4( 1 );

//---------- Other (cmd115mo3a) ----------
		
   mode.addr3 = param2;
   mode.recv3 = 1;

   return( 0 );
}


