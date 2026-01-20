#include <stdio.h>

struct stud {
    int id;
    float marks;
};

int main() {

    int a = 10;
    float b = 3.14f;
    char c = 'A';
    double d = 99.99;

    int arr[3] = {1, 2, 3};
    struct stud s = {101, 88.5};

    printf("---- Primitive Data Types ----\n");
    printf("int a = %d, Address = %p, Size = %d bytes\n", a, &a, sizeof(a));
    printf("float b = %.2f, Address = %p, Size = %d bytes\n", b, &b, sizeof(b));
    printf("char c = %c, Address = %p, Size = %d byte\n", c, &c, sizeof(c));
    printf("double d = %.2lf, Address = %p, Size = %d bytes\n\n", d, &d, sizeof(d));

    printf("---- Non-Primitive Data Types ----\n");
    printf("Array elements:\n");
    for(int i = 0; i < 3; i++) {
        printf("arr[%d] = %d, Address = %p, Size = %d bytes\n",
               i, arr[i], &arr[i], sizeof(arr[i]));
    }

    printf("\nStructure values:\n");
    printf("Student ID = %d, Address = %p, Size = %d bytes\n",
           s.id, &s.id, sizeof(s.id));
    printf("Student Marks = %.2f, Address = %p, Size = %d bytes\n",
           s.marks, &s.marks, sizeof(s.marks));

    printf("\nTotal size of structure = %d bytes\n", sizeof(s));
}
