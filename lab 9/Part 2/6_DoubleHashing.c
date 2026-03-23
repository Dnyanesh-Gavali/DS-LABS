#include<stdio.h>
#include<stdlib.h>

int * DBHashing(int *arr, int n, int m) {
    int * hash = malloc(m * sizeof(int));

    for (int i = 0; i< m; i++) {
        hash[i] = -1;
    }

    for (int i=0; i<n; i++) {
        int index1 = arr[i] % m;
        int index2 = arr[i] % (m-2) + 1;
        int j =0;
        while(hash[index1] != -1) {
            index1 = (arr[i] % m + j * index2) % m;
            j++;
        }

        hash[index1] = arr[i];
        printf("%d : %d \n", index1, arr[i]);
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

    int * hash = DBHashing(arr, n, m);

    free(hash);
}