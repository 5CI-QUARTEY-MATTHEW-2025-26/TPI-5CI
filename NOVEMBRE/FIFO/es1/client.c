#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_PATH "/tmp/richieste_fifo"

int main(int n, char *x[]) {
    if (n < 2) {
        fprintf(stderr, "Uso: %s <  >\n", x[0]);
        exit(1);
    }

    int fd = open(FIFO_PATH, O_WRONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    pid_t pid = getpid();

    char buffer[256];
    snprintf(buffer, sizeof(buffer), "%d %s", pid, x[1]);

    write(fd, buffer, strlen(buffer));

    close(fd);
    return 0;
}

