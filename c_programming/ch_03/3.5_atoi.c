#include <ctype.h>
#include <stdio.h>

int atoi(char []);

main(int argc, char **argv)
{
    char *test = "22";
    printf("Test case for the number 22...\n");
    if (atoi(test) == 22)
        printf("'22' was converted to 22.\n\n");
    else
        printf("'22' is still just '22'...\n\n");

    if (argc == 2)
    {
        printf("The string (null-terminated character array) was %s.\n", argv[1]);
        printf("Its character set integer value is %d.\n", *argv[1]);
        
        int result = atoi(argv[1]);
        printf("The resulting integer is %d.\n", result);
    } else
    {
        printf("Enter a single argument please.\n");
    }
    
}

// atoi: convert s to integer: version 2
int atoi(char s[])
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++) // skip white space
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') // skip sign
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}