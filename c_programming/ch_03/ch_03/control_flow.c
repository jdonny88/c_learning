/* Chapter 3 - Control Flow */
#include <stdio.h>

/* Without 'extern' the compiler treats these as definitions of 
global variables and storage is allocated accordingly.*/
int y = 1; // This has been explicitly initialized
int z; // This is implicitly initialized to 0

/* Declaring a is fine if you don't use it...
If you use a without a definition somewhere though...
You'll get a linker error, not a compiler error.
For you declare symbols with extern, the compiler only
checks declarations; the linker checks defintions*/
extern int a;

/* In C, global variables that are not explicitly initialized
are automatically initialized to zero (for numeric types)
or '\0' (the null character, for char). So, c equals '\0'
(the null character), which is the character with ASCII value 0.*/
char c;



int main()
{
    /*---------------Mucking around with scope------------------*/
    // printf("a = %d\n", a); This will cause a linker error
    printf("Mucking around with scope...\n");
    printf("Global z = %d\n", z);
    z = 1; /* This updates the global variable */
    printf("Global z now = %d\n", z);
    int global_z_exists = 1;
    int global_z = z; // Capture global z value before it gets shadowed

    int z = 0; /* This is a local variable that shadows the global z */
    printf("Local z shadowing global z is = %d\n", z);

    /* you will likely see a blank space or nothing at all in the output,
    because the null character is not printable.*/
    printf("Global c = %c... AKA NULL\n\n", c);

    int x = 1;

    /*---------------Exploring conditionals------------------*/
    /* braces below aren't necessary due to single statements but
    are probably a good practice to be in the habit of using*/
    printf("Exploring conditionals...\n");
    if (x && y && z)
    {
        printf("x, y and local z are true\n\n");
    } else if (global_z_exists && global_z)
    {
        printf("x, y and global a are true\n\n");;
    } else {
        printf("x, y, z or some combination of these are false\n\n");
    }

    printf("Exploring switch...\n");
    switch(global_z_exists) {
        case 1:
            printf("There's a global z you can use!\n");
            break; // don't forget the breaks!
        case 0:
            printf("There's no global z!\n");
            break;
        default:
            printf("What's going on?\n");
            break; // Even here to guard against future cases
    }
}