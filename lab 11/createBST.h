#ifndef BST_H
#define BST_H

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node *right;
};

struct node * createNew(int data);
struct node * insert(struct node * root, int data);
struct node * buildTree();

#ifdef BST_CREATION

struct node * createNew(int data) {
    if (data == -1) return NULL;

    struct node * newNode = (struct node * )malloc(sizeof(struct node));
    newNode->data= data;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
}

struct node * insert(struct node * root, int data) {
    if (root == NULL) {
        return createNew(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    if (data >= root->data) {
        root->right = insert(root->right, data);
    }

    return root;
}

struct node * buildTree() {
    struct node * root = NULL;

    printf("Data entry... (-1 to terminate)\n");
    int data;

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
#endif
#endif