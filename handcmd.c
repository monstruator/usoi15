
#include <time.h>
#include "globals.h"

extern int verbose;

//*************** Handler Command Set Kar ***************

int HandlerCmdKar( int param )
{
   int i;
   struct packet34 *p34;

   if( verbose > 0 ) {
      printf( "HandlerCmdSetKar: param=0x%08x\n", param );
   }

   ControlLed3( 1 );

   i = outpack4.nsave;
   p34 = (struct packet34 *)outpack4.buf[i].data;
   p34->head.pream = 0x3231;
   p34->head.code = 0x74;
   p34->data[0] = 0xff;
   switch( param ) {
   case 1:
      p34->data[1] = 0x02;
      break;
   case 2:
      p34->data[1] = 0x04;
      break;
   case 3:
      p34->data[1] = 0x08;
      break;
   case 4:
      p34->data[1] = 0x10;
      break;
   case 5:
      p34->data[1] = 0x20;
      break;
   case 6:
      p34->data[1] = 0x40;
      break;
   default:
      p34->data[1] = 0x01;
      break;
   }
   p34->data[2] = Sum2( (unsigned char *)p34, sizeof(struct header34) + 2 );
   outpack4.buf[i].size = sizeof(struct header34) + 3;
   outpack4.buf[i].cmd = BUF3KIT_CMD_BLK4;
   outpack4.nsave++;

   return( 0 );
}

//*************** Handler Command Kvi7 KASRT1 ***************

int HandlerCmdKasrt17( void )
{
   int i;
   struct header12 *head;
   static unsigned char nsoob = 0;
   time_t t;

   if( verbose > 0 ) {
      printf( "HandlerCmdKasrt17: no param\n" );
   }

   ControlLed1( 1 );

   i = outpack1.nsave;
   head = (struct header12 *)outpack1.buf[i].data;
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
   head->kvi = 0; //Type mesage
   head->sk = 0;
   head->kg = 0;
   head->kpts = 0;
   head->ps = 0; //Flag finish
   head->kzo = 7; //Type header
   head->rez14 = 0;
   head->totpm = (unsigned short)(t & 0xffff);
   head->totps = (unsigned short)(t >> 16);
   outpack1.buf[i].size = sizeof(struct header12);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;
   stat.out |= FLAG_BUF1;

   return( 0 );
}

//*************** Handler Command Kvi7 KASRT2 ***************

int HandlerCmdKasrt27( void )
{
   int i;
   struct header12 *head;
   static unsigned char nsoob = 0;
   time_t t;

   if( verbose > 0 ) {
      printf( "HandlerCmdKasrt27: no param\n" );
   }

   ControlLed2( 1 );

   i = outpack2.nsave;
   head = (struct header12 *)outpack2.buf[i].data;
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
   head->kvi = 0; //Type mesage
   head->sk = 0;
   head->kg = 0;
   head->kpts = 0;
   head->ps = 0; //Flag finish
   head->kzo = 7; //Type header
   head->rez14 = 0;
   head->totpm = (unsigned short)(t & 0xffff);
   head->totps = (unsigned short)(t >> 16);
   outpack2.buf[i].size = sizeof(struct header12);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;
   stat.out |= FLAG_BUF2;

   return( 0 );
}

//*************** Handler Command Scan KASRT1 ***************

int HandlerCmdScan1( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
	static short n_scan1; //кол-во повторов скана

   if( verbose > 0 ) {
      printf( "HandlerCmdScan1: %d\n",n_scan1 );
   }
	n_scan1++;
	if (n_scan1>80)//80 
		{
			outpack0.svch1.nword=0;
			outpack0.svch2.nword=0;
			n_scan1=mode.scan1=0;
			printf("mode.scan1=0\n");
			return(0);
		} //завершение после 80 опросов
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
   f11->ku9z10 = 1;
   f11->ku10 = 1;
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

/* kzo7_1(); */
   return( 0 );
}

int HandlerCmdRli1( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
	static short n_rli1; //кол-во повторов скана

   if( verbose > 0 ) {
      printf( "HandlerCmdRli1: %d \n",mode.n_rli1 );
   }
	mode.n_rli1++;
	if (mode.n_rli1>70)  //30
		{
			outpack0.svch1.nword=0;
			mode.n_rli1=mode.rli1=0; //завершение после 25 опросов
			printf("mode.rli1=0\n");
			return(0);
		}
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
   f11->ku9z10 = 1;
   f11->ku10 = 1;
   f11->ku3 = 1;

   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack1.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack1.buf[i].cmd = BUF3KIT_CMD_BLK1;
   outpack1.nsave++;

   return( 0 );
}

int HandlerCmdRli2( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
	static short n_rli2; //кол-во повторов скана

   if( verbose > 0 ) {
      printf( "HandlerCmdRli2: %d \n",mode.n_rli2 );
   }
	mode.n_rli2++;
	if (mode.n_rli2>70)  //30
		{
			outpack0.svch2.nword=0;
			mode.n_rli2=mode.rli2=0; //завершение после 25 опросов
			printf("mode.rli2=0\n");
			return(0);
		}
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
   f11->ku9z10 = 1;
   f11->ku10 = 1;
   f11->ku3 = 1;

   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

   return( 0 );
}


//*************** Handler Command Scan KASRT2 ***************

int HandlerCmdScan2( void )
{
   int i;
   struct header12 *h12;
   struct form11 *f11;
	static short n_scan2; //кол-во повторов скана

   if( verbose > 0 ) {
      printf( "HandlerCmdScan2: %d\n",n_scan2 );
   }
	n_scan2++;
	if (n_scan2>80)//80 
		{
			n_scan2=mode.scan2=0;
			printf("mode.scan2=0\n");
			return(0);
		} //завершение после 80 опросов
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
   f11->ku9z10 = 1;
   f11->ku10 = 1;
   memcpy( (char *)&form11k1, (char *)f11, sizeof(struct form11) );
   outpack2.buf[i].size = sizeof(struct header12) + sizeof(struct form11);
   outpack2.buf[i].cmd = BUF3KIT_CMD_BLK2;
   outpack2.nsave++;

/* kzo7_2(); */
   return( 0 );

}

