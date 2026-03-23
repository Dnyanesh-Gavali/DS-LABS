#include<stdio.h>
int maxDist(int arr[], int n) {
    int hash[10000];
    int max = 0;
    for (int i=0; i<10000; i++) {
        hash[i] = -1;
    }

    for (int i=0; i<n; i++) {
        if(hash[arr[i]] == -1) {
            hash[arr[i]] = i;
        }

        else {
            int dist = i-hash[arr[i]];

            if (dist > max) {
                max = dist;
            }
        }
    }

    return max;
}
int main() {
    int m;
    printf("Enter the size of array: ");
    scanf("%d", &m);

    int arr1[m];
    printf("Enter the elements of array 1: \n");
    for (int i=0; i<m; i++) {
        printf("Enter elem at index %d: ", i);
        scanf("%d", &arr1[i]);
    }

    printf("The max dist is: %d", maxDist(arr1, m));
}