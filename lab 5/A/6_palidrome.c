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

void palindrome(struct node * s) {
    // if (s==NULL || s->next==NULL) {
    //     return s;
    // }

    struct node * temp =s;
    int count = 0;
    while (temp!=NULL) {
        count++;
        temp=temp->next;
    }

    temp = s;
    for (int k = 0; k < (count - 1) / 2; k++) {
        temp = temp->next;
    }
    
    struct node * left;
    struct node * right;

    if (count%2 == 0) {
        left = temp;
        right = temp->next;
    }
    else {
        left = right = temp;
    }

    int flag =0;
    while (left != NULL && right != NULL && flag ==0) {
        if (left->data == right->data) {
            left = left->prev;
            right = right->next;
        }
        else {
            flag =1;
        }
    }

    if (flag==0) {
        printf("Palindrome");
    }
    else{
        printf("Failed");
    }
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createDLL(n);

    palindrome(head);
}