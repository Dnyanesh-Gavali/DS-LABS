#include<stdio.h>
#include<stdlib.h>
int main() {
    int row, col;
    printf("Enter the row and column of matrix: ");
    scanf("%d %d" ,&row ,&col);

    int arr[row][col];
    printf("Enter the elements of matrix: ");
    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    int rmo, cmo, rth, cth;
    printf("enter the dimensions of element (row, column): ");
    scanf("%d %d", &rth, &cth);

    rmo = (int) &arr[0][0] + ((rth - 0) *(col) + (cth - 0)) * sizeof(int);
    
    cmo = (int) &arr[0][0] + ((cth - 0) *(row) + (rth - 0)) * sizeof(int);

    printf("\nThe address using rmo is %d", rmo);
    printf("\t%d", &arr[rth][cth]);
    printf("\nThe address using cmo is %d", cmo);

    if (rmo == (int) &arr[rth][cth]) {
        printf("\nThe memory follows rmo type and our formula is valid");
    }
    if (cmo == (int) &arr[rth][cth]) {
        printf("\nThe memory follows rmo type and our formula is valid");
    }
}