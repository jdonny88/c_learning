#include <stdio.h>

int main() {
    // 5.1 The abtract state machine
    double x = 5.0;
    double y = 3.0;

    x = (x * 1.5) - y;
    printf("x is %g\n", x);

    /* Expression processing order for line 8 then line 9
        1. x is evaluated to the value 5.0 -> (5.0 * 1.5) which results in a value 7.5...
        2. y is evaluated to the value 3.0 -> 7.5 - 3.0 which results in 4.5...
        3. x = 4.5 results in a change of value of x to 4.5.
        4. The x in printf is evaluated to the value 4.5, which is printed as "x is 4.5".
    */

    /* Only operations (and their resulting values) that are stored in addressable memory
        or written to an output device are "observable".
    */

    /* In this example, optmisation by the compiler may replace the while think with the equivalent
        printf("x is 4.5\n");...
        Meaning all the computations will be done at compile time, and the executable provided will just
        print a fixed string...
        All the remaining code and even the definitions of the variables disappear.
        NOTE this is only if x isn't used later...

        Other example if x is used later...

        For an optimisation to be value, it is only important that a C compiler produces an executable
        that reproduces the observable states.
    */

    /* 5.1 - The abstract state machine....
    Values (5.1.1), Types (5.1.2), Binary representation (5.1.3), and optimisation (5.1.4)
        - All values are numbers or translate to numbers.
        - Types are the core concept that enables us to achieve platform independence.
        - A type is an additional property that C associates with values.
            - All values have a type that is statically determined.
            - Possible operations on a value are determined by its type.
            - A value's type determines the results of all operations. 
        - A type's binary representation determines the results of all operations.
    */
}