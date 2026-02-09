#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};

struct node* createDLL(int n) {
    if (n <= 0) return NULL;

    struct node *head = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return head;
}


struct node* bubbleSortDLL(struct node* s) {
    if (s == NULL) return s;

    int swapped = 1;
    struct node *ptr;

    while (swapped) {
        swapped = 0;
        ptr = s;

        while (ptr->next != NULL) {
            if (ptr->data > ptr->next->data) {
                int temp = ptr->data;
                ptr->data = ptr->next->data;
                ptr->next->data = temp;
                swapped = 1;
            }
            ptr = ptr->next;
        }
    }

    return s;
}


void pair(struct node * s, int sum) {
    struct node * right;
    struct node * temp=s;
    struct node * left=s;
    
    bubbleSortDLL(s);
    while (temp->next!=NULL) {
        temp = temp->next;
    }

    right = temp;

    while (left->data < right->data) {
        if (right->data + left->data > sum) {
            right = right->prev;
        }

        else if (right->data + left->data < sum) {
            left = left->next;
        }

        else {
            printf("\npair found: (%d, %d)", left->data, right->data);
            left = left->next;
            right = right->prev;
        }
    }
}
int main() {
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("\n");

    struct node * head = createDLL(n);


    int sum;
    printf("Enter the sum: ");
    scanf("%d", &sum);
    printf("\n");
    pair(head, sum);
}