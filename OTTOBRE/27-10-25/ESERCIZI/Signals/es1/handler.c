#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    static int counter = 0;
    counter++;

    if (counter < 3) {
        printf("Non mi puoi terminare subito! Ho bisogno di pulire.\n");
    } else {
        printf("Addio! Ora posso terminare.\n");
        exit(0);
    }
}

int main() {
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("Premi CTRL+C per interrompere.\n");
        sleep(2);
    }

    return 0;
}
