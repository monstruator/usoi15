
#include <sys/dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <string.h>

int OpenDEVnb( char *name )
{
   int fd;
   int one = 1;

   fd = open( name, O_RDWR );
   if( fd == -1 ) {
      perror( name );
      return( -1 );
   }

   if( ioctl( fd, FIONBIO, &one ) == -1 ) {
      perror( "ioctl(FIONBIO)" );
      close( fd );
      return( -1 );
   }

   return( fd );
}

