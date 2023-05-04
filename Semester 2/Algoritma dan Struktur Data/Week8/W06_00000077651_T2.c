#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef struct Node{
    char key;
    struct Node *left, *right;
}Node;

Node *newNode(int item){
    Node *temp = (Node*) malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

Node *insertSymbol(Node *root, char item, int curr){
    if(curr == 0){
        root = newNode(item);
        return root;
    }
    else if(curr == 1){
        if (root->left == NULL){
            root->left = newNode(item);
        }
        else{
            root->left->key = item;
        }
        return root->left;
    }
    else if(curr == 2){
        if (root->right == NULL){
            root->right = newNode(item);
        }
        else{
            root->right->key = item;
        }
        return root->right;
    }
    return NULL;
}

Node *insertLetter(Node *root, char item, int curr){
    if(curr == 0){
        root->left->left = newNode(item);
        return root->left->left;
    }
    else if(curr == 1){
        root->left->right = newNode(item);
        return root->left->right;
    }
    else if(curr == 2){
        root->right->left = newNode(item);
        return root->right->left;
    }
    else if(curr == 3){
        root->right->right = newNode(item);
        return root->right->right;
    }
    return NULL;
}

void inorder(Node *root){
    if (root != NULL){
        if(root->key == '*' || root->key == '/' || root->key == '+' || root->key == '-'){
            printf("(");
        }
        inorder(root->left);
        printf("%c", root->key);
        inorder(root->right);
        if(root->key == '*' || root->key == '/' || root->key == '+' || root->key == '-'){
            printf(")");
        }
    }
}

int main(){
    char expressionA[7] = "-*+abcd";
    char expressionB[7] = "*+ab+cd";
    char expressionC[7] = "+/ab/cd";
    Node *rootA, *rootB, *rootC;
    rootA = rootB = rootC = NULL;
    int currA = 0, currB = 0, currC = 0, tempA = 0, tempB = 0, tempC = 0;
    int i;

    //Expression A
    for (i = 0;i < 7;i++){
        if (strchr("+-*/", expressionA[i])){
            if (rootA == NULL){
                rootA = insertSymbol(rootA, expressionA[i], currA);
            }
            else{
                insertSymbol(rootA, expressionA[i], currA);
            }
            currA++;
        }
    }

    for (i = 0; i < 7;i++){
        if (strchr("abcd", expressionA[i])){
            insertLetter(rootA, expressionA[i], tempA);
            tempA++;
        }
    }
    if (rootA == NULL){
        printf("Error has occured\n");
    }
    else{
        printf("The correct mathematic expression of -*+abcd is : ");
        inorder(rootA);
        printf("\n");
    }

    //Expression B
    for (i = 0;i < 7;i++){
        if (strchr("+-*/", expressionB[i])){
            if (rootB == NULL){
                rootB = insertSymbol(rootB, expressionB[i], currB);
            }
            else{
                insertSymbol(rootB, expressionB[i], currB);
            }
            currB++;
        }
    }

    for (i = 0; i < 7;i++){
        if (strchr("abcd", expressionB[i])){
            insertLetter(rootB, expressionB[i], tempB);
            tempB++;
        }
    }
    if (rootB == NULL){
        printf("Error has occured\n");
    }
    else{
        printf("The correct mathematic expression of *+ab+cd is : ");
        inorder(rootB);
        printf("\n");
    }

    //Expression C
    for (i = 0;i < 7;i++){
        if (strchr("+-*/", expressionC[i])){
            if (rootC == NULL){
                rootC = insertSymbol(rootC, expressionC[i], currC);
            }
            else{
                insertSymbol(rootC, expressionC[i], currC);
            }
            currC++;
        }
    }

    for (i = 0; i < 7;i++){
        if (strchr("abcd", expressionC[i])){
            insertLetter(rootC, expressionC[i], tempC);
            tempC++;
        }
    }
    if (rootC == NULL){
        printf("Error has occured\n");
    }
    else{
        printf("The correct mathematic expression of +/ab/cd is : ");
        inorder(rootC);
        printf("\n");
    }
    return 0;
}
