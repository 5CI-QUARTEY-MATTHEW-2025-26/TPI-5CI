#include <stdio.h>
#include <stdbool.h>

int main(){

    int myArray[10];
    int i;
    int n;
    bool primo;
    for(i = 0; i < 10; i++) {
        printf("Dammi il numero %d: ",i+1);
        scanf("%d", &myArray[i]);
    };
    for(i = 0; i < 10; i++){
        n = myArray[i];

        if (n <= 1) {
            continue;
        }

        primo = true;

        for (int f = 2; f <= n / f; f++) {
            if (n % f == 0) {
                primo = false;
                break;
            }
        }

        if (primo) {
            printf("%d, è un numero primo \n", myArray[i]);
        }
        
    }
    return 0;
}