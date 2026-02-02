#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * random;
};

struct node* cloneList(struct node *s) {
    struct node * temp = s;
    
    
    //inserting clone nodes between
    while (temp!=NULL) {
        struct node * clone = (struct node *)malloc(sizeof(struct node));
        clone->data = temp->data;
        clone->next  = temp->next;
        temp->next = clone;
        temp = temp->next->next;
    }

    temp = s;

    //connecting random pointers of clone
    while(temp!=NULL) {
        struct node * clone = temp->next;
        if (temp->random != NULL) {
            clone->random = temp->random->next;
        }
        else {
            clone->random = NULL;
        }

        temp = temp->next->next;
    }

    temp = s;

    struct node * dummy = (struct node *)malloc(sizeof(struct node));
    dummy->next = NULL;

    struct node * res = dummy;
    res->next = NULL;
    //connect next pointers of clone
    while(temp!=NULL) {
        struct node * clone = temp->next;
        res->next = clone;
        res = clone;

        temp->next = clone->next;
        temp = temp->next;
    }
    return dummy->next;
}

void display(struct node * s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}

void displayRandom(struct node * s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->random;
    }
    printf("NULL");
}


int main() {
    struct node * head = (struct node *)malloc(sizeof(struct node));
    struct node * second = (struct node *)malloc(sizeof(struct node));
    struct node * third = (struct node *)malloc(sizeof(struct node));
    struct node * fourth = (struct node *)malloc(sizeof(struct node));
    struct node * tail = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 20;
    third->data = 10;
    fourth->data = 20;
    tail->data = 10;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;
    tail->next = NULL;

    head->random = fourth;
    second->random = NULL;
    third->random = head;
    fourth->random = second;
    tail->random = third;

    printf("Original list (next pointers):\n");
    display(head);
    printf("\n");
    displayRandom(head);
    printf("\n\n");

    struct node * clonedHead = cloneList(head);

    printf("Cloned list (next pointers):\n");
    display(clonedHead);
    printf("\n");
    printf("Cloned list (random pointers):\n");
    displayRandom(clonedHead);
    printf("\n");

    return 0;
}