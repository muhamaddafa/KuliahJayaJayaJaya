#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


typedef struct Node{
    int key, height;
    struct Node *left, *right;
} Node;

int height (struct Node *N){
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b){
    return (a > b)? a: b;
}

Node *newNode(int item) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    temp->height = 1;
    return temp;
}

Node *leftRotate(Node *x){
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;

    return y;
}

Node *rightRotate(Node *y){
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;

    return x;
}

int getBalance (Node *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node *insert(Node *node, int key){
    if (node == NULL) return(newNode(key));

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;


    node->height = 1 + max(height(node->left),
                           height(node->right));


    int balance = getBalance(node);

    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key){
        node->right = rightRotate (node->right);
        return leftRotate(node);
    }

    return node;

}

void printInorder (Node *node){
    if (node == NULL) return;
    printInorder (node->left);
    printf("%d ", node->key);
    printInorder (node->right);
}

void printPreorder (Node *node){
    if (node == NULL) return;
    printf("%d ", node->key);
    printPreorder (node->left);
    printPreorder (node->right);
}

void printPostorder (Node *node){
    if (node == NULL) return;
    printPostorder (node->left);
    printPostorder (node->right);
    printf("%d ", node->key);
}

Node* minValueNode(Node* node){
    Node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

Node* deleteNode(Node* root, int key){

    if (root == NULL)
        return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);

    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    else {
        if (root->left == NULL){
            Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            Node* temp = root->left;
            free(root);
            return temp;
        }

        Node* temp = minValueNode(root->right);
        root->key = temp->key;
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

int main(){
    Node *root = NULL;

    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Base Tree\n");
    printf("Preorder  : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder : "); printPostorder(root); printf("\n\n");

    printf("Deleting node 20\n");
    deleteNode(root, 20);
    printf("Preorder  : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder : "); printPostorder(root); printf("\n\n");

    printf("Deleting node 30\n");
    deleteNode(root, 30);
    printf("Preorder  : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder : "); printPostorder(root); printf("\n\n");

    printf("Deleting node 70\n");
    deleteNode(root, 70);
    printf("Preorder  : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder : "); printPostorder(root); printf("\n\n");

    return 0;
}
