/*
    4) Prendere in input un array di n interi
   Creare 2 figli:
     - il primo calcola e stampa la somma dei primi n/2 elementi 
	 - il secondo calcola e stampa la somma degli elementi restanti
	 - il padre aspetta che i figli terminino 
	 
VARIANTE 4.b: utilizzare due file 'somma1.txt' e 'somma2.txt' e sfruttarli
              per calcolare la somma totale nel padre e mostrarla in output

VARIANTE 4.c: utilizzare delle pipe per permettere una comunicazione 'diretta' tra padre e figlio

*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    int i;
    printf("Dammi la capienza del array:");
    scanf("%d", &i);
    int myArray[i];
    int n;
    int meta = i/2;

    for(n = 0; n < i; n++) {
        printf("Dammi il numero %d: ",n+1);
        scanf("%d", &myArray[n]);
    };
    

    int pidpadre = getpid();

    int primofiglio = fork();
  
    if(primofiglio == 0){
        int somma = 0;
        for(n = 0; n < meta; n++){
            somma = somma + myArray[n];
        };
        printf("\n la somma dei primi %d numeri è %d", meta, somma);
    
    }

    if(primofiglio > 0){
        int secondofiglio = fork();
        if(secondofiglio == 0){
            int somma = 0;
            for(n = meta; n < i; n++){
                somma = somma + myArray[n];
            };
            if(i % 2 == 0)
                printf("\n la somma dei ultimi %d numeri è %d \n", meta, somma);
            else 
                 printf("\n la somma dei ultimi %d numeri è %d \n", meta + 1, somma);
        }
    } 
    return 0;
}