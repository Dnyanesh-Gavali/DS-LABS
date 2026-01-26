#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node* createList(int n) {
    struct node *head = NULL, *temp = NULL, *newNode = NULL;
    int data;

    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);

        newNode = (struct node*)malloc(sizeof(struct node));
        newNode->data = data;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp->next = newNode;
        }

        temp = newNode;
    }

    return head;
}

struct node * insertHead(struct node * head, int data) {
    if (head == NULL) {
        printf("NO SLL");
        return head;
    }

    struct node * temp = (struct node *)malloc(sizeof(struct node));

    temp->data = data;
    temp->next = head;
    head = temp;

    return head;
}

struct node * undoList(struct node * head) {
    if (head == NULL) {
        printf("NO SLL");
        return head;
    }

    struct node * temp = head;
    head = head->next;
    free(temp);

    return head;
}

void printNode(struct node *s) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }

    int i=1;
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s= s->next;
    }

    printf("NULL");
}

int main() {
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);
    struct node* head = createList(n);

    int data;
    printf("Enter data to insert: ");
    scanf("%d", &data);

    head = insertHead(head, data);

    printNode(head);

    printf("\n");

    head = undoList(head);

    printNode(head);

}