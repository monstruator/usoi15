
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#define SIZE_INBUF_TCP 61440
#define SIZE_OUTBUF_TCP 61440

#define SIZE_INBUF_UDP 20000
#define SIZE_OUTBUF_UDP 20000

int BindTCPnb( char *name, unsigned short port )
{
   int sock;
   int one = 1;
   int ibuf = SIZE_INBUF_TCP;
   int obuf = SIZE_OUTBUF_TCP;
   struct sockaddr_in addr;
   struct hostent *hp;

   sock = socket( AF_INET, SOCK_STREAM, 0 );
   if( sock == -1 ) {
      perror( "socket" );
      return( -1 );
   }

   if( ioctl( sock, FIONBIO, &one ) == -1 ) {
      perror( "ioctl(FIONBIO)" );
      close( sock );
      return( -1 );
   }

   if( ibuf != 0 ) {
      if( setsockopt( sock, SOL_SOCKET, SO_RCVBUF, &ibuf, sizeof(ibuf) ) == -1 ) { 
         perror( "setsockopt(SO_RCVBUF)" );
         close( sock );
         return( -1 );
      } 
   }

   if( obuf != 0 ) {
      if( setsockopt( sock, SOL_SOCKET, SO_SNDBUF, &obuf, sizeof(obuf) ) == -1 ) { 
         perror( "setsockopt(SO_SNDBUF)" );
         close( sock );
         return( -1 );
      }
   }

   memset( &addr, 0, sizeof(addr) );
   addr.sin_family = AF_INET;
   if( name != NULL ) {
      hp = gethostbyname( name );
      if( hp == NULL ) {
         herror( "gethostbyname" );
         close( sock );
         return( -1 );
      }
      memcpy( &addr.sin_addr, hp->h_addr, hp->h_length );
   } else {
      addr.sin_addr.s_addr = INADDR_ANY;
   }
   addr.sin_port = htons( port );

   if( bind( sock, (struct sockaddr *)&addr, sizeof(addr) ) == -1 ) {
      perror( "bind" );
      close( sock );
      return( -1 );
   }

   if( listen( sock, 5) == -1 ) {
      perror( "listen" );
      close( sock );
      return( -1 );
   }

   return( sock );
}

int ConnectTCPnb( char *name, unsigned short port )
{
   int sock;
   int one = 1;
   int ibuf = SIZE_INBUF_TCP;
   int obuf = SIZE_OUTBUF_TCP;
   struct sockaddr_in addr;
   struct hostent *hp;

   sock = socket( AF_INET, SOCK_STREAM, 0 );
   if( sock == -1 ) {
      perror( "socket" );
      return( -1 );
   }

   if( ioctl( sock, FIONBIO, &one ) == -1 ) {
      perror( "ioctl(FIONBIO)" );
      close( sock );
      return( -1 );
   }

   if( ibuf != 0 ) {
      if( setsockopt( sock, SOL_SOCKET, SO_RCVBUF, &ibuf, sizeof(ibuf) ) == -1 ) { 
         perror( "setsockopt(SO_RCVBUF)" );
         close( sock );
         return( -1 );
      }
   } 

   if( obuf != 0 ) {
      if( setsockopt( sock, SOL_SOCKET, SO_SNDBUF, &obuf, sizeof(obuf) ) == -1 ) { 
         perror( "setsockopt(SO_SNDBUF)" );
         close( sock );
         return( -1 );
      }
   }

   memset( &addr, 0, sizeof(addr) );
   addr.sin_family = AF_INET;
   if( name != NULL ) {
      hp = gethostbyname( name );
      if( hp == NULL ) {
         herror( "gethostbyname" );
         close( sock );
         return( -1 );
      }
      memcpy( &addr.sin_addr, hp->h_addr, hp->h_length );
   } else {
      addr.sin_addr.s_addr = inet_addr( "127.0.0.1" );
   }
   addr.sin_port = htons( port );

   if( connect( sock, (struct sockaddr *)&addr, sizeof(addr) ) == -1 ) {
      if( errno != EINPROGRESS ) {
         perror( "connect" );
         close( sock );
         return( -1 );
      }
   }

   return( sock );
}


int BindUDPnb( char *name, unsigned short port )
{
   int sock;
   int one = 1;
   int ibuf = SIZE_INBUF_UDP;
   int obuf = SIZE_OUTBUF_UDP;

   struct sockaddr_in addr;
   struct hostent *hp;

   sock = socket( AF_INET, SOCK_DGRAM, 0 );
   if( sock == -1 ) {
      perror( "socket" );
      return( -1 );
   }

   if( ioctl( sock, FIONBIO, &one ) == -1 ) {
      perror( "ioctl(FIONBIO)" );
      close( sock );
      return( -1 );
   }

   if( ibuf != 0 ) {
      if( setsockopt( sock, SOL_SOCKET, SO_RCVBUF, &ibuf, sizeof(ibuf) ) == -1 ) { 
         perror( "setsockopt(SO_RCVBUF)" );
         close( sock );
         return( -1 );
      } 
   }

   if( obuf != 0 ) {
      if( setsockopt( sock, SOL_SOCKET, SO_SNDBUF, &obuf, sizeof(obuf) ) == -1 ) { 
         perror( "setsockopt(SO_SNDBUF)" );
         close( sock );
         return( -1 );
      }
   }

   memset( &addr, 0, sizeof(addr) );
   addr.sin_family = AF_INET;
   if( name != NULL ) {
      hp = gethostbyname( name );
      if( hp == NULL ) {
         herror( "gethostbyname" );
         close( sock );
         return( -1 );
      }
      memcpy( &addr.sin_addr, hp->h_addr, hp->h_length );
   } else {
      addr.sin_addr.s_addr = INADDR_ANY;
   }
   addr.sin_port = htons( port );

   if( bind( sock, (struct sockaddr *)&addr, sizeof(addr) ) == -1 ) {
      perror( "bind" );
      close( sock );
      return( -1 );
   }

   return( sock );
}

