#include<stdio.h>
#include<stdlib.h>
int top = -1;
void push(int x, int *arr, int n) {
    if (top == n-1) {
        printf("Stack Overflow");
        return;
    }

    else {
        top++;
        arr[top] = x;
    }
}

int pop(int *arr, int n) {
    if (top==-1) {
        printf("Underflow");
        return NULL;
    }
    else {
        int y = arr[top];
        top--;
        return y;
    }
}

int peek(int *arr, int n) {
    if (top >= n-1) {
        printf("Stack Overflow");
        return;
    }
    else if (top==-1) {
        printf("Underflow");
        return NULL;
    }
    else { 
        return arr[top];
    }
}

void isEmpty(int *arr, int n) {
    if (top==-1) {
        printf("The stack is empty");
    }
    else {
        printf("The stack is not empty");
    }
}

void isFull(int *arr, int n) {
    if (top==n-1) {
        printf("\nThe stack is full");
    }
    else {
        printf("\nThe stack is not full");
    }
}
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int *arr = (int *)malloc(n * sizeof(int));

    isEmpty(arr, n);

    push(10, arr, n);
    printf("\nThe element pushed 10");
    push(30, arr, n);
    printf("\nThe element pushed 30");
    push(40, arr, n);
    printf("\nThe element pushed 40");
    
    isFull(arr, n);

    printf("\n\nThe element pop: %d", pop(arr, n));
    printf("\nThe element pop: %d", pop(arr, n));
    printf("\nThe element at top: %d", peek(arr, n));
}