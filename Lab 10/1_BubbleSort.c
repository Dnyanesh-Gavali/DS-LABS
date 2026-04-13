#include<stdio.h>
#include<stdlib.h>

int * BS(int * arr, int n) {
    for (int  i= 0; i<n; i++) {
        int flag = 0;
        for (int j = 0; j<n-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }

        if (flag == 0) break;
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
    arr = BS(arr, n);
    printf("\n\nSorted array elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }

    free(arr);
}