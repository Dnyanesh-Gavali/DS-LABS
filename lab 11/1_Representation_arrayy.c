#include<stdio.h>
#include<stdlib.h>

void init(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = -1; // -1 represents NULL
    }
}

void set_parent(int *arr, int key) {
    arr[0] = key;
}

void set_left(int *arr, int key, int pIndex, int n) {
    int left_child = (2 * pIndex) + 1;
    if (left_child < n) { 
        arr[left_child] = key;
    }
    else if (key != -1) {
        printf("Index %d out of bounds for left child\n", left_child);
    }
}

void set_right(int *arr, int key, int pIndex, int n) {
    int right = (2 * pIndex) + 2;
    if (right < n) { 
        arr[right] = key;
    } 
    else if (key != -1) {
        printf("Index %d out of bounds for right child\n", right);
    }
}

int main() {    
int n = 100;
    int *arr = malloc(n * sizeof(int));
    init(arr, n);
    
    int data;
    printf("Enter data for parent node (-1 for NULL): ");
    scanf("%d", &data);
    
    if (data == -1) {
        printf("Tree is empty.\n");
        free(arr);
        return 0;
    }
    
    set_parent(arr, data);

    int i = 0;
    int max_index = 0; 

    while(i <= max_index && i < n) {
        if (arr[i] == -1) {
            i++; 
            continue;
        }
        
        printf("Enter left child of %d (-1 for NULL): ", arr[i]);
        scanf("%d", &data);
        set_left(arr, data, i, n);
        if (data != -1) {
            int left_child = (2 * i) + 1;
            if (left_child > max_index) max_index = left_child;
        }
        
        printf("Enter right child of %d (-1 for NULL): ", arr[i]);
        scanf("%d", &data);
        set_right(arr, data, i, n);
        if (data != -1) {
            int right_child = (2 * i) + 2;
            if (right_child > max_index) max_index = right_child;
        }

        i++;
    }

    printf("\nArray representation of the tree:\n");
    for (int j = 0; j <= max_index; j++) {
        if (arr[j] == -1) printf("Null ");
        else printf("%d ", arr[j]);
    }
    printf("\n");
}