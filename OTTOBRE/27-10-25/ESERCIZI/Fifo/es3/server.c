
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(){

    const char* myfifo = "/tmp/chat_server";
    mkfifo(myfifo, 0666);


    char buffer[4092];
    int fd_r = open (myfifo, O_RDONLY ); 

    int n = read(fd_r, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        close(fd_r);
        return 1;
    }
    buffer[n > 0 ? n : 0] = "";

    printf("%s\n", buffer);

}