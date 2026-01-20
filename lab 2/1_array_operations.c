#include<stdio.h>
#include<stdlib.h>

void make(int *arr, int n) {
    for (int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }
}

void sortDescending(int *arr, int size) {
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] < arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insert(int *arr, int size, int elem, int index) {
    int temp[size+1];
    for (int i=0; i<size; i++) {
        temp[i] = arr[i];
    }
    for (int i=size+1; i>index; i--) {
        temp[i] = temp[i-1];
    }
    temp[index] = elem;

    print(temp, size+1);

}

void delete(int *arr, int size, int index) {

    int temp[size];
    for (int i=0; i<size; i++) {
        temp[i] = arr[i];
    }

    for (int i=index; i<size-1; i++) {
        temp[i] = temp[i+1];
    }

    print(temp, size-1);
}

void reverse(int *arr, int size) {
    int temp[size];
    for (int i=0; i<size; i++) {
        temp[i] = arr[size-1-i];
    }

    printf("The reverse of array using temporary is : ");
    print(temp, size);

    int start=0, end = size-1;
    while(start<=end) {
        arr[start] = arr[start] + arr[end];
        arr[end] = arr[start] - arr[end];
        arr[start] = arr[start] - arr[end];
        start++;
        end--;
    }

    printf("The reverse of array without using temporary is : ");
    print(arr, size);
}

void copy(int *arr_main, int *arr_sub, int size_main, int size_sub) {
    int temp[size_main+size_sub];
    for (int i=0; i<size_main; i++) {
        temp[i] = arr_main[i];
    } 
    for (int i=size_main-1; i<size_main+size_sub-1; i++) {
        temp[i] = arr_sub[i-(size_main-1)];
    }

    print(temp, size_main+size_sub);
}

void merge(int *arr1, int *arr2, int size1, int size2, int *result) {
    int i = 0, j = 0, k = 0;

    int temp1[size1];
    for (int n=0; n<size1; n++) {
        temp1[n] = arr1[n];
    }

    int temp2[size2];
    for (int n=0; n<size2; n++) {
        temp2[n] = arr2[n];
    }

    sortDescending(temp1, size1);

    sortDescending(temp2, size2);

    while (i < size1 && j < size2) {
        if (temp1[i] > temp2[j]) {
            result[k++] = temp1[i++];
        } else {
            result[k++] = temp2[j++];
        }
    }

    while (i < size1) {
        result[k++] = temp1[i++];
    }

    while (j < size2) {
        result[k++] = temp2[j++];
    }

    print(result, size1+size2);
}

void sumIterative(int *arr, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += arr[i];
    }

    printf("the Sum is %d", sum);
    
}

int sumRecursive(int arr[], int n) {
    if(n == 0) {
        printf("the sum Recursive is 0");
    }
    return arr[n-1] + sumRecursive(arr, n-1);
}

void search(int *arr, int size, int elem) {
    int temp[size];
    for (int i=0; i<size;i++) {
        temp[i] = arr[i];
    }

    int flag=0, i;
    for (i=0; i<size && flag==0; i++) {
        if (elem == temp[i]) {
            flag=1;
        }
    }

    if (flag == 1) {
        printf("The element found at index %d", i);
    }
    else {
        printf("The element not found");
    }
}

void seperate(int *arr, int size) {
    int temp[size];
    for (int i=0; i<size; i++) {
        temp[i] = arr[i];
    }

    int even[20], odd[20], pos[20], neg[20];

    int e=0, o=0, p=0,   n=0;

    for (int i =0; i<size; i++) {
        if(temp[i] % 2==0) {
            even[e] = temp[i];
            e++;
        }
        else {
            odd[o] = temp[i];
            o++;
        }

        if (temp[i] >= 0) {
            pos[p] = temp[i];
            p++;
        }
        else {
            neg[n] = temp[i];
            n++;
        }
    }

    print(even, e);
    print(odd, o);
    print(pos, p);
    print(neg, n);
}

void print(int *arr, int size) {
    for (int i=0; i<size; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}


int main() {
    int *SubArray1;
    SubArray1 = (int *)malloc(10 * sizeof(int));

    int *SubArray2;
    SubArray2 = (int *)malloc(10 * sizeof(int));

    int *MainArray;
    MainArray = (int *)malloc(20 * sizeof(int));

    printf("Enter the elements of SubArray 1: ");
    make(SubArray1, 5);

    printf("Enter the elements of SubArray 2: ");
    make(SubArray2, 5);

    printf("Enter the elements of MainArray: ");
    make(MainArray, 10);
    
    int cont=1;
    while (cont != 0) {
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Reverse\n");
        printf("4. Copy\n");
        printf("5. Merge\n");
        printf("6. Display Sum\n");
        printf("7. Search\n");
        printf("8. Seperate\n");

        int choice;
        printf("\nEnter a valid choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            int elem;
            int index;
            int arr_ch;
            printf("Enter the element to insert: ");
            scanf("%d", &elem);

            printf("Enter the index where to insert: ");
            scanf("%d", &index);

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                insert(SubArray1, 5, elem, index);
            }
            else if (arr_ch == 2) {
                insert(SubArray2, 5, elem, index);
            }
            else if (arr_ch == 3) {
                insert(MainArray, 10, elem, index);
            }
            else {
                insert(SubArray1, 5, elem, index);
            }
        }

        else if (choice == 2) {
            int index;
            int arr_ch;

            printf("Enter the index to delete: ");
            scanf("%d", &index);

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                delete(SubArray1, 5, index);
            }
            else if (arr_ch == 2) {
                delete(SubArray2, 5, index);
            }
            else if (arr_ch == 3) {
                delete(MainArray, 10, index);
            }
            else {
                delete(SubArray1, 5, index);
            }
        }

        else if (choice == 3) {
            int arr_ch;

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                reverse(SubArray1, 5);
            }
            else if (arr_ch == 2) {
                reverse(SubArray2, 5);
            }
            else if (arr_ch == 3) {
                reverse(MainArray, 10);
            }
            else {
                reverse(SubArray1, 5);
            }
        }
        
        
        else if (choice == 4) {
            int arr_ch;

            printf("Which array to perform: 1. Sub1 2. Sub2: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                copy(MainArray, SubArray1, 10, 5);
            }
            else if (arr_ch == 2) {
                copy(MainArray, SubArray2, 10, 5);
            }
            else {
                copy(MainArray, SubArray1, 10, 5);
            }
        }

        else if (choice == 5) {
            int arr_ch;
            int result[20];

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                merge(SubArray1, SubArray2, 5, 5, result);
            }
            else if (arr_ch == 2) {
                merge(SubArray2, SubArray1, 5, 5, result);
            }
            else if (arr_ch == 3) {
                merge(MainArray, SubArray1, 10, 5, result);
            }
            else {
                merge(MainArray, SubArray2, 10, 5, result);
            }
        }

        else if (choice == 6) {
            int arr_ch;

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                sumIterative(SubArray1, 5);
                int sum_recursive = sumRecursive(SubArray1, 5);
                printf("\nThe recursive sum is %d", sum_recursive);
            }
            else if (arr_ch == 2) {
                sumIterative(SubArray1, 5);
                int sum_recursive = sumRecursive(SubArray1, 5);
                printf("\nThe recursive sum is %d", sum_recursive);
            }
            else if (arr_ch == 3) {
                sumIterative(SubArray1, 5);
                int sum_recursive = sumRecursive(SubArray1, 5);
                printf("\nThe recursive sum is %d", sum_recursive);
            }
            else {
                sumIterative(SubArray1, 5);
                int sum_recursive = sumRecursive(SubArray1, 5);
                printf("\nThe recursive sum is %d", sum_recursive);
            }
        }

        else if (choice == 7) {
            int elem;
            int arr_ch;

            printf("Enter the element to search: ");
            scanf("%d", &elem);

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                search(SubArray1, 5, elem);
            }
            else if (arr_ch == 2) {
                 search(SubArray2, 5, elem);
            }
            else if (arr_ch == 3) {
                 search(MainArray, 5, elem);
            }
            else {
                 search(SubArray1, 5, elem);
            }
        }

        else if (choice == 8) {
            int arr_ch;

            printf("Which array to perform: 1. Sub1 2. Sub2 3. Main: ");
            scanf("%d", &arr_ch);

            if (arr_ch == 1) {
                seperate(SubArray1, 5);
            }
            else if (arr_ch == 2) {
                seperate(SubArray2, 5);
            }
            else if (arr_ch == 3) {
                seperate(MainArray, 5);
            }
            else {
                seperate(SubArray1, 5);
            }
        }

        else {
            printf("\nEnter wrong choice !!! pleasse enter again......");
            scanf("%d", &choice);
        }



        printf("\nDo you want to continue(0/1): ");
        scanf("%d", &cont);

    }


}