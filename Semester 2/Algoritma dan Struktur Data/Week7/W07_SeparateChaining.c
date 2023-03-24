#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <windows.h>

typedef struct numList{
    int number;
    struct numList *next;
}numList;

void insertToChain(int key, numList **head){
    numList *ptr =  (*head);
    numList *node = (numList*)malloc(sizeof(numList));
    node->number = key;
    node->next = NULL;
    if(*head == NULL){
        *head = node;
    }
    else{
        while(ptr->next != NULL){
            ptr = ptr->next;
        }
        ptr->next = node;
    }
}

int main(){
    numList *HashT[10];
    int i;
    for(i = 0; i < 10; i++){
        HashT[i] = NULL;
    }
    while(1){
        system("cls");
        for(i = 0; i < 10; i++){
            numList *ptr = HashT[i];
            printf("[%d]->", i);
            while(ptr!= NULL){
                printf("(%d)", ptr->number);
                ptr = ptr->next;
            }
            printf("\n");
        }
        int inputKey;
        scanf("%d", &inputKey);
        insertToChain(inputKey,&HashT[inputKey%10]);
    }
    return 0;
}
