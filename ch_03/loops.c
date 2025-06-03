#include <stdio.h>

int main(int argc, char *argv[])
{
    int i;
    int j;
    int z = 10;
    
    for (i = 0; i <10; i++)
    {
        if (argc > 2)
        {
            printf("%d. ", i);
            for (j = 1; j < argc; j++)
            {
                printf("%s \n", argv[j]);
            }
        } else
        {
            printf("%d. %s\n", i, argv[1]);
        }
    };

    while (z > 0)
    {
        printf("%d\n", z);
        z--;
    }

    do {
        printf("%d\n", z);
        z++;
    } while (z < 10);
}