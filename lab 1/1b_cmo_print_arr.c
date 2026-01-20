#include<stdlib.h>
#include<stdio.h>
int main() {
    int **arr;
    arr = (int**) malloc(10*sizeof(int));
    for (int i=0; i<10; i++) {
        arr[i] = (int*) malloc(10*sizeof(int));
    }   
    int row, col;
    scanf("%d %d" ,&row ,&col);

    for (int j=0; j<col; j++) {
        for (int i=0; i<row; i++) {
            scanf("%d", *(arr+i)+j);
        }
    }

    printf("The array is \n");
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            printf("%d\t", *(*(arr+i)+j));
        }
        printf("\n");
    }

    
}