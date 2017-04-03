#include <stdio.h>
#include "packets.h"

struct formrls form1;
unsigned char *buff;//[sizeof(struct formrls)];
unsigned short crc16(const unsigned char*, unsigned char);
int i;

main (void)
{
	//-----------------------------------заполнение структуры------------------------------
	buff = (unsigned char *) &form1.num_out;
	form1.num_out=2;
    form1.num_in=0x1000;
    form1.div_course=1000001;
	//--------------------------------------------------------------------------------------------------------
   
	//memcpy((char *)buff, (char *)form1, sizeof(struct formrls));  //копирование структуры в массив
	for (i=0; i<sizeof(struct formrls); i++) printf(" %02x", buff[i]);  printf("\n");                  // проверка заполнения массива
	
	form1.cksum = crc16(buff, sizeof(struct formrls)-2);  //считаем контрольную сумму

	for (i=0; i<sizeof(struct formrls); i++) printf(" %02x", buff[i]);  printf("\n");                 // проверка заполнения массива	
}


unsigned short crc16(const unsigned char* data, unsigned char lenght)
{
	unsigned char x;
	unsigned short crc = 0xFFFF;
	int i;
	for(i=0;i<80;i++) printf("%02x ",*(data+i)); printf("\n");
	while (lenght--)
	{
		x = crc >> 8 ^ *data++;
		x ^= x>>4;
		crc = (crc <<8) ^ ((unsigned short)(x << 12)) ^ (( unsigned short)(x << 5)) ^ ((unsigned short)x);
	}
	printf("crc = %04x  \n", crc);   // для отладки
	
	return crc;
}