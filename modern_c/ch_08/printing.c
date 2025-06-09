#include <stdio.h>
#include <stdint.h>

int main(void) {
    int32_t a = -42;
    int32_t aa = 42;
    uint32_t b = 42U;
    uint32_t c = -42U;
    double d = 


    printf("This is a negative signed integer: %d\n", a);
    printf("This is a positive signed integer with signing: %+d\n", aa);
    
    // Printing signed with unsigned specifier: undefined behavior (may appear to wrap, but not guaranteed).
    // Always match your types to your format specifiers for portable, correct code!
    printf("This is the same negative signed integer with an unsigned specifier: %u\n", a);
    printf("This is an unsiged integer: %u\n", b);
    printf("This is an unsiged integer with padding: %010u\n", b);

    // Assigning negative to unsigned: well-defined, wraps modulo.
    printf("This is a small, unsiged integer initialised with a '-' so 'wrapping around': %u\n", c);


    printf("This is a string literal: %s\n", "Hello, World!");
    printf("%.5s\n", "Hello, World!"); // Printing a substring (precision for strings) Prints: Hello
    printf("100%% complete\n"); // Prints: 100%
    printf("'%10s'\n", "cat");   // Right-aligns in 10 spaces: '       cat'
    printf("'%-10s'\n", "cat");  // Left-aligns in 10 spaces: 'cat       '
    printf("Tab\tNewline\nBackslash\\Quote\"\n");
    
    printf("This is a character literal: %c\n\n", 'A');
    printf("Char: %c, ASCII: %d\n", 'A', 'A'); // Char: A, ASCII: 65

    int n = 42;
    printf("Playing with padding and co...\n");
    printf("Width 10: '%10d'\n", n);
    printf("Left align: '%-10d'\n", n);
    printf("Zero pad: '%010d'\n", n);
    printf("Always show sign: '%+d'\n", n);
    printf("Space for positive: '% d'\n", n);
    printf("Hex with 0x: '%#x'\n", n);
    printf("Octal with 0: '%#o'\n\n", n);

    double pi = 3.14159;
    printf("Playing with pi...\n");
    printf("Float, 2 decimals: '%.2f'\n", pi);
    printf("Float, width 10, 2 decimals: '%10.2f'\n\n", pi);
}