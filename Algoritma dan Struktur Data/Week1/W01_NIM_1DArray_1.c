#include <stdio.h>

int main () {
    int randomNumber[5] = {10,24,234,345,234};
    int i;

    printf("Isi Array adalah\n");
    for (i=0; i<5; i++) {
        printf("Random Number [%d] = %d\n", i, randomNumber[i]);
    }

    printf("\n");
    randomNumber[3] = 1000;

    for (i=0; i<5; i++) {
        printf("Random Number [%d] = %d\n", i, randomNumber[i]);
    }

    return 0;
}