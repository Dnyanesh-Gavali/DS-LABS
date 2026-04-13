#include<stdio.h>
#include<stdlib.h>


void merge(int *arr, int s, int mid, int e) {
    int n1 = mid - s + 1;
    int n2 = e - mid;

    int l[n1+1];
    int r[n2+1];
    for (int i = 0; i<n1; i++) {
        l[i] = arr[s+i];
    }

    for (int i = 0; i<n2; i++) {
        r[i] = arr[mid+i+1];
    }

    l[n1] = __INT_MAX__;
    r[n2] = __INT_MAX__;

    int i=0, j = 0;
    for (int k=s; k<=e; k++) {
        if (l[i] < r[j]) {
            arr[k] = l[i];
            i++;
        }
        else {
            arr[k] = r[j];
            j++;
        }
    }
}

void mergeSort(int *arr, int s, int e) {
    if (s < e) {
        int mid = (s + e)/2;

        mergeSort(arr, s, mid);
        mergeSort(arr, mid+1, e);
        merge(arr, s, mid, e);
    }
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

    mergeSort(arr, 0, n-1);
    printf("\n\nSorted array elements: ");
    for (int i =0; i<n; i++) {
        printf("%d\t", arr[i]);
    }
    free(arr);
}