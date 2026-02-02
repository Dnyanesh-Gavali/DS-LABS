#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node * createList(int n) {
    struct node * head = NULL, *temp = NULL;

    int data;
    for (int i =0; i<n; i++) {
        struct node * new = malloc(sizeof(struct node));

        printf("Enter data in sorted order: ");
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;

        if (head==NULL) {
            head = temp = new;
        }
        else {
            temp->next = new;
            temp = new;
        }
    }
    return head;
}

struct node * merge(struct node * l1, struct node * l2) {
    if (l1 == NULL && l2 == NULL) {
        printf("The node doesn't exist");
        return NULL;
    }

    struct node newNode;
    struct node * result = &newNode;
    newNode.next = NULL;
    while (l1 != NULL && l2!=NULL) {
        if (l1->data < l2->data) {
            result->next = l1;
            result = l1;
            l1 = l1->next;
        }
        else {
            result->next = l2;
            result = l2;
            l2 = l2->next;
        }
    }

    if (l1 != NULL) result->next = l1;
    else result->next = l2;

    return newNode.next;
}

void display(struct node * s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }

    printf("NULL");
}
int main() {
    printf("Enter data for 1st ll (5 elemnt):");
    struct node * first = createList(5);

    printf("\nEnter data for 1st ll (5 elemnt):");

    struct node * second = createList(5);

    printf("The merged ll: ");

    first = merge(first, second);

    display(first);
    
}