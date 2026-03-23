#include<stdio.h>
#include<stdlib.h>

struct node  {
    int data;
    struct node *next;
};

struct node * createNode(int data) {
    struct node * new = (struct node * ) malloc(sizeof(struct node));
    new->data = data;
    new->next = NULL;

    return new;
}

int * chaining(int *arr, int n, int m) {
    int *hash = malloc(m * sizeof(int));

    for (int i = 0; i<m; i++) {
        hash[i] = 0;
    }

    for (int i = 0; i<n; i++) {
        int index = arr[i] % m;

        struct node * new = createNode(arr[i]);
        new->next = hash[index];

        hash[index] = new;
    }

    return hash;
}
int main() {
        int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int m;
    printf("Enter the size of hash table: ");
    scanf("%d", &m);

    int * hash = chaining(arr , n, m);

    printf("The hash map is: \n");

    for (int i = 0; i < m; i++) {
        printf("%d : ", i);
        struct node* temp = hash[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    free(hash);
}