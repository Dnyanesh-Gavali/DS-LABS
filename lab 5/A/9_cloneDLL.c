#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
    struct node *random;
};

struct node* cloneList(struct node *s) {
    struct node *temp = s;

    // Step 1: Insert clone nodes
    while (temp != NULL) {
        struct node *clone = (struct node *)malloc(sizeof(struct node));
        clone->data = temp->data;

        clone->next = temp->next;
        clone->prev = temp;
        clone->random = NULL;

        if (temp->next != NULL)
            temp->next->prev = clone;

        temp->next = clone;
        temp = clone->next;
    }

    temp = s;

    // Step 2: Set random pointers
    while (temp != NULL) {
        struct node *clone = temp->next;
        if (temp->random != NULL)
            clone->random = temp->random->next;
        temp = clone->next;
    }

    temp = s;

    // Step 3: Separate the lists
    struct node *dummy = (struct node *)malloc(sizeof(struct node));
    dummy->next = NULL;
    struct node *res = dummy;

    while (temp != NULL) {
        struct node *clone = temp->next;

        res->next = clone;
        clone->prev = (res == dummy) ? NULL : res;
        res = clone;

        temp->next = clone->next;
        if (temp->next != NULL)
            temp->next->prev = temp;

        temp = temp->next;
    }

    struct node *clonedHead = dummy->next;
    free(dummy);
    return clonedHead;
}

void display(struct node *s) {
    while (s != NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL\n");
}

void displayRandom(struct node *s) {
    while (s != NULL) {
        printf("%d -> ", s->data);
        s = s->random;
    }
    printf("NULL\n");
}

int main() {
    // Creating nodes
    struct node *head   = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third  = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *tail   = (struct node *)malloc(sizeof(struct node));

    // Data
    head->data = 10;
    second->data = 20;
    third->data = 10;
    fourth->data = 20;
    tail->data = 10;

    // Next pointers
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = tail;
    tail->next = NULL;

    // Prev pointers
    head->prev = NULL;
    second->prev = head;
    third->prev = second;
    fourth->prev = third;
    tail->prev = fourth;

    // Random pointers
    head->random = fourth;
    second->random = NULL;
    third->random = head;
    fourth->random = second;
    tail->random = third;

    printf("Original list (next):\n");
    display(head);

    printf("Original list (random):\n");
    displayRandom(head);

    struct node *clonedHead = cloneList(head);

    printf("\nCloned list (next):\n");
    display(clonedHead);

    printf("Cloned list (random):\n");
    displayRandom(clonedHead);

    return 0;
}
