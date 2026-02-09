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

struct node * reverse(struct node * s) {
    struct node *current = s;
    struct node *temp = NULL;

    while (current != NULL) {
        // swap prev and next
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        // move to next node (which is prev now)
        current = current->prev;
    }

    // temp will be pointing to the old head's prev
    if (temp != NULL) {
        s = temp->prev;
    }

    return s;
}

void display(struct node * s) {
    while(s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}
int main() { 
    int n;
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    printf("\n");
    struct node * head = createDLL(n);
    display(head);

    printf("\n");

    head = reverse(head);
    display(head);

}