#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
int count;
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

struct node * Insert(struct node * s, int k, int data) {
    if (s== NULL) {
        printf("The sll is empty");
        return s;
    }

    struct node * temp = s;
    int count =1;

    while (count != k-1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    struct node * new = malloc(sizeof(struct node));
    new->data = data;

    new->next = temp->next;
    temp->next = new;

    return s;
}

struct node * Delete(struct node *s, int k) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }

    struct node * temp = s;
    struct node * prev = s;

    int count = 1;
    while (count != k && temp->next !=  NULL) {
        prev = temp;
        temp = temp->next;
        count++;
    } 

    prev->next = temp->next;
    free(temp);

    return s;
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
        i++;
    }
    printf("NULL");
}
int main() {
    struct node * head = createList(5);
    
    printf("The sll is : ");
    printNode(head);


    int posInsert;
    printf("\nEnter the positon to insert(Note: position > 5 lead to insert at last): ");
    scanf("%d", &posInsert);

    int dataInsert;
    printf("Enter the data to insert: ");
    scanf("%d", &dataInsert);

    printf("\nAfter insertion: ");
    Insert(head, posInsert, dataInsert);
    printNode(head);

    int delInsert;
    printf("\nEnter the positon to insert(Note: position > 5 lead to delete the last): ");
    scanf("%d", &delInsert);
    printf("\nAfter deletion: ");
    Delete(head, delInsert);
    printNode(head);
}