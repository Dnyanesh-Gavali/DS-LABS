#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * top = NULL;
struct node * front = NULL;
struct node * rear = NULL;

int isEmpty(struct node *s) {
    if (front == rear) {
        return 1;
    }
    return 0;
}
void Enqueue(int x) {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    if (newNode != NULL) {
        if (rear == NULL && front == NULL) {
            front = rear = newNode;
        }

        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    else {
        printf("No memory");
        return;
    }
}

void Dequeue() {
    struct node * del = front;

    if (front == rear) {
        rear = front = NULL;
        return;
    }

    else {
        front = front->next;
    }
    free(del);
}

void display(struct node * s) {
    struct node *temp = front;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int peek(struct node * s) {
    if (front ==  NULL) {
        printf("Queue Empty");
        return -1;
    }
    return front->data;
}

//stack methods

void push(struct node * s, int val) {
    struct node * new = (struct node *) malloc(sizeof(struct node));
    new->data = val;
    new->next = top;
    top = new;
}

int pop(struct node *s) {
    if (top == NULL)
        return -1;

    struct node *temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    Enqueue(10);
    Enqueue(20);
    Enqueue(30);
    Enqueue(40);

    printf("Original Queue:\n");
    display(top);

    while (front != NULL) {
        push(top, peek(top));
        Dequeue();
    }

    while (top != NULL) {
        Enqueue(pop(top));  // enqueue stored value
    }

    printf("\nReversed Queue:\n");
    display(top);

}
