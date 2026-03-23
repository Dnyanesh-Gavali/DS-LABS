#include<stdio.h>
#include<stdlib.h>

int count(int n) {
    int count = 0;
    while (n>0) {
        count++;
        n = n/10;
    }
    return count;
}

int * midSquareHashing(int *arr, int n, int m) {
    int * hash = malloc(m * sizeof(int));

    for (int i = 0; i<n; i++) {
        int sq = arr[i] * arr[i];       
        int r = sq;
        int j = 0;
        int digits = count(sq);
        while (j < digits / 2) {
            sq = sq/10;
            j++;
        }
        r = sq%m;

        hash[r] = arr[i];
        printf("%d : %d\n", r, arr[i]);
    }

    return hash;
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int m;
    printf("Enter the table size (choose between 10, 100, 1000): ");
    scanf("%d", &m);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }


    int * hash = midSquareHashing(arr, n, m);
}