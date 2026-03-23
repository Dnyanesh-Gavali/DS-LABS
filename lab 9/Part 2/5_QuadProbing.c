#include<stdio.h>
#include<stdlib.h>

int * QuadProbing(int * arr, int n, int m) {
    int * hash = malloc(m * sizeof(int));

    for (int i =0; i< m; i++) {
        hash[i] = -1;
    }

    for (int i = 0; i< n; i++) {
        int index = arr[i] % m;
        int j = 0;
        while (hash[index] != -1) {
            index = (arr[i] % m + j * j) % m;
            j++;
        }

        hash[index] = arr[i];

        printf("%d : %d \n", index, arr[i]);
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

    int * hash = QuadProbing(arr, n, m);
    free(hash);
}