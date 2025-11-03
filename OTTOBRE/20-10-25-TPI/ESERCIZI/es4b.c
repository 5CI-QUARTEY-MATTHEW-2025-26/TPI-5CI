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
    FILE *fptr;
    FILE *fptr2;

    fptr = fopen("somma1.txt", "w");
    fptr2 = fopen("somma2.txt", "w");
    fptr = fopen("somma1.txt", "r");
    fptr2 = fopen("somma2.txt", "r");

    
    
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
        fprintf(fptr, somma);
        
    }
    
    if(primofiglio > 0){
        int secondofiglio = fork();
        if(secondofiglio == 0){
            int somma = 0;
            for(n = meta; n < i; n++){
                somma = somma + myArray[n];
            };
            fprintf(fptr2, somma);
            exit(0);
        } 

        if(secondofiglio > 0 ){
            int valore1;
            fscanf(fptr,"%s", &valore1);
            int valore2;
            fscanf(fptr2,"%s", &valore2);
            int s = valore1 + valore2;
            printf("\n la somma dei due valori letti è: %d\n ", s);
        }
    }

    fclose(fptr);
    fclose(fptr2);
    return 0;
}