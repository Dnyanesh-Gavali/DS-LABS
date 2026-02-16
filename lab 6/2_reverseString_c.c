#include<stdio.h>
#include<stdlib.h>
struct node {
    char data;
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

int isFull(struct node *s) {
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n==NULL) {
        return 1;
    }

    else {
        return 0;
    }
}

void push(struct node *s, char c) {
    struct node * n = (struct node *)malloc(sizeof(struct node));

    if (n==NULL) {
        printf("\nStack overflow\n");
        return;
    }

    else {
        n->data = c;
        n->next = top;
        top = n;
    }
}

void pop(struct node *s) {
    if (isEmpty(s)) {
        printf("\nStack Underflow\n");
        return;
    }

    else {
        struct node * n = top;
        top = top->next;
        free(n);
    }
}

char peek(struct node *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return '\0';   
    }
    else {
        return top->data;
    }
}

int main() {
    char str[100];
    fgets(str, 100, stdin);
    int size = 0;
    for(int i=0; str[i] != '\0'; i++) {
        size++;
    }

    for (int i =0;i<size; i++) {
        push(top, str[i]);
    }

    for (int i=0; i<size; i++) {
        printf("%c", peek(top));
        pop(top);
    }

}