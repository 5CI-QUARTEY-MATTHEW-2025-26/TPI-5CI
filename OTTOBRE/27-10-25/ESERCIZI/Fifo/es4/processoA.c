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

    int server = open(myfifoserver, O_WRONLY);
    int client = open(myfifoclient, O_RDONLY);

    char *mess = "ping";
    write(server, mess, strlen(mess) + 1);

    char buffer[BUFSIZ];
    int n = read(client, buffer, sizeof(buffer));
    buffer[n] = '\0';

    printf("Received from B: %s\n", buffer);

    close(server);
    close(client);
    return 0;
}
