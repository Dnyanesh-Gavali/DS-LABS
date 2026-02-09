#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};

struct node * createDLL(int n) {
    struct node * head = NULL, * tail =NULL, *new;

    int data;
    for (int i = 0; i<n; i++) {
        new = (struct node*)malloc(sizeof(struct node));
        printf("Enter the data to enter:  ");
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;
        new->prev = NULL;

        if (head == NULL) {
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


struct node * findNthNode(struct node * s, int k) {
    int count =1;
    while(s!=NULL) {
        if (count==k) return s;
        count++;
        s = s->next;
    }

    return s;
}
struct node * rotate(struct node *s, int k) {
    struct node * tail = s;
    int len;
    while (tail->next != NULL) {
        len++;
        tail = tail->next;
    }

    if (k%len == 0) return s;

    k = k%len;

    tail->next = s;
    s->prev = tail;

    struct node * newTail = findNthNode(s, len-k+1);
    s = newTail->next;
    s->prev = NULL;
    newTail->next =  NULL;
    return s;
}

void display(struct node *s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);

        s=s->next;
    }
    printf("NULL");
}
int main() {
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createDLL(n);

    int k;
    printf("Enter the rotation value: ");
    scanf("%d", &k);
    head = rotate(head, k);

    display(head);
}