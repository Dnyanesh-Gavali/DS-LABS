#include<stdio.h>
#include<stdlib.h>

int * insertionSort(int * arr, int n) {
    for (int i =1; i< n; i++) {
        int key = arr[i];

        int j = i-1;

        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = key;
    }

    return arr;
}
int main() {
        int n;
    printf("Enter the size of n: ");
    scanf("%d", &n);

    int * arr = malloc(n * sizeof(int));    
    printf("Enter array elements: ");
    for (int i =0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }

    arr = insertionSort(arr, n);
    printf("\n\nSorted array elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
    free(arr);
}