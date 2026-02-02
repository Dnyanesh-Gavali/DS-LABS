#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * child;
};
struct nodeSingle {
    int data;
    struct nodeSingle * next;
};

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

struct nodeSingle * convert(int arr[], int n) {
    struct nodeSingle *head = (struct nodeSingle*)malloc(sizeof(struct nodeSingle));
    head->data = arr[0];
    head->next = NULL;
    struct nodeSingle * temp = head;

    for (int i=1; i<n; i++) {
        struct nodeSingle * new = (struct nodeSingle*)malloc(sizeof(struct nodeSingle));
        new->data = arr[i];
        new->next = NULL;
        temp->next = new;
        temp = new;
    }
    return head;
}

struct nodeSingle * webToArr(struct node * s) {
    int arr[100];
    struct node * temp = s;
    int size = 0;

    while (temp!=NULL) {
        struct node * temp2 = temp;
        while (temp2!=NULL) {
            arr[size++] = temp2->data;
            temp2 = temp2->child;
        }
        temp = temp->next;
    }

    bubbleSort(arr, size);

    return convert(arr, size);
}

void printSingle(struct nodeSingle *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    // Creating nodes manually to match diagram

    struct node *head = (struct node*)malloc(sizeof(struct node));
    head->data = 5;

    struct node *n10 = (struct node*)malloc(sizeof(struct node));
    n10->data = 10;

    struct node *n19 = (struct node*)malloc(sizeof(struct node));
    n19->data = 19;

    struct node *n28 = (struct node*)malloc(sizeof(struct node));
    n28->data = 28;


    head->next = n10;
    n10->next = n19;
    n19->next = n28;
    n28->next = NULL;

    // Vertical lists
    head->child = (struct node*)malloc(sizeof(struct node));
    head->child->data = 7;
    head->child->child = (struct node*)malloc(sizeof(struct node));
    head->child->child->data = 8;
    head->child->child->child = NULL;

    n10->child = (struct node*)malloc(sizeof(struct node));
    n10->child->data = 20;
    n10->child->child = NULL;

    n19->child = (struct node*)malloc(sizeof(struct node));
    n19->child->data = 22;
    n19->child->child = NULL;

    n28->child = (struct node*)malloc(sizeof(struct node));
    n28->child->data = 40;
    n28->child->child = (struct node*)malloc(sizeof(struct node));
    n28->child->child->data = 45;
    n28->child->child->child = NULL;

    head->child->next = NULL;
    head->child->child->next = NULL;
    n10->child->next = NULL;
    n19->child->next = NULL;
    n28->child->next = NULL;
    n28->child->child->next = NULL;

    struct nodeSingle *result = webToArr(head);

    printSingle(result);

    return 0;
}
