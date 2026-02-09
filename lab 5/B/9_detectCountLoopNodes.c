#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
};

struct node* createCLL(int n, int loopPos) {
    if (n <= 0 || loopPos <= 0) return NULL;

    struct node *head = NULL, *tail = NULL;
    struct node *loopNode = NULL;
    int data;

    for (int i = 1; i <= n; i++) {
        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        newNode->data = data;
        newNode->next = NULL;

        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (i == loopPos) {
            loopNode = newNode;
        }
    }

    if (loopNode) {
        tail->next = loopNode;
    }

    return head;
}
int countDetect(struct node *s) {
    struct node * slow = s;
    struct node * fast = s;

    while(fast != NULL && fast->next!=NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            int count=1;
            printf("The loop detected");

            struct node * temp = slow->next;
            while(temp!=slow) {
                count++;
                temp = temp->next;
            }

            return count;
        }
    }
    return 0;
}


int main() {
    int n;
    printf("Enter the number of nodes in list1: ");
    scanf("%d", &n);

    int loopPos;
    printf("Enter the position for loop start: ");
    scanf("%d", &loopPos);
    struct node * l1 = createCLL(n, loopPos);

    int count = countDetect(l1);
    printf("\nThe count is: %d", count);
}