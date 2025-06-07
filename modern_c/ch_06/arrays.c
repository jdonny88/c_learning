// arrays.c
// Examples and idioms for working with arrays in C

#include <stdio.h>
#include <stdlib.h>

// This is the only way to really encapsulate the functionality to determine the size of an array.
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

// No real way to take in an array of any type to print its contents.
void print_double_array(const double *a, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("Element %zu: %f\n", i, a[i]);
    }
}

/* Doesn't work as the array decays to a pointer when passed to the function.
size_t get_size(double *a) {
    return sizeof(a) / sizeof(a[0]);
}
*/

int main(void) {
    double a[4] = { [3] = 3.14, };
    double b[4] = { 1.0, 2.0, 3.0, 4.0 };
    double c[] = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    printf("This is the first element of an array: %f\n", a[0]);

    printf("And this is a loop through the array:\n");
    for (size_t i = 0; i < (sizeof(a) / sizeof(a[0])); i++) {
        printf("Element %zu: %f\n", i, a[i]);
    }

    printf("This is the second array:\n");
    print_double_array(b, sizeof(b) / sizeof(b[0]));

    printf("This is the third array:\n");
    print_double_array(c, ARRAY_SIZE(c));

    printf("This is what it looks like to access an element out of bounds:\n");
    // Accessing out of bounds is undefined behavior, but let's see what happens.
    printf("Element 4 of array a: %f\n", a[4]); // Undefined behavior, but often compilers will not crash.
    /*
    You got 0.00000 because the memory after your array happened to look like a zeroed double,
    but this is not guaranteed and should never be relied upon.
    Always avoid out-of-bounds access!
    */

    return EXIT_SUCCESS;
}

/*
Idomatic C practices in the code:
- Using size_t for array indices and sizes
- Using the sizeof operator to determine the size of arrays
- Using a macro (ARRAY_SIZE) to encapsulate and reuse the logic to determine the array length at compile time
- Passing the array size as a parameter to functions that operate on arrays
- Using %zu as the format specifier for size_t in printf
- Initialising arrays with designated initializers (e.g., [3] = 3.14)
- Keeping functions focused and simple (e.g., print_darray)
- Using const for function parameters to indicate that the data will not be modified
- Using a loop to iterate through arrays instead of hardcoding indices
*/

/*
"Footguns" in the code:
- Accessing out-of-bounds elements, which leads to undefined behavior.
- Using sizeof on a pointer instead of an array, which will not yield the expected size.
*/