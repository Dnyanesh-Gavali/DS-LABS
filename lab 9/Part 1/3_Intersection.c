#include<stdio.h>
#include<stdlib.h>

int * Intersection(int arr1[], int arr2[], int m,  int n, int *size) {
    int hash[100000] = {0};
    int *ans = (int*)malloc(1000 * sizeof(int)); 
    int k=0;
    for (int i=0; i<m; i++) {
        hash[arr1[i]]++;
    }

    for (int i=0; i<n; i++) {
        hash[arr2[i]]++;
    }

    for (int i=0; i<10000; i++) {
        if (hash[i] > 1) {
            ans[k++] = i;
        }
    }

    *size = k;
    return ans;

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
    
    int size;
    int *ans = Intersection(arr1, arr2, m, n, &size);
    for (int i=0; i<size; i++) {
        printf("%d\t", ans[i]);
    }
}