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

void sortCLL(struct node * s) {
    struct node * t1 = s, * t2;

    while (t1->next != s) {
        t2 = s;

        while(t2->next!=s) {

            if (t2->data > t2->next->data) {
                int t = t2->data;
                t2->data = t2->next->data;
                t2->next->data = t;
            }

            t2 = t2->next;
        }

        t1 = t1->next;
    }
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

    sortCLL(head);
    displayCLL(&head);
}