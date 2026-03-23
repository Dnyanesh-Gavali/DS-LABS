#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int * hashingMulti(int *arr, int n, int m, double constant) {
    int *hash = malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        hash[i] = 0;
    }

     for (int i = 0; i < n; i++) {
        double x = arr[i] * constant;
        double frac = x - floor(x);
        int index = (int)(m * frac);
        hash[index] = arr[i];

        printf("%d -> %d\n", arr[i], index);
    }

    return hash;
}
int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of array: ");
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    int m;
    printf("Enter a number size of hash table: ");
    scanf("%d", &m);

    double constant;
    printf("Enter a value between 0 and 1(preferred is 0.61): ");
    scanf("%lf", &constant);

    int * hash = hashingMulti(arr, n, m, constant);
    printf("Hash Table Mapping:\n");
    for (int i = 0; i < m; i++) {
        printf("%d : %d\n", i, hash[i]);
    }

    free(hash);
}