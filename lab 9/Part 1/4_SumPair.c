#include<stdio.h>
int main() {
    int hash[100] = {0};
    int count = 0;


    int m;
    printf("Enter the size of array: ");
    scanf("%d", &m);

    int arr[m];
    printf("Enter the elements of array 1: \n");
    for (int i=0; i<m; i++) {
        printf("Enter elem at index %d: ", i);
        scanf("%d", &arr[i]);
    }

    int target;
    printf("Enter the target number: ");
    scanf("%d", &target);

    for(int i=0; i<m; i++) {
        int com = target - arr[i];
        
        if (com >= 0 && com<100 && hash[com] == 1) {
            count++;
        }

        if (arr[i] >= 0 && arr[i] < 100) {
            hash[arr[i]] = 1;
        }
    }

     printf("Number of pairs = %d\n", count);
}