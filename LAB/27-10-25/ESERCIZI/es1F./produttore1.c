#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#include <string.h>
#include <errno.h>
#define myfifo  "/tmp/dati_fifo"
#define messaggio "ciao sono matto"
int main(){
    mkfifo(myfifo, 0666);
    char mess[64];
    int fd_w = open(myfifo, O_WRONLY);

    for(int i = 0 ; i < 10; i++){
        snprintf(mess, sizeof(mess), "%s%d", messaggio, i);
        write(fd_w, mess, sizeof(mess));
        sleep(1);
    }

    close(fd_w);
    unlink(myfifo);
    return 0;
}