#include<stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (int i =0 ;i<n; i++) {
        scanf("%d", &arr[i]);
    }   
    int max=arr[0], min=arr[0], target, flag = 0, index;
    float average =0;
    printf("\nEnter a number: ");
    scanf("%d", &target);
    for (int i=0; i<n; i++) {
        if (target == arr[i]) {
            flag =1;
            index = i;
        }
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
        average += (float) arr[i] / n;
    }
    if (flag == 1) {
        printf("Element found at index %d", index);
    }
    else {
        printf("Element not found");
    }
    printf("\nThe maximum element is %d", max);
    printf("\nThe minimum element is %d", min);
    printf("\nThe average is %f", average);
}