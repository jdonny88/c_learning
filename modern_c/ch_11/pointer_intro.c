#include <stdio.h>
#include <stdlib.h>

void double_swap(double* p0, double* p1);
// Two function arguments that "point" to objects of type double.

/* For example, when the function is called, p0 and p1 could be pointing
to double variables d0 and d1 respectively. */

/* Using pointers, the function will be able to apply the change directly
to the variables of the calling function; a pure function without pointers
or arrays would not be able to do this. */


int main(void) {
    double d0 = 10.2;
    double d1 = 20.4;
    printf("Before swap: d0 = %.2f, d1 = %.2f\n", d0, d1);

    /* For the call to double_swap, we use the unary "address-of" operator "&".
    It allows us to refer to an object through its address. */
    double_swap(&d0, &d1);

    printf("After swap: d0 = %.2f, d1 = %.2f\n", d0, d1);
    return EXIT_SUCCESS;
}

void double_swap(double* p0, double* p1) {
    double tmp = *p0; // Dereferencing p0 to get the value it points to
    *p0 = *p1; // Dereferencing p1 to get the value it points to and assign it to the location pointed by p0
    *p1 = tmp; // Assigning the value of tmp to the location pointed by p1
}
/* Pointers are an important concept, so there are several C langauge operations
and features just for them.

Most importantly, specific operators allow us to deal with the "pointing-to" and
"pointed-to" relation between pointers and the objects to which they point to.

Also, pointers are considered scalars:
- Arithmetic operations are defined for them, offset additions and subtractions
- They have "state"
- And they have a dedicated "null" state
*/