#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * top = NULL;

int min = 1101;

int isEmpty(struct node *s) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct node * s) {
    struct node * n = (struct node *)malloc(sizeof(struct node));

    if (n==NULL) {
        return 1;
    }

    else {
        return 0;
    }
}


void push(struct node * s, int x) {
    struct node * n = (struct node *)malloc(sizeof(struct node));

    if (n==NULL) {
        return;
    }

    if (isEmpty(s)) {
        min = x;
        n->data = x;
    }

    else {
        if (x>min) n->data = x;

        else{
            n->data = 2*x - min;
            min = x;
        }
    }

    n->next = top;
    top = n;
}

void pop(struct node *s){ 
    if (isEmpty(s)) {
        return;
    }

    struct node * temp = top;

    int n = temp->data;
    top = temp->next;

    if (n<min) {
        min = 2*min - n;
    }

    free(temp);
}

int peek(struct node *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow");
        return -1;
    }

    if(top->data > min) {
        return top->data;
    }
    else {
        return min; 
    }
}

int getMiN() {
    return min;
}

int main() {

    push(top, 6);
    push(top, 2);
    push(top, 9);

    printf("Minimum is %d\n", getMiN());

    pop(top);
    printf("Minimum is %d\n", getMiN());

    pop(top);
    push(top, 1);
    printf("Minimum is %d\n", getMiN());

    return 0;
}