#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node * createCLL(int n) {
    struct node * head = NULL, * tail = NULL, * new;

    int data;
    for (int i = 0; i<n; i++) {
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

struct node * insert(struct node * s, int data) {
    struct node * temp = s;
    struct node * dat = (struct node *)malloc(sizeof(struct node));

    dat->next = NULL;
    dat->data = data;
    if (data < s->data) {
        while (temp->next != s) {
            temp = temp->next;   
        }
        temp->next = dat;
        dat->next = s;
        return dat;  
    }

    while (temp->next != s && temp->next->data < data) {
        temp = temp->next;
    }

    dat->next = temp->next;
    temp->next = dat;

    return s;
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

    displayCLL(&head);
    int data;
    printf("\nEnter data to be inserted: ");
    scanf("%d", &data);

    head = insert(head, data);
    displayCLL(&head);

}