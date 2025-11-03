
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

struct record {
    int numb;
};

int main() {
    const char* myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);

    char mess[12];
    int fd_w = open(myfifo, O_WRONLY);
    struct record io;

    for (int i = 0; i < 5; i++) {
        io.numb = rand();
        snprintf(mess, sizeof(mess), "%d", io.numb);
        write(fd_w, mess, sizeof(mess));
        sleep(1);
    }

    close(fd_w);
    unlink(myfifo);
    return 0;
}
