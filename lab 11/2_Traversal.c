#include<stdio.h>
#include<stdio.h>

#define CREATE_BT
#include "createBT.h"

void displayInorder(struct node* root) {
    if (root == NULL) return;
    
    displayInorder(root->left);
    printf("%d ", root->data);
    displayInorder(root->right);
}

void PreOrder(struct node * root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}

void PostOrder(struct node * root) {
    if (root == NULL) return;

    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}
int main() {
    struct node* root = NULL;

    printf("Start building the tree:\n");
    root = buildTree();

    printf("\nInorder Traversal of the Linked Tree:\n");
    if (root == NULL) {
        printf("Tree is empty.\n");
    } else {
        displayInorder(root);
        printf("\n");
    }

    printf("\nPreOrder Traversal of the Linked Tree:\n");
    if (root == NULL) {
        printf("Tree is empty.\n");
    } else {
        PreOrder(root);
        printf("\n");
    }

    printf("\nPostder Traversal of the Linked Tree:\n");
    if (root == NULL) {
        printf("Tree is empty.\n");
    } else {
        PostOrder(root);
        printf("\n");
    }
}