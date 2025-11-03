#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
#define FIFO_PATH  "/tmp/dati_fifo"

int main(){
    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    char buffer[64];
    int n = read(fd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        close(fd);
        return 1;
    }
    buffer[n > 0 ? n : 0] = "";

    printf("stampo1 : %s\n", buffer);

    close(fd);
    return 0;
}