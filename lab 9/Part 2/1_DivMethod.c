#include<stdio.h>
#include<stdlib.h>

int * hashingDivision(int *arr, int n) {
    int *hash = (int *)malloc(1000 * sizeof(int));

    for (int i=0; i<n; i++) {
        int index = arr[i] % 1000;
        hash[index] = arr[i] ;
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

    int * hash = hashingDivision(arr, n);
    printf("Hash Table Mapping:\n");
    for (int i=0; i<n; i++) {
        int index = arr[i] % 1000;
        printf("%d -> %d\n", arr[i], index);
    }
} 