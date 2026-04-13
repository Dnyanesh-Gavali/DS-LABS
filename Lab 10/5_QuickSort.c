#include<stdio.h>
#include<stdlib.h>
int partition(int *arr, int l, int h) {
    int pivot = arr[l];
    int i = l;
    int j = h+1;
    while (i < j) {
        do {
            i++;
        }while (arr[i] <= pivot);

        do {
            j--;
        }while(arr[j] > pivot);

        if ( i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[l];
    arr[l] = arr[j];
    arr[j] = temp;

    return j;
}

void QuickSort(int *arr, int l, int h) {
    if (l < h) {
        int j = partition(arr, l, h);

        QuickSort(arr, l, j-1);
        QuickSort(arr, j+1, h);
    }

}
int main() {
    int n;
    printf("Enter the size of n: ");
    scanf("%d", &n);

    int * arr = malloc((n+1)* sizeof(int));    
    printf("Enter array elements: ");
    for (int i =0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }

    QuickSort(arr, 0, n-1);
    printf("\n\nSorted array elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
    free(arr);
}