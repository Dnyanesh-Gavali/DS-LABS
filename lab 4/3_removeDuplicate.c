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

struct node* sortLL(struct node* head) {
    if (head == NULL || head->next == NULL)
        return head;

    struct node *i = head;
    struct node *j;
    int temp;

    while (i->next != NULL) {
        j = i->next;

        while (j != NULL) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
            j = j->next;
        }
        i = i->next;
    }
    return head;
}

struct node * removeDuplicate(struct node * s) {
    if (s==NULL) {
        printf("The ll doesn't exist");
    }
    else if (s==NULL) {
        printf("Only one node exist");
    }

    s = sortLL(s);
    struct node * temp = s;

    while (temp->next!=NULL) {
        if (temp->data != temp->next->data) {
            temp = temp->next;
        }
        else {
            struct node * sec = temp->next;
            temp->next = sec->next;
            free(sec);
        }
    }

   return s; 
}
void display(struct node * s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}
int main() {
    int n;
    printf("Enter the number of nodes in list: ");
    scanf("%d", &n);
    struct node * head = createList(n);

    printf("ORIGINAL LL: ");
    display(head);

    printf("\n\n");

    head = removeDuplicate(head);

    display(head);
}