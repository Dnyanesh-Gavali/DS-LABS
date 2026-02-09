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

struct node * removeK(struct node * s, int k) {
    struct  node * temp = s, *prev = NULL, *del;
    int count=1;
    while (temp->next != s) {
        if (count == k) {
            del = temp;
            prev->next = temp->next;
            temp =temp->next;
            free(del);
            count = 1;
        }
        else {
            prev = temp;
            temp = temp->next;
            count++;
        }
    }

    return s;
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

    int k;
    printf("\nEnter the number of jumps: ");
    scanf("%d", &k);
    head = removeK(head, k);
    displayCLL(&head);
}