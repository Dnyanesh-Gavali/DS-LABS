#ifndef BT_H
#define BT_H

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node *right;
};

struct node * createNode(int value);
struct node * buildTree();

#ifdef CREATE_BT

struct node * createNode(int value) {
    if (value == -1) return NULL;

    struct node * new1 = (struct node *)malloc(sizeof(struct node));
    new1->data = value;
    new1->right = NULL;
    new1->left = NULL;

    return new1;
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

#endif
#endif
