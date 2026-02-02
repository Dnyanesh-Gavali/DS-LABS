#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node * createList(int n) {
    struct node *head = NULL, *tail= NULL;
    int data;

    for (int i =0; i<n; i++) {
        struct node * new = (struct node *) malloc(sizeof(struct node));
        printf("Enter the data for node %d: ", i+1);
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;

        if (head == NULL) {
            head = tail = new;
        }
        else {
            tail->next = new;
        }
        tail = new;
    }

    return head;
}

struct node * midElem(struct node *s) {
    if (s==NULL) {
        printf("No node exist");
        return s;
    }
    if (s->next == NULL) {
        printf("\nOnly one  node exist: ");
        return s;
    }
    struct node * temp = s;

    int count = 1;
    while (temp->next != NULL) {
        temp = temp->next;
        count++;
    }

    temp = s;
    if (count % 2 != 0) {
        int even = 0;
        while (even != count/2) {
            temp = temp->next;
            even++;
        }

        printf("The data is %d", temp->data);
    }
    else {
        int odd = 0;
        while (odd != count/2-1) {
            temp = temp->next;
            odd++;
        }

        printf("The mid elements are: ");
        printf("%d", temp->data);
        temp = temp->next;
        printf(" %d", temp->data);

    }
    return s;
}
int main() {
    int n;
    printf("Enter the number of nodes in list: ");
    scanf("%d", &n);
    struct node * head = createList(n);

    head = midElem(head);
}