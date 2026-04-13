#include<stdio.h>
#include<stdlib.h>

#define BST_CREATION
#include "createBST.h"


struct node * search(struct node * root, int val) {
    if (root  == NULL) {
        return NULL;
    }

    if (root->data == val) return root;
    if(root->data > val) {
        return search(root->left, val);
    }

    else return search(root->right, val);
}

int main() {
    struct node * root = NULL;
    
     printf("Start building the tree:\n");
    root = buildTree();

    int key;
    printf("Enter the value to search: ");
    scanf("%d", &key);

    struct node * result = search(root, key);
    
    if (result != NULL) {
        printf("\nFound!!!");
    }

    else {
        printf("\nNot Found");
    }
}