#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
    char data;
    struct node * prev;
    struct node * next;
};

struct node * front = NULL;
struct node * rear = NULL;

void insertRear(char x) {
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    new->prev = rear;

    if (rear == NULL)
        front = rear = new;
    else {
        rear->next = new;
        rear = new;
    }
}

void insertFront(char x) {
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = x;
    new->next = NULL;
    new->prev = front;

    if (front == NULL)
        front = rear = new;
    else {
        front->next = new;
        front = new;
    }
}

void deleteFront() {
    if (front == NULL) {
        printf("Deque is Empty\n");
        return;
    }

    struct node* temp = front;

    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
        front->prev = NULL;
    }

    free(temp);
}

void deleteRear() {
    if (rear == NULL) {
        return;
    }

    struct node * temp = rear;
    if (front == rear) {
        front = rear = NULL;
    }

    else {
        rear = rear->prev;
        rear->next =NULL;
    }

    free(temp);
}

void display() {
    struct node* temp = front;

    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

int isPalindrome() {
    struct node* left = front;
    struct node* right = rear;

    while (left && right && left != right && left->prev != right) {
        if (left->data != right->data)
            return 0;

        left = left->next;
        right = right->prev;
    }

    return 1;
}

int main() {
    char str[100];
    printf("Enter string: ");
    scanf("%s", str);

    for (int i = 0; str[i] != '\0'; i++)
        insertFront(str[i]);

    if (isPalindrome())
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}