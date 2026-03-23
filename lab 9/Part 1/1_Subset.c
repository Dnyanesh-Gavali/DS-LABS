#include<stdio.h>

int subSet(int arr1[], int arr2[], int m, int n) {
    int hash[100000] = {0};
    for (int i=0; i<m; i++) {
        hash[arr1[i]]++;
    }

    for (int i=0; i<n; i++) {
        if (hash[arr2[i]] == 0) {
            return 0;
        }
    }
    return 1;
}
int main() {
    int m, n;
    printf("Enter the size of both arrays: ");
    scanf("%d %d", &m, &n);

    int arr1[m], arr2[n];
    printf("Enter the elements of array 1: \n");
    for (int i=0; i<m; i++) {
        printf("Enter elem at index %d: ", i);
        scanf("%d", &arr1[i]);
    }

    printf("Enter the elements of array 2: \n");
    for (int i=0; i<n; i++) {
        printf("Enter elem at index %d: ", i);
        scanf("%d", &arr2[i]);
    }

    if (subSet(arr1, arr2, m, n) == 0) {
        printf("\nThey are not subset\n");
    }
    else {
        printf("\nThey are subset of each other\n");
    }
}