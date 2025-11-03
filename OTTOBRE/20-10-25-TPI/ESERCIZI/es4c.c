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
    
    

  int p[2];
  if(pipe(p) < 0){
    return 0;
  }

  int  pid1 = fork();
  if(pid1 < 0){
    return 0;
  }

  if(pid1 == 0){
    int somma = 0;
    for(n = 0; n < meta; n++){
      somma += myArray[n];
    }
    close(p[0]);
    if(write(p[1], &somma, sizeof(somma)) != sizeof(somma)){
      perror("write primo figlio");
    }
    close(p[1]);
    return 0;
  }


  int  pid2 = fork();
  if(pid2 < 0){
    return 0;
  }

  if(pid2 == 0){
    int somma = 0;
    for(n = meta; n < i; n++){
      somma += myArray[n];
    }
    close(p[0]);
    if(write(p[1], &somma, sizeof(somma)) != sizeof(somma)){
      perror("write secondo figlio");
    }
    close(p[1]);
    return 0;
  }

 
  int somma1 = 0, somma2 = 0;
  int r;

  r = read(p[0], &somma1, sizeof(somma1));
  r = read(p[0], &somma2, sizeof(somma2));

  close(p[0]);

  waitpid(pid1, NULL, 0);
  waitpid(pid2, NULL, 0);

  printf("Somma primi %d numeri = %d\n", meta, somma1);
  if(i % 2 == 0)
    printf("Somma ultimi %d numeri = %d\n", meta, somma2);
  else
    printf("Somma ultimi %d numeri = %d\n", meta + 1, somma2);

  printf("Somma totale = %d\n", somma1 + somma2);
    return 0;
}