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
        printf("Enter the data to enter:  ");
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

struct node * swap(struct node * s, int start, int end) {
    struct node *t1 = s, *t2;

    int diff = end - start, count = 0;
    while (count<start-1) {
        t1 = t1->next;
        count++;
    }

    t2 = t1;
    count =0;
    while (count < diff) {
        t2 = t2->next;
        count++;
    }

    // fix previous links
    if (t1->prev != NULL) {
        t1->prev->next = t2;
    }

    if (t2->prev != NULL) {
        t2->prev->next = t1;
    }

    if (t1->next != NULL) {
        t1->next->prev = t2;
    }
    if (t2->next != NULL) {
        t2->next->prev = t1;
    }

    // swap prev pointers
    struct node* temp;
    temp = t1->prev;
    t1->prev = t2->prev;
    t2->prev = temp;

    // swap next pointers
    temp = t1->next;
    t1->next = t2->next;
    t2->next = temp;

    // update head if needed
    if (start == 1) s = t2;
    else if (end ==1) s = t1;
    return s;
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
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createDLL(n);

    int pos1, pos2;
    printf("Enter the positions to swap: ");
    scanf("%d %d", &pos1, &pos2);
    head = swap(head, pos1, pos2);
    display(head);
}