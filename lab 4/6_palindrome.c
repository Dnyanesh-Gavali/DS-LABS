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

void palindrome (struct node * s) {
    struct node * prev = NULL, * tempReverse =s, *temp = s, *front;

    if (s==NULL) {
        printf("SLL don't exist");
    }

    if (s->next == NULL) {
        printf("Palindrome exist");
    }

    while (tempReverse != NULL) {
        front = tempReverse->next;
        tempReverse->next = prev;
        prev = tempReverse;
        tempReverse = front;
    }

    int flag=0;
    while (temp !=NULL) {
        if (temp->data == prev->data) {
            flag =1;
        }
        else {
            flag=0;
            break;
        }
        temp = temp->next;
        prev = prev->next;

    }
    if (flag == 1) {
        printf("Palindrome exist");
    }
    else {
        printf("Palindorme dont exist");
    }
}

void display(struct node * s) {
    if (s==NULL) {
        printf("The node does't exist");
    }

    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}
int main() {
    struct node * head = createList(5);

    palindrome(head);
}