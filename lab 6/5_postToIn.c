#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct node {
    char data[100];  
    struct node * next;
};

struct node * top = NULL;

int isEmpty(struct node * s) {
    return top == NULL;
}

void push(struct node *s, char *c) {
    struct node * n = (struct node *)malloc(sizeof(struct node));

    if (n == NULL) {
        printf("\nStack overflow\n");
        return;
    }

    strcpy(n->data, c);  
    n->next = top;
    top = n;
}

void pop(struct node *s) {
    if (isEmpty(s)) {
        printf("\nStack Underflow\n");
        return;
    }

    struct node * n = top;
    top = top->next;
    free(n);
}

char* peek(struct node *s) {
    if (isEmpty(s)) {
        printf("Stack is Empty\n");
        return NULL;   
    }
    return top->data;
}

int main() {
    char s[] = "AB-DE+F*/";

    int size = strlen(s);

    for (int i = 0; i < size; i++) {

        if (isalnum(s[i])) {  
            char operand[2];
            operand[0] = s[i];
            operand[1] = '\0';
            push(top, operand);
        } 
        else {
            char t1[100], t2[100], temp[100];

            strcpy(t1, peek(top));
            pop(top);

            strcpy(t2, peek(top));
            pop(top);

            sprintf(temp, "(%s\t%c\t%s)", t2, s[i], t1);

            push(top, temp);
        }
    }

    printf("Infix Expression: %s\n", peek(top));

    return 0;
}