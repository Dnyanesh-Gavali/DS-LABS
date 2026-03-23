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

void minMax() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }
    
    struct node * temp = front;
    int min = temp->data;
    int max = temp->data;

    while (temp!=NULL) {
        if (temp->data > max) {
            max = temp->data;
        }

        if (temp->data < min) {
            min = temp->data;
        }

        temp = temp->next;
    }

    printf("\nMax = %d", max);
    printf("\nMin = %d", min);
} 

int main() {
    int choice, val;
    while (1) {
        printf("\n\n----MinMax Menu----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Get Min Max\n");
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
            minMax();
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
