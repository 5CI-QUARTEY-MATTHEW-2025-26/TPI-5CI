#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#define buffer 16
int main(){
    int mkfifo ( const char * pathname , mode_t mode ) ;
    
    int fd_w = open (" nome_fifo ", O_WRONLY ); 

    int fd_r = open (" nome_fifo ", O_RDONLY );


    write (fd_w , buffer , sizeof ( buffer )) ;

    read (fd_r , buffer , sizeof ( buffer ) );
    
    close(mkfifo);
    unlink(mkfifo);
}
