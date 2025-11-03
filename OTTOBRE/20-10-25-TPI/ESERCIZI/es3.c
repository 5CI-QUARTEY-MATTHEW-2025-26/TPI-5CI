/**
    3) Lanciare un processo che genera due figli (A e B):
     - A a sua volta genera il figlio A1
	 - B genera i figli B1 e B2
   Ogni processo deve mostrare in output una cosa del tipo: "Sono B2, figlio di B"
N.B.: Bisogna far terminare i processi in modo ordinato utilizzando le opportune wait()

 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){

    int pidpadre = getpid();
    int A = fork();
    if(A == 0){
        int A1 = fork();
        if(A1 == 0){
            printf("\n sono A1 e sono figlio di A \n");
            exit(0);
        };
        printf("\n Ciao sono A e sono figlio di %d \n", pidpadre);
        exit(0);
    };
    if(A > 0){
        int B = fork();
        if(B == 0){
            int B1 = fork();
            if(B1 == 0){
                printf("\n Ciao sono B1 e sono figlio di B \n");
                exit(0);
            }; 
            printf("\n sono B e sono figlio di %d \n", pidpadre);
            exit(0);
        
        };
    }
    

    return 0;
}