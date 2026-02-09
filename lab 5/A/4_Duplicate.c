#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node * next;
    struct node * prev;
};


struct node* createDLL(int n) {
    if (n <= 0) return NULL;

    struct node *s = NULL, *temp = NULL, *newNode;
    int value;

    for (int i = 0; i < n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));

        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if (s == NULL) {
            s = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }
    }

    return s;
}

void deleteNode(struct node *s) {
    if (s == NULL)
        return;

    if (s->prev != NULL)
        s->prev->next = s->next;

    if (s->next != NULL)
        s->next->prev = s->prev;

    free(s);
}

struct node* removeAllDuplicates(struct node* head) {
    struct node *i, *j, *next;
    int count;

    i = head;
    while (i != NULL) {
        int val = i->data;  
        count = 0;

        //count occurrences
        j = head;
        while (j != NULL) {
            if (j->data == val)
                count++;
            j = j->next;
        }

        // delete ALL occurrences
        if (count > 1) {
            j = head;
            while (j != NULL) {
                next = j->next;
                if (j->data == val) {
                    if (j == head)
                        head = next;
                    deleteNode(j);
                }
                j = next;
            }
            i = head;   
        } else {
            i = i->next;
        }
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
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    struct node * head = createDLL(n);

    display(head);
    printf("\n");

    head = removeAllDuplicates(head);
    display(head);
}
