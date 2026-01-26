#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
struct node * insertHead(struct node *s, int data) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }   

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = s;
    s = new;
    printf("Inserted successfully");
    return s;
}

struct node * insertTail(struct node *s, int data) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }   

    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    struct node *temp = s;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new;

    printf("Inserted successfully");
    return s;

}

struct node * deleteValue(struct node *s, int data) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }  

    struct node * p = s;
    struct node *q = s;
    while(q->data != data && q->next != NULL ) {
        p = q;
        q = q->next;
    }

    if (q->data == data) {
        p->next = q->next;
        free(q);
    }
    printf("Deleted successfully");
    return s;
}

struct node * deletePosition(struct node *s, int index) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }  

    struct node * p = s;
    struct node *q = s;
    int count = 0;
    while(count != index && q->next != NULL ) {
        count++;
        p = q;
        q = q->next;
    }

    if (count == index) {
        p->next = q->next;
        free(q);
    }

    printf("Deleted successfully");
    return s;
}

struct node * reverse(struct node* s) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }  
    struct node * temp = s;

    struct node * prev = NULL;

    struct node * front;

    while (temp!= NULL) {
        front = temp->next;
        temp->next = prev;
        prev = temp; 
        temp = front;
    }

    printf("Reversed successfully");
    return prev;
}

void cycle(struct node *s) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }  

    struct node * p = s;
    struct node * q = s;

    int flag=0;

    while(q!= NULL && q->next != NULL && flag!=1) {
        p = p->next;
        q = q->next->next;

        if (p==q) {
            printf("Yes cycle found");
            flag=1;
            break;
        }
    }

    if (flag == 0) {
        printf("No Cycle detected");
    }

}

void search(struct node * s, int data) {
     if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }  

    int count = 1, flag=0;
    while (s->data != data && flag!=1) {
        s= s->next;
        count++;
        if (s->data == data) {
            flag=1;
        }
    }
    if (flag==1) {
        printf("The data found at node %d", count);
    }
    else {
        printf("NO data found");
    }

}
void printNode(struct node *s) {
    if (s == NULL) {
        printf("Node does not exist");
    }
    else if (s->next==NULL) {
        printf("Only ONE NODE EXIST: %d", s->data);
    }

    int i=1;
    while (s!=NULL) {
        printf("%d -> ", s->data);
        s = s->next;
    }
    printf("NULL");
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 20;
    third->data = 30;
    fourth->data = 40;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    printf("\nThe Linked list Operations:- ");
    int choice;
    int cont=1;
    while (cont == 1) {
        printf("\n1.Insert At Head.");
        printf("\n2.Insert At Tail.");
        printf("\n3.Delete by Value.");
        printf("\n4.Delete by Position");
        printf("\n5.Search for Value");
        printf("\n6.Reverse the list.");
        printf("\n7.Detect Cycle.");        
        printf("\n8.Display List.\n");

        printf("\n-------The list is -------- \n");
        printNode(head);

        printf("\nEnter the choice: ");
        scanf("%d", &choice);


        if (choice > 8 || choice <=0) {
            printf("\nInvalid choice !!..Enter the choice: ");
        }
        if (choice == 1) {
            int data;
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            head = insertHead(head, data);
        }
        else if (choice == 2) {
            int data;
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            head = insertTail(head, data);
        }
        else if (choice == 3) {
            int data;
            printf("Enter the data to delete: ");
            scanf("%d", &data);
            head = deleteValue(head, data);
        }
        else if (choice == 4) {
            int index;
            printf("Enter the index to delete: ");
            scanf("%d", &index);
            head = deletePosition(head, index);
        }
        else if (choice == 5) {
            int data;
            printf("Enter the data to search: ");
            scanf("%d", &data);
            search(head, data);
        }
        else if(choice == 6) {
            head = reverse(head);
        }
        else if(choice == 7) {
            cycle(head);
        }
        else if(choice ==8) {
            printNode(head);
        }

        printf("\nDo you want to continue(0/1): ");
        scanf("%d", &cont);
    }
    
}