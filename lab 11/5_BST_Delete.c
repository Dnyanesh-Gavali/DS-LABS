#include<stdio.h>
#include<stdio.h>

#define BST_CREATION
#include "createBST.h"

struct node * successor(struct node * curr) {
    while(curr->left != NULL) {
        curr = curr->left;
    }

    return curr;
}

struct node * delete(struct node * root, int val) {
    if (root == NULL) return NULL;

    if (val < root->data) {
        root->left = delete(root->left, val);
    } 
    else if (val > root->data) {
        root->right = delete(root->right, val);
    }

    else {
        if (root->left == NULL) {
            struct node * temp = root->right;
            free(root);
            return temp;
        }

        else if (root->right == NULL) {
            struct node * temp = root->left; 
            free(root);
            return temp;
        }

        struct node * temp = successor(root->right);
        root->data = temp->data;

        root->right = delete(root->right, temp->data);
    }

    return root;
}

void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main() {
    struct node * root = NULL;
    
    printf("Start building the tree:\n");
    root = buildTree();

    int keyToDelete;
    printf("Enter the value to delete: ");
    scanf("%d", &keyToDelete);

    root = delete(root, keyToDelete);

    printf("\nIn-order traversal after deletion:\n");
    inorder(root);
    printf("\n");
}