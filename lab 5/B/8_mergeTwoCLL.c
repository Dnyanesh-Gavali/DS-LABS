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

struct node* merge(struct node* l1, struct node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    
    struct node* last1 = l1;
    while (last1->next != l1) {
        last1 = last1->next;
    }
    last1->next = NULL;

    struct node* last2 = l2;
    while (last2->next != l2) {
        last2 = last2->next;
    }
    last2->next = NULL;


    struct node* head = NULL;
    struct node* tail = NULL;

    if (l1->data <= l2->data) {
        head = tail = l1;
        l1 = l1->next;
    } else {
        head = tail = l2;
        l2 = l2->next;
    }


    while (l1 && l2) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    tail->next = (l1) ? l1 : l2;

    while (tail->next) {
        tail = tail->next;
    }
    tail->next = head;

    return head;
}

void displayCLL(struct node *head) {
    struct node *temp = head;

    if (head == NULL)
        return;

    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp!= head);

    printf("(back at head)\n");
}

int main() {
    int n;
    printf("Enter the number of nodes in list1: ");
    scanf("%d", &n);
    struct node * l1 = createCLL(n);

    int m;
    printf("\nEnter the number of nodes in list2: ");
    scanf("%d", &m);
    struct node * l2 = createCLL(m);

    printf("The list1: ");
    displayCLL(l1);

    printf("\nThe list2: ");
    displayCLL(l2);

    l1 = merge(l1, l2);
    displayCLL(l1);
}