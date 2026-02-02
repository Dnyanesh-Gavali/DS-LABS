#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node * sort(struct node * s) {
    if (s == NULL || s->next == NULL)
        return s;

    struct node * temp1 = s;
    struct node * temp2 = s;

    while (temp1!=NULL) {
        temp2 = temp1->next;
        while(temp2 != NULL) {
            if (temp1->data > temp2->data) {
                int temp = temp1->data;
                temp1->data = temp2->data;
                temp2->data = temp;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return s;
}

struct node * createList(int n) {
    struct node * head = NULL, *temp = NULL;

    int data;
    for (int i =0; i<n; i++) {
        struct node * new = malloc(sizeof(struct node));

        printf("Enter data in sorted order: ");
        scanf("%d", &data);

        new->data = data;
        new->next = NULL;

        if (head==NULL) {
            head = temp = new;
        }
        else {
            temp->next = new;
            temp = new;
        }
    }
    return head;
}

struct node * merge2Lists(struct node * l1, struct node * l2) {
    if (l1 == NULL) return l2;
    if (l2 == NULL) return l1;

    struct node newNode;
    struct node * result = &newNode;
    newNode.next = NULL;
    while (l1 != NULL && l2!=NULL) {
        if (l1->data < l2->data) {
            result->next = l1;
            result = l1;
            l1 = l1->next;
        }
        else {
            result->next = l2;
            result = l2;
            l2 = l2->next;
        }
    }

    if (l1 != NULL) result->next = l1;
    else result->next = l2;

    return newNode.next;
}


struct node * merge(struct node* lists[], int k) {
    struct node* head = NULL;

    for (int i = 0; i < k; i++) {
        head = merge2Lists(head, lists[i]);
    }

    return head;
}

void display(struct node * s) {
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }

    printf("NULL");
}

int main() {
    int k;
    printf("Enter the number of lists: ");
    scanf("%d", &k);

    struct node * lists[k];
    for (int i = 0; i < k; i++) {
        int n;
        printf("\nEnter number of nodes in list %d: ", i + 1);
        scanf("%d", &n);

        printf("Enter list %d (%d elements): ", i+1, n);
        lists[i] = createList(n);
    }

    for (int i = 0; i<k; i++) {
        lists[i] = sort(lists[i]);
    }

    printf("\nMerged list:\n");
    struct node* merged = merge(lists, k);
    display(merged);
}