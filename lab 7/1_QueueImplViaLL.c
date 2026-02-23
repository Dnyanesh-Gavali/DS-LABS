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
void Enqueue(struct node * s, int x) {
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

void Dequeue(struct node * s) {
    struct node * del = front;

    if (front == rear) {
        rear = front = NULL;
        return;
    }

    else {
        front = front->next;
        free(del);
    }
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

int main() {
    int choice, value;

     while (1) {
        printf("\n\n--- Queue ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Emptyness\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &value);
                Enqueue(top, value);
                break;

            case 2:
                Dequeue(top);
                break;

            case 3:
                printf("The element at top is %d" , peek(top));
                break;
            
            case 4:
                if (!isEmpty(top)) {
                    printf("The queue is not empty...");
                }

                else {
                    printf("Queue empty");
                }
                break;

            case 5:
                display(top);
                break;

            case 6:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
}