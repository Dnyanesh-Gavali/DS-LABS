#include<stdio.h>
#include<stdlib.h>

struct node {
    char data;     
    struct node *next;
};

struct node *top = NULL;

int isEmpty(struct node* s) {
    if (top == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull(struct node *s) {
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL) {
        return 1;
    }
    else {
        return 0;
    }
}

void push(struct node *s, char x) {   
    struct node *n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL) {
        printf("Stack Overflow\n");
    }
    else {
        n->data = x;
        n->next = top;
        top = n;
    }
}

char pop(struct node *s) {   
    if (isEmpty(s)) {
        printf("Stack Underflow\n");
        return '\0';  
    }
    else {
        struct node *n = top;
        top = top->next;
        char x = n->data;
        free(n);
        return x;
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
    printf("Enter an expression: ");
    char s[100];
    scanf("%s", s);

    struct node * st = (struct node *)malloc(sizeof(struct node));

    int flag = 0;

    for (int i =0; s[i] != '\0'; i++) {
        if (s[i] == '{'  || s[i] == '(' || s[i] == '[') {
            push(st, s[i]);
        }

        else if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (isEmpty(st)) {
                flag = 1;
                break;
            }

            char c = peek(st);
            char x = pop(st);

            if (s[i] == ')' && c != '(' || s[i] == '}' && c != '{' || s[i] == '}' && c != '{') {
                flag = 1;
            }
        }
    }

    if(isEmpty(st) != 1) {
        flag = 1;
    }

    if (flag ==1) {
        printf("\n Invalid \n");
    }
    else {
        printf("\n Valid \n");
    }
}

