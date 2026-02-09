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

struct node *reverse (struct node * s) {
    struct node * temp = s, *prev=NULL, *front;
    while(temp->next != s) {
        front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }

    front = temp->next;
    temp->next = prev;

    s->next = temp;
    return temp;
}

void displayCLL(struct node **head) {
    struct node *temp = *head;
    if (*head == NULL) return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != *head);

    printf("%d(back at head)\n", temp->data);
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createCLL(n);

    head = reverse(head);

    displayCLL(&head);
}