/**
    2) Prendere in input un numero intero n.
   Il processo deve creare n figli (hint: usare un ciclo for)
     - ogni figlio stampa il suo pid
	 - il padre DEVE attendere la terminazione di tutti i figli




 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int input;
    int pidpadre = getpid();
    int i;
    

    printf("Dammi un numero: ");
    scanf("%d", &input);

    pid_t pid[input];

    for(i = 0; i < input; i++){
        pid[i] = fork();
        if (pid[i] == 0){
            pid_t pidfiglio = getpid();
            printf("\n pid figlio: %d\n", (int)pidfiglio );
            exit(0);
        }
    } 

   
    for (i = 0; i < input; i++) {
        waitpid(pid[i], NULL, 0);
    }
    return 0;

}