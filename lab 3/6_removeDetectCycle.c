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
struct node * detectRemove(struct node * s) {
    if (s==NULL) {
        printf("SLL doesn't exist");
    }

    struct node * fast = s;
    struct node * slow = s;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            printf("CYCLE detected");
            break;
        }
    }

    if (fast == NULL || fast->next  == NULL) {
        printf("CYCLE DON'T EXIST");
        return 0;  
    }

    slow = s;

    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    while (fast->next != slow) {
        fast = fast->next;
    }

    fast->next = NULL;
    return s;
}
void display(struct node * s) {
    if (s==NULL) {
        printf("The Sll doesn't exist");
    }


    while (s!= NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}
int main() {
    int n;
    printf("enter the size of ll: ");
    scanf("%d", &n);
    struct node * head = createList(n, n-3);

    head = detectRemove(head);

    printf("\nAfter removal: ");
    display(head);
}