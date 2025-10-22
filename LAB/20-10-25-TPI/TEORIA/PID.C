#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int pidpadre = getpid();
    int Valore = fork();
    //int Valore = 1;
    

    if( Valore == 0){
        int  pidfiglio = getpid();
        printf("\n pid figlio: %d \n pid padre %d", pidfiglio , pidpadre); 
    }else{
        printf("%d\n", pidpadre);
    }

}