#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <string.h>

int main() {
    const char* myfifo = "/tmp/chat_server";
    mkfifo(myfifo, 0666);

    int fd_w = open(myfifo, O_WRONLY);
    if (fd_w == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    char name[100];
   
    while (1) {
        printf("Enter one string - 'exit' to finish: ");
        fgets(name, sizeof(name), stdin);

        if (strcmp(name, "exit\n") == 0)
            break;

        write(fd_w, name, strlen(name));
    }

    close(fd_w);
    return 0;
}

