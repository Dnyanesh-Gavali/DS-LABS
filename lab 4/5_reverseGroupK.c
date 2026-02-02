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

struct node * reverseK(struct node * s, int k) {
    struct node * temp = s, * prev = NULL, * front, * newHead = NULL, *tail = NULL;

    while (temp!=NULL) {

        int count = 0;
        struct node * check = temp;
        while (check != NULL && count < k) {
            check = check->next;
            count++;
        }

        // If nodes are less than k -> don't reverse
        if (count < k) {
            if (tail != NULL)
                tail->next = temp;
            else
                newHead = temp;
            break;
        }
        count = 0;
        struct node * groupStart = temp;
        prev = NULL;
        
        while (temp!= NULL && count < k) {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
            count ++;
        }

        if (newHead == NULL) {
            newHead = prev;
        }
        else {
            tail->next = prev;
        }

        tail = groupStart;
    }
    return newHead;
}

void display(struct node *s) {
    if (s==NULL) {
        printf("No node exist");
    }
    while(s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}
int main() {
    struct node *head = createList(8);
    display(head);
    
    head = reverseK(head, 3);

    printf("\n");

    display(head);
}