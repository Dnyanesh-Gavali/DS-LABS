#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};
struct node * createList(int n, int circularNode) {
    struct node * head = NULL, * temp = NULL, *loopStart = NULL;

    int data;

    for (int i=0; i<n; i++) {
        struct node * new = (struct node *)malloc(sizeof(struct node));
        new->next = NULL;
        
        printf("Enter the data of %d node: ", i+1);
        scanf("%d", &data);
        
        new->data = data;
        if (head == NULL) {
            head = temp = new;
        }
        else {
            temp->next = new;
            temp = new;
        }

        if (i==circularNode) {
            loopStart = new;
        }
    } 

    if (loopStart != NULL) {
        temp->next = loopStart;
    }
    return head;
}
void Cycle(struct node * s) {
    if (s==NULL) {
        printf("\nNo node or sll");
    }
    else if (s->next == NULL) {
        printf("Only one node exist");
    }

    struct node * slow = s;
    struct node * fast = s;
    int flag=0;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow==fast) {
            flag=1;
            printf("\nThe cycle exist");
            break;
        }
    }

    if (flag == 0) {
        printf("NO cycle");
    }
}
int main() {
    int n;
    printf("Enter the size of ll: ");
    scanf("%d", &n);
    struct node * head = createList(n ,3);

    Cycle(head);
}