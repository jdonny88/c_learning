#include <stdio.h>
#include <stdlib.h>

int binsearch(int, int [], int);

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
    int nums[] = {1, 3, 5, 7, 18, 20};

    /* arrays in C are contiguous blocks of memory, meaning
    element sizes are uniform and consecutive... The total size
    of an array is the sum its elements' sizes. So, to get the
    number of elements, we divide the total size by the size of
    a single element. */
    int size = sizeof(nums) / sizeof(nums[0]);

    int result = binsearch(num, nums, size);

    if (result >= 0)
        printf("Found %d in numbers at position %d!\n", nums[result], result+1);
    else
        printf("Did not find number in set.\n");
}

/* binsearch: find X in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /* found match */
            return mid;
    }
    return -1; /* no match */
}