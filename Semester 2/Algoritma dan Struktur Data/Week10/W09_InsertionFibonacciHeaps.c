#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node {
    struct node* parent;
    struct node* child;
    struct node* left;
    struct node* right;
    int key;
} node;

void insertion(node** mini, int val, int* no_of_nodes) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->key = val;
    new_node->parent = NULL;
    new_node->child = NULL;
    new_node->left = new_node;
    new_node->right = new_node;
    if ((*mini) != NULL) {
        new_node->left = (*mini)->left;
        (*mini)->left->right = new_node;
        (*mini)->left = new_node;
        new_node->right = (*mini);
        if (new_node->key < (*mini)->key) {
            (*mini) = new_node;
        }
    }
    else {
        (*mini) = new_node;
        (*mini)->left = (*mini);
        (*mini)->right = (*mini);
    }
    (*no_of_nodes)++;
}

void display(node* mini, int no_of_nodes) {
    node* ptr = mini;
    if (ptr == NULL) {
        printf("The Heap is Empty\n");
    }
    else {
        printf("The root nodes of Heap are: \n");
        do {
            printf("%d ", ptr->key);
            ptr = ptr->right;
            if(ptr != mini)
                printf("--> ");
        } while (ptr != mini);
        printf("\nThe heap has %d nodes\n", no_of_nodes);
    }
}


void find_min(node* mini) {
    if (mini == NULL) {
        printf("The Heap is Empty\n");
    }
    else {
        printf("min of heap is: %d\n", mini->key);
    }
}

int main() {
    node* mini = NULL;
    int no_of_nodes = 0;
    insertion(&mini, 4, &no_of_nodes);
    insertion(&mini, 3, &no_of_nodes);
    insertion(&mini, 7, &no_of_nodes);
    insertion(&mini, 5, &no_of_nodes);
    insertion(&mini, 2, &no_of_nodes);
    insertion(&mini, 1, &no_of_nodes);
    insertion(&mini, 10, &no_of_nodes);
    display(mini, no_of_nodes);
    find_min(mini);
    return 0;
}
