#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node * createCLL(int n) {
    struct node * head = NULL, * tail = NULL, * new;
    int data;

    for (int i=0; i<n; i++) {
        new = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;

        if (head == NULL) {
            head = tail = new;
            new->next = head;
        }
        else {
            tail->next = new;
            tail = new;
            tail->next = head;
        }
    }
    return head;
}

void halfSplit(struct node * s, struct node **first, struct node **second) {
    struct node * t1 = s, *t2;
    struct node * temp = s;

    int count = 0;
    while (temp->next!=s) {
        temp = temp->next;
        count++;
    }

    count = count/2;
    int i=0;
    while (i<count) {
        i++;
        t1 = t1->next;
    }

    *first = s;
    *second = t1->next;

    t1->next = *first;

    t2 = *second;
    while(t2->next !=s) {
        t2 = t2->next;
    }

    t2->next = *second;
}

void displayCLL(struct node **head) {
    struct node *temp = *head;
    if (*head == NULL) return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != *head);

    printf("%d\n", temp->data);
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createCLL(n);

    struct node *firstHalf, *secondHalf;

    halfSplit(head, &firstHalf, &secondHalf);

    displayCLL(&firstHalf);

    printf("\n");
    
    displayCLL(&secondHalf);
}