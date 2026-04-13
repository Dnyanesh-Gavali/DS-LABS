#include<stdio.h>
#include<stdlib.h>

int * selectionSort(int *arr, int n) {
    for (int i = 0; i<n; i++) {
        int min = arr[i];
        int loc = i;
        for (int j = i+1; j<n; j++) {
            if (min > arr[j]) {
                min = arr[j];
                loc = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[loc];
        arr[loc] = temp;
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

    arr = selectionSort(arr, n);
    printf("\n\nSorted array elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
    free(arr);
}