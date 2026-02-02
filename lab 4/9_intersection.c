#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};

struct node * Intersection(struct node * s1, struct node * s2, int d) {
    struct node * temp1 = s1, * temp2 = s2;

    while(d) {
        d--;
        temp2 = temp2->next;
    }

    while (temp1 != temp2) {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return temp1;
}


struct node * Detection(struct node * s1, struct node *s2) {
    int count1 = 0, count2=0;

    struct node * temp1 = s1;
    struct node * temp2 = s2;

    while (temp1 != NULL) {
        count1++;
        temp1 = temp1->next;
    }

    while (temp2 != NULL) {
        count2++;
        temp2 = temp2->next;
    }

    if (count1 < count2) {
        return Intersection(s1, s2, count2 - count1);
    }
    else {
        return Intersection(s2, s1, count1-count2);
    }

}
void display(struct node *head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct node *common1 = (struct node *)malloc(sizeof(struct node));
    struct node *common2 = (struct node *)malloc(sizeof(struct node));

    common1->data = 3;
    common2->data = 4;

    common1->next = common2;
    common2->next = NULL;

    struct node *l1_1 = (struct node *)malloc(sizeof(struct node));
    struct node *l1_2 = (struct node *)malloc(sizeof(struct node));

    l1_1->data = 1;
    l1_2->data = 2;

    l1_1->next = l1_2;
    l1_2->next = common1;   // join here

    struct node *head1 = l1_1;
    struct node *l2_1 = (struct node *)malloc(sizeof(struct node));
    l2_1->data = 9;

    l2_1->next = common1;   // join here

    struct node *head2 = l2_1;

    printf("List 1:\n");
    display(head1);

    printf("List 2:\n");
    display(head2);

    struct node *intersect = Detection(head1, head2);

    if (intersect != NULL)
        printf("Intersection point data: %d\n", intersect->data);
    else
        printf("No intersection found\n");

}
