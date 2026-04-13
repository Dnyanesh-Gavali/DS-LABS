#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node *right;
};

struct node * createNode(int value) {
    if (value == -1) return NULL;

    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = value;
    new->right = NULL;
    new->left = NULL;

    return new;
}

struct node * buildTree() {
    int data;

    printf("Enter data (-1 for NULL): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    struct node * root = createNode(data);

    printf("Entering left child of %d: ", data);
    root->left = buildTree();

    printf("Entering right child of %d: ", data);
    root->right = buildTree();

    return root;
}

void displayInorder(struct node* root) {
    if (root == NULL) return;
    
    displayInorder(root->left);
    printf("%d ", root->data);
    displayInorder(root->right);
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
}