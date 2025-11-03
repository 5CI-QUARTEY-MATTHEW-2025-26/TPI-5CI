/** 
  1) Lanciare un processo che genera un figlio:
     - il padre stampa 'Sono il padre'
	 - il figlio stampa 'Sono il figlio'
	 - il padre DEVE attendere la terminazione del figlio
**/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(){
    int pidpadre = getpid();

    pid_t Valore = fork();
    //int Valore = 1;
    
    if( Valore == 0){
        int  pidfiglio = getpid();
        printf("\n pid figlio: %d", pidfiglio ); 
    }
    else if(Valore > 0)
    {
        printf("\n sono il padre: %d", pidpadre ); 

    }
    wait(NULL);
    return 0;

}