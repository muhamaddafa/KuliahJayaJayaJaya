#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//Deklarasi Struct untuk Linked List dalam Tree
typedef struct Node
{
    int key;
    struct node *left, *right;
}Node;

//Function yang digunakan untuk membuat node baru
Node *newNode(int item)
{
    Node *temp = (Node*) malloc(sizeof(Node));
    temp -> key = item;
    temp -> left = temp -> right = NULL;
    return temp;
}

// Function yang digunakan untuk memasukan node baru ke dalam Tree
Node *insert(Node *node, int key)
{
    // Jika Tree kosong
    // Atau ketika berada pada node kosong (left / right)
    if (node == NULL)
        return newNode(key);
    
    // Jika key kurang dari key pada node sementara
    if (key < node -> key)
        // Turun ke left dari node sementara
        node -> left = insert(node -> left, key);

    else if (key > node -> key)
        //Turun ke right dari node sementara
        node -> right = insert(node -> right, key);

    // return node jika sudah berhasil insert
    return node;
}

// Function untuk mencetak tree secara pre-order
void printPreorder(Node *node)
{
    if (node == NULL)
        return;

    printf("%d ", node->key);
    printPreorder(node->left);
    printPreorder(node->right);
}

// Function untuk mencetak tree secara in-order
void printInorder(Node *node)
{
    if (node == NULL)
        return;

    printInorder(node->left);
    printf("%d ", node->key);
    printInorder(node->right);
}

// Function untuk mencetak tree secara post-order
void printPostorder(Node *node)
{
    if (node == NULL)
        return;

    printPostorder(node->left);
    printPostorder(node->right);
    printf("%d ", node->key);
}

// Function untuk mencari nilai minimum pada tree
Node *minValueNode(Node *node)
{
    Node *current = node;
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

//Function untuk menghapus Node
Node* deleteNode(Node* root, int key)
{
    //base case
    if (root == NULL)
        return root;

    // Kalau key lebih kecil dari root, pindah ke kiri
    if (key < root -> key)
        root -> left = deleteNode(root -> left, key);

    // Kalau key lebih kecil dari root, pindah ke kanan
    else if (key > root -> key)
        root -> right = deleteNode(root -> right, key);

    // Kalau key sama dengan root
    else
    {
        // Node dengan 1 anak / tanpa anak
        if (root -> left == NULL)
        {
            Node* temp = root -> right;
            free(root);
            return temp;
        }
        else if (root -> right == NULL)
        {
            Node* temp = root -> left;
            free(root);
            return temp;
        }

        // Node dengan 2 anak
        // ambil key terkecil di bawahnya
        Node* temp = minValueNode(root -> right);

        // Copy nilai terkecilnya ke root
        root -> key = temp -> key;

        // Delete nilai terkecilnya ke root
        root -> right = deleteNode(root -> right, temp -> key);
    }
    return root;
}

int main()
{
  Node *root = NULL;

    root = insert(root, 50);
    insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Base Tree\n");
    printf("Preorder   : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder   : "); printPostorder(root); printf("\n\n");
    
    printf("Deleting node 20\n");
    deleteNode(root, 20);
    printf("Preorder   : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder   : "); printPostorder(root); printf("\n\n");
    
    printf("Deleting node 30\n");
    deleteNode(root, 30);
    printf("Preorder   : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder   : "); printPostorder(root); printf("\n\n");
    
    printf("Deleting node 70\n");
    deleteNode(root, 70);
    printf("Preorder   : "); printPreorder(root); printf("\n");
    printf("Inorder   : "); printInorder(root); printf("\n");
    printf("Postorder   : "); printPostorder(root); printf("\n\n");
    
    return 0;
}
