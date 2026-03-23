#include<stdio.h>
#define size 100

struct Queue {
    int queue[size];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q) {
    return (q->front == -1);
}

int isFull(struct Queue *q) {
    return (q->rear == size - 1);
}

void enqueue(struct Queue *q, int data) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear++;
    q->queue[q->rear] = data;
}

int dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    int data = q->queue[q->front];
    
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } 
    else {
        q->front++;
    }
    printf("Deleted element: %d\n", data);
    return data;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }
    printf("\n");
}

int main() {
    struct Queue q;
    initializeQueue(&q);
    int choice, val;
    while (1) {
        printf("\n\n----Count Menu----\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Count\n");
        printf("4. Exit\n");

        printf("Enter a choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the value to enter: ");
            scanf("%d", &val);
            enqueue(&q, val);
            break;

        case 2:
            dequeue(&q);
            break;
        
        case 3:
            int count = q.rear - q.front + 1;
            printf("\nThe count of elements is %d", count);
            break;
        
        case 4:
            exit(0);
            break;
        
        default:
            printf("\nEntered wrong choice");
            break;
        }
    }
    int count = q.rear - q.front+1;
    printf("%d", count);
}