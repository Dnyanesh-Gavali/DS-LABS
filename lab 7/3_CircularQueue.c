#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node * top = NULL;
struct node * front = NULL;
struct node * rear = NULL;

void Enqueue(struct node * s, int x) {
    struct node * new = (struct node *)malloc(sizeof(struct node));
    if (new == NULL) {
        printf("No memory allocated");
        return;
    }

    new->data = x;
    new->next = NULL;
    if (front == NULL && rear == NULL) {

        front = rear = new;
        rear->next = front;
    }

    else {
        rear->next = new;
        rear = new;
        rear->next = front;
    }
}

void Dequeue(struct node * s) {
    struct node * del = front;

    if (front == rear) {
        rear = front = NULL;
        return;
    }

    else {
        front = front->next;
        rear->next = front;
        free(del);
    }
}

void display(struct node * s) {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }

    struct node *temp = front;

    while (temp->next != front) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("%d -> Back At Front\n", temp->data);
}

int getFront(struct node * s) {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    return front->data;
}

int getRear(struct node * s) {
    if (rear == NULL) {
        printf("Queue is Empty\n");
        return -1;
    }
    return rear->data;
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Circular Queue---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. getFront\n");
        printf("4. getRear\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                Enqueue(NULL, value);
                break;

            case 2:
                if (front == NULL) {
                    printf("Queue Underflow\n");
                } 
                else {
                    Dequeue(NULL);
                    printf("Element deleted successfully\n");
                }
                break;
            
            case 3:
                if (front == NULL) {
                    printf("Queue Underflow\n");
                } 

                else {
                    printf("The element at front is %d", front->data);
                }
                break;

            case 4: 
                printf("The element at rear is %d", rear->data);
                break;

            case 5:
                display(NULL);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}