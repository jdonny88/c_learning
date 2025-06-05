#include <stdio.h>
#include <limits.h> /* This header defines the limits of basic types */
#include <float.h> /* This header defines the limits of floating point types */

/*There are only a few basic data types in C: */
/*
At first I tried defining then initialisating these global variables....
This isn't allowed in C. So I had to define and initialise together....
*/
int i = 0;
char c = 'a';
float f = 0.0;
double d = 0.0;

/* In addition, there are a number of qualifiers that can be applied to these basic types. */
short s = 0; /* This is shorthand for short int s = 0; */
long l = 0; /* This is shorthand for long int l = 0; */
long long ll = 0; /* Introduced in C99, long long is used for integers larger than long */
long double ld = 0.0; /* No short or long but C provides float, double and long double */
signed int si = 0; /* Signed integers are used for both negative and positive numbers */
unsigned int ui = 0; /* Unsigned integers are used for non-negative numbers */

int main()
{
    /* This is the size of each type */
    printf("Here're the basic data types:\n");
    printf("Size of int: %zu bytes\n", sizeof(i));
    printf("Size of char: %zu bytes\n", sizeof(c));
    printf("Size of float: %zu bytes\n", sizeof(f));
    printf("Size of double: %zu bytes\n\n", sizeof(d));

    printf("Here're the qualifiers:\n");
    printf("Size of short: %zu bytes\n", sizeof(s));
    printf("Size of long: %zu bytes\n", sizeof(l));
    printf("Size of long long: %zu bytes\n", sizeof(ll));
    printf("Size of long double: %zu bytes\n", sizeof(ld));
    printf("Size of signed int: %zu bytes\n", sizeof(si));
    printf("Size of unsigned int: %zu bytes\n\n", sizeof(ui));
    /* PLACEHOLDER This is the size of a pointer */

    /* Print ranges of each type*/
    printf("Here's the range of each basic type:\n");
    printf("Range of int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("Range of float: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("Range of double: %e to %e\n\n", DBL_MIN, DBL_MAX);

    printf("Here's the range of each qualifed type:\n");
    printf("Range of unsigned int: %u to %u\n", 0, UINT_MAX);
    printf("Range of signed int: %d to %d\n", INT_MIN, INT_MAX);
    printf("Range of short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("Range of long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("Range of long long: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("Range of long double: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
}