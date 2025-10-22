#include <stdio.h>

int main(){
    int myArray[3][3];
    int myArray2[3][3];
    int myArrayFinale[3][3];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Dammi il numero in posizione del primo array [%d][%d]: ",i,j);
            scanf("%d", &myArray[i][j]);
        }
    };

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("Dammi il numero in posizione del secondo array [%d][%d]: ",i,j);
            scanf("%d", &myArray2[i][j]);
        }
    };

    
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("%d\n" , &myArrayFinale[i][j]);
        }
    }
    return 0;
}