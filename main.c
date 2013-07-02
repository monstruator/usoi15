
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/select.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/sched.h>
#include <arpa/inet.h>
#include <netdb.h>

#include "globals.h"
#include "tcpip.h"
#include "device.h"

char name[30] = "194.1.1.8";
int port = 8204;
char name0[30] = "194.1.1.5";
int port0 = 8204;
char name1[30] = "192.168.0.157";
int port1 = 4000;
char name2[30] = "192.168.2.157";
int port2 = 4000;
char name3[30] = "/dev/pcs1";
char name4[30] = "/dev/pcs2";
char name5[30] = "/dev/pcs7";
char name6[30] = "/dev/pcs8";
char tfile[30] = "/TInUSOI.txt";
int verbose = 0;

int msock0 = -1;
int msock1 = -1;
int msock2 = -1;
int mfd3 = -1;
int mfd4 = -1;
int mfd5 = -1;
int mfd6 = -1;

struct sockaddr_in maddr0;

fd_set arfd;
fd_set awfd;

void Terminate( int );
void InitArgs( int, char** );
void ArmSelect( void );
int Max7( int, int, int, int, int, int, int );
int ReadTestFile( char * );

void main( int argc, char **argv )
{
   int i;

   struct hostent *hp;
   int saddr = sizeof(struct sockaddr);

   fd_set rfd;
   fd_set wfd;
   struct itimerval tv;
   int rc;
   int nsel = 0;

   int r;
   char buf[100];

//--------------- Start ---------------

   setscheduler( 0, SCHED_FIFO, 14 );

   for( i = _SIGMIN; i <= _SIGMAX; ++i ) {
      if( i != SIGTERM ) {
         signal( i, SIG_IGN );
      }
   }
   signal( SIGTERM, &Terminate );

   InitGlobals();

   mode.pr = 0;
   InitArgs( argc, argv );


   ReadTestFile( tfile );

   mfd3 = OpenDEVnb( name3 );
   if( mfd3 == -1 ) {
      perror( "OpenDEVnb" );
      exit( EXIT_FAILURE );
   } else {
      if( verbose > 1 ) {
         printf( "Open device %s.\n", name3 );
      }
   }

   mfd4 = OpenDEVnb( name4 );
   if( mfd4 == -1 ) {
      perror( "OpenDEVnb" );
      exit( EXIT_FAILURE );
   } else {
      if( verbose > 1 ) {
         printf( "Open device %s.\n", name4 );
      }
   }

   mfd5 = OpenDEVnb( name5 );
   if( mfd5 == -1 ) {
      perror( "OpenDEVnb" );
      exit( EXIT_FAILURE );
   } else {
      if( verbose > 1 ) {
         printf( "Open device %s.\n", name5 );
      }
   }

   mfd6 = OpenDEVnb( name6 );
   if( mfd6 == -1 ) {
      perror( "OpenDEVnb" );
      exit( EXIT_FAILURE );
   } else {
      if( verbose > 1 ) {
         printf( "Open device %s.\n", name6 );
      }
   }

   memset( &maddr0, 0, sizeof(struct sockaddr_in) );
   maddr0.sin_family = AF_INET;
   maddr0.sin_port = htons( port0 );
   hp = gethostbyname( name0 );
   if( hp == 0 ) {
      perror( "gethostbyname" );
      exit( EXIT_FAILURE );
   }
   memcpy( &maddr0.sin_addr, hp->h_addr, hp->h_length );

   msock0 = BindUDPnb( name, port );
   if( msock0 == -1 ) {
      perror( "BindUDPnb" );
      exit( EXIT_FAILURE );
   } else {
      if( verbose > 1 ) {
         puts( "Bind socket 0." );
      }
   }

   memset( &tv, 0, sizeof(struct itimerval) );
   tv.it_value.tv_sec = TIMEOUT_SEC;
   tv.it_value.tv_usec = TIMEOUT_USEC;
   tv.it_interval.tv_sec = 0;
   tv.it_interval.tv_usec = 0;
   if( setitimer( ITIMER_REAL, &tv, NULL ) == -1 ) {
      perror( "setitimer" );
      exit( EXIT_FAILURE );
   }

   FD_ZERO( &arfd );
   FD_ZERO( &awfd );
   FD_SET( msock0, &arfd );
   FD_SET( mfd3, &arfd );
   FD_SET( mfd4, &arfd );
   FD_SET( mfd5, &arfd );
   FD_SET( mfd6, &arfd );

   ControlLed1( 0 );
   ControlLed2( 0 );
   ControlLed3( 0 );
   ControlLed4( 0 );
   ControlLed5( 0 );
   ArmSelect();

//--------------- Cycle ---------------

   for( ;; ) {
      memcpy( &rfd, &arfd, sizeof(rfd) );
      memcpy( &wfd, &awfd, sizeof(wfd) );

      if( getitimer( ITIMER_REAL, &tv ) == -1 ) {
         perror( "getitimer" );
         exit( EXIT_FAILURE );
      }

      rc = select( 1 + Max7( msock0, msock1, msock2, mfd3, mfd4, mfd5, mfd6 ), 
         &rfd, &wfd, 0, &tv.it_value );

      if( rc == -1 ) {
         perror( "select" );
         exit( EXIT_FAILURE );
      } else {
         nsel++; 
         if( verbose > 2 ) {
            printf( "Select %d (%d msec).\n", nsel, clock() );
         }
      }

//--------------- Timeout ---------------

      if( rc == 0 ) {
         if( verbose > 2 ) {
            puts( "Timeout." );
         }
         memset( &tv, 0, sizeof(struct itimerval) );
         tv.it_value.tv_sec = TIMEOUT_SEC;
         tv.it_value.tv_usec = TIMEOUT_USEC;
         tv.it_interval.tv_sec = 0;
         tv.it_interval.tv_usec = 0;
         if( setitimer( ITIMER_REAL, &tv, NULL ) == -1 ) {
            perror( "setitimer" );
            exit( EXIT_FAILURE );
         }
         HandlerTimeout();
         ArmSelect();
         continue;
      }

//--------------- Socket 0 ---------------

      if( msock0 != -1 ) {
         if( FD_ISSET( msock0, &rfd ) ) {
            r = recv( msock0, inbuf0.data, BUFFER2_SIZE, 0 );
            if( r <= 0 ) {
               if( verbose > 1 ) {
                  printf( "Recv socket 0: %d.\n", r );
               }
            } else {
               if( verbose > 1 ) {
                  printf( "Recv socket 0: %d bytes.\n", r );
               }
               inbuf0.size = r; 
               HandlerInBuf0();
               ArmSelect();
            }
         }
         if( FD_ISSET( msock0, &wfd ) ) {
            if( outbuf0.nload < outbuf0.nsave ) {
               i = outbuf0.nload;
               r = sendto( msock0, outbuf0.buf[i].data, outbuf0.buf[i].size,
                  0, (struct sockaddr *)&maddr0, sizeof(maddr0) );
               delay( 1 ); //KLVS CRACK
               if( r <= 0 ) {
                  if( verbose > 0) {
                     printf( "Send socket 0: %d.\n", r );
                  }
                  FD_CLR( msock0, &awfd );
               } else {
                  if( verbose > 2) {
                     printf( "Send %d bytes socket 0: %d bytes.\n", 
                        outbuf0.buf[i].size, r );
                  }
                  outbuf0.nload++;
               }
            } else {
               FD_CLR( msock0, &awfd );
               outbuf0.nload = outbuf0.nsave = 0;
            }
         }
      }

//--------------- Socket 1 ---------------

      if( msock1 != -1 ) {
         if( FD_ISSET( msock1, &rfd ) ) {
            if( inbuf1.save < BUFFER1_SIZE ) {
               i = inbuf1.save;
               r = recv( msock1, &inbuf1.data[i], BUFFER1_SIZE - i, 0 );
               switch( r ) {
               case -1:
                  if( verbose > 1 ) {
                     puts( "Recv socket 1: -1." );
                  }
                  break;
               case 0:
                  if( verbose > 1) {
                     puts( "Close socket 1." );
                  }
                  FD_CLR( msock1, &arfd );
                  FD_CLR( msock1, &awfd );
                  close( msock1 );
                  msock1 = -1;
                  break;
               default:
                  if( verbose > 1) {
                     printf( "Recv socket 1: %d bytes.\n", r );
                  }
                  inbuf1.save += r; 
                  HandlerInBuf1();
                  ArmSelect();
                  break;
               }
            } else {
               if( verbose ) {
                  errno = ENOMEM;
                  perror( "InBuf1" );
               }
               inbuf1.save = inbuf1.load = 0;
            }
         } else if( FD_ISSET( msock1, &wfd ) ) {
            if( outbuf1.load < outbuf1.save ) {
               i = outbuf1.load;
               r = send( msock1, &outbuf1.data[i], outbuf1.save - i, 0 );
               if( r == -1 ) {
                  if( verbose > 0 ) {
                     puts( "Send socket 1: -1." );
                  }
                  FD_CLR( msock1, &awfd );
               } else {
                  if( verbose > 2) {
                     printf( "Send %d bytes socket 1: %d bytes.\n", 
                        outbuf1.save - i, r );
                  }
                  outbuf1.load += r;
               } 
            } else {
               FD_CLR( msock1, &awfd );
               outbuf1.load = outbuf1.save = 0;
            }
         }
      }

//--------------- Socket 2 ---------------

      if( msock2 != -1 ) {
         if( FD_ISSET( msock2, &rfd ) ) {
            if( inbuf2.save < BUFFER1_SIZE ) {
               i = inbuf2.save;
               r = recv( msock2, &inbuf2.data[i], BUFFER1_SIZE - i, 0 );
               switch( r ) {
               case -1:
                  if( verbose > 1 ) {
                     puts( "Recv socket 2: -1." );
                  }
                  break;
               case 0:
                  if( verbose > 1) {
                     puts( "Close socket 2." );
                  }
                  FD_CLR( msock2, &arfd );
                  FD_CLR( msock2, &awfd );
                  close( msock2 );
                  msock2 = -1;
                  break;
               default:
                  if( verbose > 1) {
                     printf( "Recv socket 2: %d bytes.\n", r );
                  }
                  inbuf2.save += r; 
                  HandlerInBuf2();
                  ArmSelect();
                  break;
               }
            } else {
               if( verbose ) {
                  errno = ENOMEM;
                  perror( "InBuf2" );
               }
               inbuf2.save = inbuf2.load = 0;
            }
         } else if( FD_ISSET( msock2, &wfd ) ) {
            if( outbuf2.load < outbuf2.save ) {
               i = outbuf2.load;
               r = send( msock2, &outbuf2.data[i], outbuf2.save - i, 0 );
               if( r == -1 ) {
                  if( verbose > 0 ) {
                     puts( "Send socket 2: -1." );
                  }
                  FD_CLR( msock2, &awfd );
               } else {
                  if( verbose > 1) {
                     printf( "Send %d bytes socket 2: %d bytes.\n", 
                        outbuf2.save - i, r );
                  }
                  outbuf2.load += r;
               } 
            } else {
               FD_CLR( msock2, &awfd );
               outbuf2.load = outbuf2.save = 0;
            }
         }
      }

//--------------- Device 3 ---------------

      if( mfd3 != -1 ) {
         if( FD_ISSET( mfd3, &rfd ) ) {
            if( inbuf3.save < BUFFER1_SIZE ) {
               i = inbuf3.save;
               r = read( mfd3, &inbuf3.data[i], BUFFER1_SIZE - i );
               if( r <= 0 ) {
                  if( verbose > 1 ) {
                     printf( "Read divice 3: %d.\n", r );
                  }
               } else {
                  if( verbose > 1 ) {
                     printf( "Read device 3: %d bytes.\n", r );
                  }
                  inbuf3.save += r; 
                  HandlerInBuf3();
                  ArmSelect();
               }
            } else {
               if( verbose ) {
                  errno = ENOMEM;
                  perror( "InBuf3" );
               }
               inbuf3.save = inbuf3.load = 0;
            }
         }
         if( FD_ISSET( mfd3, &wfd ) ) {
            if( outbuf3.load < outbuf3.save ) {
               i = outbuf3.load;
               r = write( mfd3, &outbuf3.data[i], outbuf3.save - i );
               if( r == -1 ) {
                  if( verbose > 0 ) {
                     puts( "Write device 3: -1." );
                  }
                  FD_CLR( msock2, &awfd );
               } else {
                  if( verbose > 1) {
                     printf( "Write %d bytes device 3: %d bytes.\n", 
                        outbuf3.save - i, r );
                  }
                  outbuf3.load += r;
               } 
            } else {
               FD_CLR( mfd3, &awfd );
               outbuf3.load = outbuf3.save = 0;
            }
         }
      }

//--------------- Device 4 ---------------

      if( mfd4 != -1 ) {
         if( FD_ISSET( mfd4, &rfd ) ) {
            if( inbuf4.save < BUFFER1_SIZE ) {
               i = inbuf4.save;
               r = read( mfd4, &inbuf4.data[i], BUFFER1_SIZE - i );
               if( r <= 0 ) {
                  if( verbose > 1 ) {
                     printf( "Read divice 4: %d.\n", r );
                  }
               } else {
                  if( verbose > 1 ) {
                     printf( "Read device 4: %d bytes.\n", r );
                  }
                  inbuf4.save += r; 
                  HandlerInBuf4();
                  ArmSelect();
               }
            } else {
               if( verbose ) {
                  errno = ENOMEM;
                  perror( "InBuf4" );
               }
               inbuf4.save = inbuf4.load = 0;
            }
         }
         if( FD_ISSET( mfd4, &wfd ) ) {
            if( outbuf4.load < outbuf4.save ) {
               i = outbuf4.load;
               r = write( mfd4, &outbuf4.data[i], outbuf4.save - i );
               if( r == -1 ) {
                  if( verbose > 0 ) {
                     puts( "Write device 4: -1." );
                  }
                  FD_CLR( mfd4, &awfd );
               } else {
                  if( verbose > 1) {
                     printf( "Write %d bytes device 4: %d bytes.\n", 
                        outbuf4.save - i, r );
                  }
                  outbuf4.load += r;
               } 
            } else {
               FD_CLR( mfd4, &awfd );
               outbuf4.load = outbuf4.save = 0;
            }
         }
      }

//--------------- Device 5 ---------------

      if( mfd5 != -1 ) {
         if( FD_ISSET( mfd5, &rfd ) ) {
            if( inbuf5.save < BUFFER1_SIZE ) {
               i = inbuf5.save;
               r = read( mfd5, &inbuf5.data[i], BUFFER1_SIZE - i );
               if( r <= 0 ) {
                  if( verbose > 1 ) {
                     printf( "Read divice 5: %d.\n", r );
                  }
               } else {
                  if( verbose > 1 ) {
                     printf( "Read device 5: %d bytes.\n", r );
                  }
                  inbuf5.save += r; 
                  HandlerInBuf5();
                  ArmSelect();
               }
            } else {
               if( verbose ) {
                  errno = ENOMEM;
                  perror( "InBuf5" );
               }
               inbuf5.save = inbuf5.load = 0;
            }
         }
         if( FD_ISSET( mfd5, &wfd ) ) {
            if( outbuf5.load < outbuf5.save ) {
               i = outbuf5.load;
               r = write( mfd5, &outbuf5.data[i], outbuf5.save - i );
               if( r == -1 ) {
                  if( verbose > 0 ) {
                     puts( "Write device 5: -1." );
                  }
                  FD_CLR( mfd5, &awfd );
               } else {
                  if( verbose > 1) {
                     printf( "Write %d bytes device 5: %d bytes.\n", 
                        outbuf5.save - i, r );
                  }
                  outbuf5.load += r;
               } 
            } else {
               FD_CLR( mfd5, &awfd );
               outbuf5.load = outbuf5.save = 0;
            }
         }
      }

//--------------- Device 6 ---------------

      if( mfd6 != -1 ) {
         if( FD_ISSET( mfd6, &rfd ) ) {
            if( inbuf6.save < BUFFER1_SIZE ) {
               i = inbuf6.save;
               r = read( mfd6, &inbuf6.data[i], BUFFER1_SIZE - i );
               if( r <= 0 ) {
                  if( verbose > 1 ) {
                     printf( "Read divice 6: %d.\n", r );
                  }
               } else {
                  if( verbose > 1 ) {
                     printf( "Read device 6: %d bytes.\n", r );
                  }
                  inbuf6.save += r; 
                  HandlerInBuf6();
                  ArmSelect();
               }
            } else {
               if( verbose ) {
                  errno = ENOMEM;
                  perror( "InBuf6" );
               }
               inbuf6.save = inbuf6.load = 0;
            }
         }
         if( FD_ISSET( mfd6, &wfd ) ) {
            if( outbuf6.load < outbuf6.save ) {
               i = outbuf6.load;
               r = write( mfd6, &outbuf6.data[i], outbuf6.save - i );
               if( r == -1 ) {
                  if( verbose > 0 ) {
                     puts( "Write device 6: -1." );
                  }
                  FD_CLR( mfd6, &awfd );
               } else {
                  if( verbose > 1) {
                     printf( "Write %d bytes device 6: %d bytes.\n", 
                        outbuf6.save - i, r );
                  }
                  outbuf6.load += r;
               } 
            } else {
               FD_CLR( mfd6, &awfd );
               outbuf6.load = outbuf6.save = 0;
            }
         }
      }

//--------------- Continue ---------------

   }
}

void Terminate( int signal )
{
   if( signal ) {
      if( msock0 != -1 ) {
         close( msock0 );
      }
      if( msock1 != -1 ) {
         close( msock1 );
      }
      if( msock2 != -1 ) {
         close( msock2 );
      }
      if( mfd3 != -1 ) {
         close( mfd3 );
      }
      if( mfd4 != -1 ) {
         close( mfd4 );
      }
      if( mfd5 != -1 ) {
         close( mfd5 );
      }
      if( mfd6 != -1 ) {
         close( mfd6 );
      }
   }
   exit( EXIT_SUCCESS );
}

void InitArgs( int argc, char **argv )
{
   int c;

   while( ( c = getopt( argc, argv, "A:0:1:2:3:4:5:6:T:M:v" ) ) != -1 ) {
      switch( c ) {
      case 'A':
         if( strrchr( optarg, ':' ) != NULL ) {
            *strrchr( optarg, ':' ) = ' ';
         }
         sscanf( optarg, "%s %d", name, &port);
         break;
      case '0':
         if( strrchr( optarg, ':' ) != NULL ) {
            *strrchr( optarg, ':' ) = ' ';
         }
         sscanf( optarg, "%s %d", name0, &port0);
         break;
      case '1':
         if( strrchr( optarg, ':' ) != NULL ) {
            *strrchr( optarg, ':' ) = ' ';
         }
         sscanf( optarg, "%s %d", name1, &port1);
         break;
      case '2':
         if( strrchr( optarg, ':' ) != NULL ) {
            *strrchr( optarg, ':' ) = ' ';
         }
         sscanf( optarg, "%s %d", name2, &port2);
         break;
      case '3':
         sscanf( optarg, "%s", name3 );
         break;
      case '4':
         sscanf( optarg, "%s", name4 );
         break;
      case '5':
         sscanf( optarg, "%s", name5 );
         break;
      case '6':
         sscanf( optarg, "%s", name6 );
         break;
      case 'T':
         sscanf( optarg, "%s", tfile );
         break;
      case 'M':
         mode.pr = atoi( optarg );
         break;
      case 'v':
         verbose++;
         break;
      default:
         errno = EINVAL;
         perror( argv[0] );
         break;
      }
   }
}

int Max7( int a1, int a2, int a3, int a4, int a5, int a6, int a7 )
{
   int m = 0;

   if( a1 > m ) m = a1;
   if( a2 > m ) m = a2;
   if( a3 > m ) m = a3;
   if( a4 > m ) m = a4;
   if( a5 > m ) m = a5;
   if( a6 > m ) m = a6;
   if( a7 > m ) m = a7;

   return( m );
}

void ArmSelect( void )
{
   if( outbuf0.nload != outbuf0.nsave ) {
      if( msock0 != -1 ) {
         FD_SET( msock0, &awfd );
      }
   }

   if( outbuf1.load != outbuf1.save ) {
      if( msock1 != -1 ) {
         FD_SET( msock1, &awfd );
      } else {
         msock1 = ConnectTCPnb( name1, port1 );
         if( msock1 != -1 ) {
            if( verbose > 1 ) {
               puts( "Connect socket 1." );
            }
            FD_SET( msock1, &arfd );
            FD_SET( msock1, &awfd );
         } else {
            if( verbose > 1) {
               puts( "Invalid connect socket 1." );
            }
         }
      }
   }

   if( outbuf2.load != outbuf2.save ) {
      if( msock2 != -1 ) {
         FD_SET( msock2, &awfd );
      } else {
         msock2 = ConnectTCPnb( name2, port2 );
         if( msock2 != -1 ) {
            if( verbose > 1) {
               puts( "Connect socket 2." );
            }
            FD_SET( msock2, &arfd );
            FD_SET( msock2, &awfd );
         } else {
            if( verbose > 1) {
               puts( "Invalid connect socket 2." );
            }
         }
      }
   }

   if( outbuf3.load != outbuf3.save ) {
      if( mfd3 != -1 ) {
         FD_SET( mfd3, &awfd );
      } 
   }

   if( outbuf4.load != outbuf4.save ) {
      if( mfd4 != -1 ) {
         FD_SET( mfd4, &awfd );
      } 
   }


   if( outbuf6.load != outbuf6.save ) {
      if( mfd6 != -1 ) {
         FD_SET( mfd6, &awfd );
      } 
   }

   if( outbuf5.load != outbuf5.save ) {
      if( mfd5 != -1 ) {
         FD_SET( mfd5, &awfd );
      } 
   }

}

int ReadTestFile( char *name )
{
   FILE *fp;
   struct sostrts *sr;

   sr = (struct sostrts *)&outpack0.word_sost_rts_1;

   fp = fopen( name, "r" );
   if( fp == NULL ) {
      perror( name );
      return( -1 );
   } else {
      fscanf( fp, "itog=%x,bu=%x", &tstart.itog, &tstart.bu );
      fclose( fp );
      if( tstart.itog ) {
//         sr->usoi = 1; //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
      }
      return( 0 );
   }
}

