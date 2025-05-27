#include <ctype.h>
#include <stdio.h>

int atoi(char []);

main(int argc, char *argv)
{
    if (argc == 2)
    {
        printf("%s", argv[1]);
        int result = atoi(argv[1]);
        printf("%d\n", result);
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