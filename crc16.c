#include <stdio.h>
#include "packets.h"

struct fomr1n *form1;
unsigned char len = 18;
unsigned char buff[20];
unsigned short crc16(const unsigned char*, unsigned char);
unsigned short sum;
int i;

main (void)
{
	//-----------------------------------заполнение структуры------------------------------
      form1->r1 = 4;
      form1->tps = 1;
      form1->r2 = 2;
      form1->tak = 1;
      form1->rilv = 2;
      form1->rp = 2;
      form1->nf = 4;

      form1->kx = 15;
      form1->kxz = 1;

      form1->ky = 15;
      form1->kyz = 1;

      form1->kvk = 16;

      form1->vp = 7;
      form1->svk = 9;

      form1->v0 = 6;
      form1->v1 = 6;
      form1->v2 = 4;

      form1->sko = 13;
      form1->rrpnk = 3;

      form1->r3 = 1;
      form1->nvkg = 3;
      form1->bnvk0 = 4;
      form1->bnvk1 = 4;
      form1->bnvk2 = 4;

      form1->tv0 = 6;
      form1->tv1 = 5;
      form1->tv2 = 6;

      form1->ks = 0x0000;
	  
	 //--------------------------------------------------------------------------------------------------------
   
   memcpy((char *)buff, (char *)form1, sizeof(buff));  //копирование структуры в массив
   printf("      tv1=%04x  \n", form1->tv1);  // проверка что структура заполняефтся
   for (i=0; i<20; i++)                       // проверка заполнения массива
   {
		printf("      buff[%d]=%04x  \n",i, buff[i]);
   }
	
	sum = crc16(buff, 18);  //считаем контрольную сумму
	printf ("control summ = %04x  \n", sum);   // для отладки
	form1->ks = sum;  // записываем контрольную сумму в структуру
	printf("form1_ks = %04x  \n", form1->ks);   // для отладки
	
}


unsigned short crc16(const unsigned char* data, unsigned char lenght)
{
	unsigned char x;
	unsigned short crc = 0xFFFF;
	
	while (lenght--)
	{
		x = crc >> 8 ^ *data++;
		x ^= x>>4;
		crc = (crc <<8) ^ ((unsigned short)(x << 12)) ^ (( unsigned short)(x << 5)) ^ ((unsigned short)x);
	}
	printf("crc = %04x  \n", crc);   // для отладки
	return crc;
}