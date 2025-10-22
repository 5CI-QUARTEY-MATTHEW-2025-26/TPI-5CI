#include <stdio.h>

int main(){
    int NDF;
    printf("dimmi il numero da fattorizzare:\n");
    scanf("%d", &NDF);

    int i  = 1;
    int primo = NDF;
    int fattoriale = 1;
    while(i <= NDF){
        fattoriale = fattoriale * (NDF - (primo - i));
        i++;
    };

    printf("%d\n", fattoriale);


    return 0;
}