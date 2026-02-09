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

struct node * lastNode(struct node * s) {
    struct node * temp = s;

    while(temp->next != temp) {
        struct node * del = temp;
        temp->next = del->next;
        free(del);
        temp = temp->next;
    }

    return temp;
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
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createCLL(n);

    head = lastNode(head);
    displayCLL(head);
}