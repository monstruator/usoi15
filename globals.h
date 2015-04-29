
#ifndef GLOBALS_H

   #define GLOBALS_H

   #include "packets.h"
   #include "handbuf0.h"
   #include "handbuf1.h"
   #include "handbuf2.h"
   #include "handbuf3.h"
   #include "handbuf4.h"
   #include "handbuf5.h"
   #include "handbuf6.h"
   #include "handtout.h"
   #include "handcmd3a.h"
   #include "led.h"

   #define PART0_SIZE 1400

   #define TIMEOUT_SEC 0
//   #define TIMEOUT_USEC 400000
   #define TIMEOUT_USEC 500000

   #define FLAG_BUF0 0x0001
   #define FLAG_BUF1 0x0002
   #define FLAG_BUF2 0x0004
   #define FLAG_BUF3 0x0008
   #define FLAG_BUF4 0x0010
   #define FLAG_BUF5 0x0020
   #define FLAG_BUF6 0x0040

   #define FLAG_KASRT1 0x0100
   #define FLAG_KASRT2 0x0200
   #define FLAG_SVC1 0x0400
   #define FLAG_SVC2 0x0800

   #define STEP_NONE 0
   #define STEP_MARK 1
   #define STEP_HEADER 2
   #define STEP_DATA 3
   #define STEP_HANDLER 4

   #define PI 3.1415926535897932384626433832795

   #ifdef DEFINE_GLOBALS

      struct status stat;
      struct timeout tout;
      struct workmode mode;
      struct counts count;

      struct buffer2 inbuf0;
      struct buffer2kit outbuf0;
      struct buffer1 inbuf1;
      struct buffer1 outbuf1;
      struct buffer1 inbuf2;
      struct buffer1 outbuf2;
      struct buffer1 inbuf3;
      struct buffer1 outbuf3;
      struct buffer1 inbuf4;
      struct buffer1 outbuf4;
      struct buffer1 inbuf5;
      struct buffer1 outbuf5;
      struct buffer1 inbuf6;
      struct buffer1 outbuf6;

      struct packcmd inpack0;
      struct packusoi outpack0;
      struct buffer3kit outpack1;
      struct buffer3kit outpack2;
      struct buffer3kit outpack3;
      struct buffer3kit outpack4;
      struct buffer3kit outpack5;
      struct buffer3kit outpack6;

      struct teststart tstart;

      struct form11 form11k1;
      struct form11 form11k2;

      struct sac form26k1;
      struct sac form26k2;
      struct sac form26k3;

      struct config999 r999cfg;

   #else

      extern struct status stat;
      extern struct timeout tout;
      extern struct workmode mode;
      extern struct counts count;

      extern struct buffer2 inbuf0;
      extern struct buffer2kit outbuf0;
      extern struct buffer1 inbuf1;
      extern struct buffer1 outbuf1;
      extern struct buffer1 inbuf2;
      extern struct buffer1 outbuf2;
      extern struct buffer1 inbuf3;
      extern struct buffer1 outbuf3;
      extern struct buffer1 inbuf4;
      extern struct buffer1 outbuf4;
      extern struct buffer1 inbuf5;
      extern struct buffer1 outbuf5;
      extern struct buffer1 inbuf6;
      extern struct buffer1 outbuf6;

      extern void InitGlobals( void );

      extern struct packcmd inpack0;
      extern struct packusoi outpack0;
      extern struct buffer3kit outpack1;
      extern struct buffer3kit outpack2;
      extern struct buffer3kit outpack3;
      extern struct buffer3kit outpack4;
      extern struct buffer3kit outpack5;
      extern struct buffer3kit outpack6;

      extern struct teststart tstart;

      extern struct form11 form11k1;
      extern struct form11 form11k2;

      extern struct sac form26k1;
      extern struct sac form26k2;
      extern struct sac form26k3;

      extern struct config999 r999cfg;

      extern int CheckStatus( void );
      extern void SetHeader12( struct header12 * );
      extern void ResetBuffers( void );
      extern int Sum2( unsigned char *, int len );
      extern int SumBit8( unsigned char );

   #endif

#endif

