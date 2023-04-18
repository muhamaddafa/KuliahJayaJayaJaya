#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right;
} node;

void preorder(struct node *root)
{
    if(root!=NULL){
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node *root)
{
    if(root!=NULL){
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
void postorder(struct node *root)
{
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->key);
    }
}

node *newNode(int item)
{
    node *temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

node *insert(node *node, int key)
{
    if(node==NULL)
        return newNode(key);
    if(key < node->key)
        node->left = insert(node->left, key);
    else if(key > node->key)
        node->right = insert(node->right, key);
    return node;
}

int main()
{
    node *root = NULL;
    root = insert(root, 50);

    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("PreOrder    : ");
    preorder(root); printf("\n");
    printf("InOrder     : ");
    inorder(root); printf("\n");
    printf("PostOrder   : ");
    postorder(root); printf("\n");
    return 0;
}