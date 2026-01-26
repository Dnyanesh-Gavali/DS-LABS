#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * head = NULL;
struct node * tail = NULL;

void insertTail(int data) {
    struct node * new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    if (head == NULL) {
        head = tail = new;
    }
    else {
        tail->next = new;
        tail = new;
    }
}

void printNode() {
    if (head == NULL) {
        printf("Node does not exist");
    }
    else if (head->next==NULL) {
        printf("Only ONE NODE EXIST: %d", head->data);
    }

    struct node * temp = head;

    int i=1;
    while (temp!=NULL) {
        printf("%d -> ", temp->data);
        temp= temp->next;
        i++;
    }
    printf("NULL");
}

int main() {
    insertTail(10);
    insertTail(20);
    insertTail(30);

    printf("Before: ");

    printNode();

    insertTail(40);
    printf("\nAfter: ");

    printNode();
}