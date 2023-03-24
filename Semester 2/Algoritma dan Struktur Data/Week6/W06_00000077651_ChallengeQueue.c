#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Number{
    int num;
    struct Number *next;
}Number;

void push(Number **head, Number **tail, int angka){
    Number *data = (Number*) malloc(sizeof(Number));
    data->num = angka;
    data->next = NULL;

    if(isEmpty(*head)){
        *head = *tail = data;
    }else{
        (*tail)->next = data;
        *tail = data;
    }
}


void pop(Number **head){
    if(isEmpty(*head)){
        printf("Nothing to dequeue. Queue already empty\n");
        return;
    }
    Number *trash = *head;
    *head = trash->next;
    free(trash);
}

int isEmpty(Number *head){
    if(head == NULL){
        return 1;
    }
    return 0;
}

Number *front(Number *head){
    if(head == NULL){
        return NULL;
    }
    return head;
}

void display(Number *head){
    Number *temp;
    temp = head;
    printf("Isi Queue: ");
    while(temp != NULL){
        printf("%d ", temp->num);
        temp = temp->next;
    }
    printf("\n");
}

int main(){
    Number *head, *tail;
    head = tail = NULL;
    int angka, i;

    while(1){
        printf("Input Angka: ");
        scanf("%d", &angka);
        if(angka == 0){
            break;
        }
        if(isEmpty(head)){
            for(i = 1;i <= angka;i++){
                push(&head, &tail, angka);
            }
            display(head);
        }else{
            if(angka < front(head)->num){
                for(i = 1;i <= angka;i++){
                    pop(&head);
                }
            }
            else{
                for(i = 1;i <= front(head)->num;i++){
                    push(&head, &tail, angka);
                }
            }
            display(head);
        }
    }
}

