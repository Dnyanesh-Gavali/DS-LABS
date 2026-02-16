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


int priority(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }

    else if(c == '*' || c=='/') {
        return 2;
    }

    else if (c== '^') {
        return 3;
    }

    else {
        return 0;
    }
}

int main() {
    char s[100];
    fgets(s, 100, stdin);

    int i = 0;
    while(s[i] != '\0') {
        i++;
    }
    char ans[i+1];
    i = 0;

    int j=0;
    while (s[i] != '\0') {
        if (s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' || s[i] >= '0' && s[i] <= '9') {
            ans[j++] = s[i];
        }

        else if (s[i] == '(') {
            push(top, s[i]);
        }

        else if(s[i] == ')') {
            while(!isEmpty(top) && peek(top) != '(') {
                ans[j++] = peek(top);
                pop(top);
            }

            pop(top);
        }

        else {
            while (!isEmpty(top) && priority(s[i]) <= priority(peek(top))) {
                ans[j++] = peek(top);

                pop(top);
            }

            push(top, s[i]);
        }

        i++;
    }

    while (!isEmpty(top)) {
        ans[j++] = peek(top);
        pop(top);
    }

    ans[j] = '\0';
    for (int i=0; ans[i] != '\0'; i++) {
        printf("%c\t", ans[i]);
    }
}