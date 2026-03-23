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

void reverseQueue() {
    if (front == NULL)
        return;

    int val = peek(front);   
    Dequeue();               

    reverseQueue();       

    Enqueue(val);   
}

int main() {
    int choice, val;
    while (1) {
        printf("\n\n----Reverse using recursion Menu----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Reverse Queue\n");
        printf("4. Display\n");
        printf("5. Exit\n");


        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to enter: ");
            scanf("%d", &val);
            Enqueue(val);
            break;

        case 2:
            Dequeue();
            break;
        
        case 3:
            reverseQueue();
            break;
        
        case 4:
            display(top);
            break;

        case 5:
            exit(0);
            break;
        
        default:
            printf("\nEntered wrong choice");
            break;
        }
    }
}
