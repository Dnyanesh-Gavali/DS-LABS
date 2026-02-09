#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * next;
    struct node * prev;
};

struct node * createDLL(int n) {
    struct node * head = NULL, * tail = NULL, *new;

    int data;
    for (int i=0; i<n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;
        new->prev = NULL;

        if (head== NULL) {
            head = tail = new;
        }
        else {
            tail->next = new;
            new->prev = tail;
            tail = new;
        }
    }

    return head;
}

struct node * maxSum(struct node *s, struct node **end) {
    struct node * t1= s, *t2;
    struct node *maxStart = NULL, *maxEnd = NULL;


    int sum, max = -10010;

    while(t1!=NULL) {
        sum = 0;
        t2 = t1;
        while (t2!=NULL) {
            sum+=t2->data;

            if (sum>max) {
                max = sum;
                maxStart = t1;
                maxEnd = t2;
            }

            t2 = t2->next;
        }
        t1 = t1->next;
    }

    *end = maxEnd;
    printf("\nThe max is: %d", max);
    return maxStart;
}

void printSublist(struct node *start, struct node *end) {
    while (start != NULL) {
        printf("%d -> ", start->data);
        if (start == end)
            break;
        start = start->next;
    }
    printf("NULL\n");
}

int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createDLL(n);

     struct node *end;

    struct node *start = maxSum(head, &end);

    printf("\nMaximum sum sublist:\n");
    printSublist(start, end);
   
}