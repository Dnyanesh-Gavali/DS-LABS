#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * right;
    struct node * left;
};

struct node * createNode(int data) {
    if(data == -1) return NULL;

    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->right = NULL;
    new->left = NULL;

    return new;
}

struct node * insert(struct node * root, int data) {
    if (root == NULL) {return createNode(data);}

    if (data < root->data) {
        root->left = insert(root->left, data);
    }

    else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node * buildTree() {
    struct node * root = NULL;
    int data;

    printf("Enter values one by one. Enter -1 to finish.\n\n");

    while (1) {
        printf("Enter data: ");
        scanf("%d", &data);

        if (data == -1) {
            break;
        }
        root = insert(root, data);
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

void print(struct node * root) {
 
    if (root == NULL) {
        return;
    }

    printf("parent node: %d\n", root->data);

    if (root->left != NULL) {
        printf("left to parent node: %d\n", root->left->data);
    } else {
        printf("left to parent node: NULL\n");
    }

    
    if (root->right != NULL) {
        printf("right to parent node: %d\n", root->right->data);
    } else {
        printf("right to parent node: NULL\n");
    }
    
    printf("\n\n");

    print(root->left);
    print(root->right);
}

int main() {
    struct node* root = NULL;

    printf("Start building the tree:\n");
    root = buildTree();

    printf("\nThe BST is: \n");
    print(root);

    printf("\nInorder Traversal of the BST: ");
    if (root == NULL) {
        printf("Tree is empty.\n");
    } 
    else {
        inorder(root);
        printf("\n");
    }

}