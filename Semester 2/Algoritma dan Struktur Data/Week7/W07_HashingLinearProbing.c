#include <stdio.h>
#include <stdbool.h>

void hashFunction(int input, int hashTable[])
{
    int hash;
    bool check = false;
    hash = input % 10;
    int temp = hash;
    while(1){
        if(hashTable[temp]==0){
            printf("Inserting data to Hash Table\n");
            hashTable[temp] = input;
            break;
        }
        temp++;
        if(hash==temp){
            printf("Hash Table Full\n");
            break;
        }
        if(temp > 9){
            temp = 0;
        }
    }
}


int main(){
    int hashT[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int inputKey;

    while(1){
        printf("Input a number : ");
        scanf("%d", &inputKey);
        printf("Processing in Hash Function\n");

        hashFunction(inputKey, hashT);

        int i;
        printf("Current Hash Table: ");
        for(i = 0; i<10; i++){
            printf("[%d]", hashT[i]);
        }
        printf("\n\n");
    }
    return 0;
}
