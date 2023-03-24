#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Symbol{
    char data;
    struct Symbol *next;
}Symbol;

Symbol *head = NULL;

void push(char data){
    Symbol *node = (Symbol*)malloc(sizeof(Symbol));
    node->data = data;
    node->next = head;
    head = node;
}

void pop(){
    if (head == NULL){
        return;
    }
    else{
        Symbol *trash = head;
        head = head->next;
        free(trash);
    }
}

int match(char a, char b){
    if(a == '(' && b == ')'){
        return 1;
    }
    else if(a == '{' && b == '}'){
        return 1;
    }
    else if(a == '[' && b == ']'){
        return 1;
    }
    return 0;
}

int check(char input[]){
    for (int i = 0; i < strlen(input); i++){
        if (input[i] == '(' || input[i] == '[' || input[i] == '{'){
            push(input[i]);
        }
        else if (input[i] == ')' || input[i] == ']' || input[i] == '}'){
            if (head == NULL){
                return 0;
            }
            else if (!match(head->data, input[i])){
                return 0;
            }
            else{
                pop();
            }
        }
        else{
            return 0;
        }
    }
    if (head == NULL)
        return 1;
    else
        return 0;
}

int main(){
    char input[100];

        printf("Input (){}[] (-1 to exit): ");
        scanf("%[^\n]", input);fflush(stdin);

        if(check(input)){
            printf("Valid Parenthesis Expression.\n");
        }else{
            printf("Invalid Parenthesis Expression.\n");
        }
}
