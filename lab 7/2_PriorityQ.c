#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    int priority;
    struct node * next;
};

struct node * top = NULL;
struct node * front = NULL;
struct node * rear = NULL;

void push(struct node * s, int data, int priority) {
    struct node * newNode = (struct node *)malloc(sizeof(struct node));

    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (newNode != NULL) {
        if (rear ==  NULL && front == NULL) {
            front = rear = newNode;
            return;
        }

        if (priority > front->priority) {
            newNode->next = front;
            front = newNode;
            return;
        }

        struct node * temp = front;

        while(temp->next != NULL && temp->next->priority >= priority) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            rear = newNode;
        }
    }
}

void pop(struct node * s) {
    if (front == NULL) {
        printf("Queue Underflow");
        return;
    }

    struct node * temp = front;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    free(temp);
}

void peek(struct node * s) {
    if (front == NULL) {
        printf("Priority Queue is Empty\n");
        return;
    }

    printf("Top Element: %d (Priority: %d)\n",
           front->data, front->priority);
}

void display(struct node * s) {
    if (front == NULL) {
       printf("Queue is Empty");
       return;
    }

    struct node * temp = front;

    printf("\n");
    while (temp!=NULL) {
        printf("%d (%d) ->", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL");
    
}
int main() {
    int choice, data, priority;

    while (1) {
        printf("\n\n--- Priority Queue ---\n");
        printf("1. Push (Insert)\n");
        printf("2. Pop (Delete)\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter priority: ");
                scanf("%d", &priority);
                push(top, data, priority);
                break;

            case 2:
                pop(top);
                break;

            case 4:
                display(top);
                break;

            case 3:
                peek(top);
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}