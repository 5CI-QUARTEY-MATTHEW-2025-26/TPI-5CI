#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

int main() {
    char *myfifoserver = "/tmp/A_to_B";
    char *myfifoclient = "/tmp/B_to_A";

    mkfifo(myfifoserver, 0666);
    mkfifo(myfifoclient, 0666);

    int server = open(myfifoserver, O_RDONLY);
    int client = open(myfifoclient, O_WRONLY);

    char buffer[BUFSIZ];
    int n = read(server, buffer, sizeof(buffer));
    buffer[n] = '\0';

    printf("Riceve: %s\n", buffer);

    char *mess = "pong";
    write(client, mess, strlen(mess) + 1);

    close(server);
    close(client);
    return 0;
}
