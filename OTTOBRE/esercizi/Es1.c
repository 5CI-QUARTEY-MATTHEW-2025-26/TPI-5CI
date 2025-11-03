#include <stdio.h>

int main() {
    int ArraySize;
    printf("hi, how many numbers?\n");
    scanf("%d", &ArraySize );

    int myArray[ArraySize];
    int a, b;
    int i;
    for(i = 0; i < ArraySize; i++) {
            printf("Enter number %d: ", i + 1);
            scanf("%d", &myArray[i]);
    }
    if(ArraySize == 1){
        printf("Only one number, min and max are the same: ");
        printf("%d\n" , myArray[0]);
    } else {
            b = myArray[0];
            a = b;
        for (i = 1; i < ArraySize; i++) {
            if (myArray[i] < a) {
                a = myArray[i];
            }
            if (myArray[i] > b) {
                b = myArray[i];
            }
        }

        printf("min = %d, max = %d\n", a, b);
    }
   
    
    return 0;
}