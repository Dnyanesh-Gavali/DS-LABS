#include<stdio.h>
#include<stdlib.h>

int * foldingHash(int *arr, int n) {
    int * hash = malloc(100 * sizeof(int));

    printf("hashIndex : value\n");
    for (int i = 0; i<n; i++) {
        int num = arr[i];
        int sum = 0;
        while (num > 0) {
            sum += num %100; // takes 2 digits and sum them
            num = num /100;
        }

        sum = sum % 100;

        hash[sum] = arr[i];
        printf("%d : %d \n", sum, arr[i]);
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

    int * hash = foldingHash(arr, n);
}