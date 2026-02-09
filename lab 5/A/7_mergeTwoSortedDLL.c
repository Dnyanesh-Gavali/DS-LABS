#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};

struct node * createDLL(int n) {
    struct node * head = NULL, * tail =NULL, *new;

    int data;
    for (int i = 0; i<n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data to enter at node %d:  ", i+1);
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;
        new->prev = NULL;

        if (head == NULL) {
            head = tail = new;
        }
        else {
            tail->next = new;
            new->prev = tail;
            tail = new;
        }

    }

    return head;
}

struct node * merge(struct node * l1, struct node * l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    struct node *head = NULL, *tail = NULL;

    while (l1 && l2) {
        struct node *temp;

        if (l1->data < l2->data) {
            temp = l1;
            l1 = l1->next;
        } else {
            temp = l2;
            l2 = l2->next;
        }

        temp->prev = tail;
        temp->next = NULL;

        if (!head)
            head = tail = temp;
        else {
            tail->next = temp;
            tail = temp;
        }
    }

    if (l1) {
        tail->next = l1;
        l1->prev = tail;
    }
    if (l2) {
        tail->next = l2;
        l2->prev = tail;
    }

    return head;
}

void display(struct node *s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);

        s=s->next;
    }
    printf("NULL");
}

int main() {
    int n;
    printf("Enter the number of nodes i n l1: ");
    scanf("%d", &n);

    int m;
    printf("Enter the number of nodes i n l2: ");
    scanf("%d", &m);

    struct node * head;
    struct node * l1 = createDLL(n);
    struct node * l2 = createDLL(m);

    head = merge(l1, l2);
    display(head);
}