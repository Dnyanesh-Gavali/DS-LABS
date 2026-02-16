#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
};

struct node * top = NULL;

int isEmpty(struct node * s) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct node * s, int x) {
    struct node * n = (struct node *)malloc(sizeof(struct node));

    if (n==NULL) {
        printf("Stack Overflow");
        return;
    }

    else {
        n->data = x;
        n->next = top;
        top= n;
    }
}

int pop(struct node * s) {
    struct node * n = (struct node *)malloc(sizeof(struct node));

    if (isEmpty(s)) {
        printf("Stack Underflow");
        return -1;
    }

    else {
        n = top;
        top = top->next;
        int x = n->data;
        free(n);
        return x;
    }
}

int peek(struct node * s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return -1;   
    }

    else {
        return top->data;
    }
}

int main() {
    push(top, 10);
    push(top, 20);
    push(top, 30);

    printf("The stack is: \n");
    struct node * temp = top;

    while (temp!=NULL) {
        printf("%d ->", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
    printf("The element popped: %d", pop(top));   

}