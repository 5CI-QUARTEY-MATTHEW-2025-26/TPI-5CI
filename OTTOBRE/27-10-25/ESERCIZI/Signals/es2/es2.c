#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int signum) {
    static int counter = 0;
    counter++;

    printf("Segnale Utente 1 ricevuto!\n");
}

int main() {
    signal(SIGUSR1, sigint_handler);
    
    int p = getpid();
    printf("%d\n", p);
    
    int ret = 0;
    ret = pause();
    printf("Pause returned with %d\n", ret);

    return 0;
}
