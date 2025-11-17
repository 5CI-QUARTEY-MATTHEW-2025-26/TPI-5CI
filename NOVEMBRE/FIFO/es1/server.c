/**   Server Persistente con Multipli Client (Invio di Identificatore)

Scrivere `server.c` e `client.c` per implementare un server persistente che gestisce richieste da più client.

Il Server crea una FIFO nota chiamata `"/tmp/richieste_fifo"` con permessi $0666$[cite: 110].
 Il Server entra in un ciclo infinito di lettura, bloccandosi in attesa di dati.
 Il Client si connette, ottiene il proprio PID (`getpid()`) e lo invia al server, seguito da una stringa di richiesta (es. "DAMMI L'ORA").
 Il Server legge i dati, stampa un messaggio come "Richiesta da PID [X]: [STRINGA]" e continua il suo ciclo.
 Il Server deve implementare un meccanismo di terminazione: se riceve la stringa "QUIT" come messaggio, chiude la FIFO e la rimuove con `unlink()`[cite: 46, 48].
 Istruzioni per l'alunno: Eseguire il Server e poi lanciare più istanze del Client in terminali separati. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO_PATH "/tmp/richieste_fifo"
#define BUF_SIZE 256

int main() {
    if (mkfifo(FIFO_PATH, 0666) == -1) {
        perror("mkfifo");
    }

    printf("Server avviato. In attesa di richieste...\n");

    int fd = open(FIFO_PATH, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(1);
    }

    char buffer[BUF_SIZE];

    while (1) {
        int n = read(fd, buffer, sizeof(buffer) - 1);

        if (n > 0) {
            buffer[n] = '\0';
            char *spazio = strchr(buffer, ' ');
            if (!spazio) continue;

            *spazio = '\0';
            char *pid_str = buffer;
            char *msg = spazio + 1;

            printf("Richiesta da PID [%s]: %s\n", pid_str, msg);

            if (strcmp(msg, "QUIT") == 0) {
                printf("Ricevuto QUIT. Chiudo.\n");
                close(fd);
                unlink(FIFO_PATH);
                exit(0);
            }
        }
    }

    return 0;
}

