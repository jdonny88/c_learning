#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <limits.h>

void print_binary(unsigned long long n, int bits) {
    for (int i = bits -1; i >=0; i--) {
        printf("%d", (n >> i) & 1);
    }
}

int main() {
    int x = 5;
    int x_neg = -5;
    long y = 5L;
    uint32_t z = 5U;
    uint32_t z_neg = (uint32_t)-5;

    printf("int x = %d\n", x);
    printf("  Size: %zu bytes\n", sizeof(x));
    printf("  Min: %d, Max: %d\n", INT_MIN, INT_MAX);
    printf("  Binary: ");
    print_binary((unsigned int)x, sizeof(x) * 8);
    printf("\n\n");

    printf("int x_neg = %d\n", x_neg);
    printf("  Size: %zu bytes\n", sizeof(x_neg));
    printf("  Min: %d, Max: %d\n", INT_MIN, INT_MAX);
    printf("  Binary: ");
    print_binary((unsigned int)x_neg, sizeof(x_neg) * 8);
    printf("\n\n");

    printf("long y = %ld\n", y);
    printf("  Size: %zu bytes\n", sizeof(y));
    printf("  Min: %ld, Max: %ld\n", LONG_MIN, LONG_MAX);
    printf("  Binary: ");
    print_binary((unsigned long)y, sizeof(y) * 8);
    printf("\n\n");

    printf("uint32_t z = %" PRIu32 "\n", z);
    printf("  Size: %zu bytes\n", sizeof(z));
    printf("  Min: 0, Max: %" PRIu32 " \n", UINT32_MAX);
    printf("  Binary: ");
    print_binary((unsigned long long)z, sizeof(z) * 8);
    printf("\n\n");

    printf("uint32_t z_neg = %" PRIu32 " (assigned -5)\n", z_neg);
    printf("  Size: %zu bytes\n", sizeof(z_neg));
    printf("  Min: 0, Max: %" PRIu32 " \n", UINT32_MAX);
    printf("  Binary: ");
    print_binary((unsigned long long)z_neg, sizeof(z_neg) * 8);
    printf("\n\n");

    printf("Demonstrating interpretation of z_neg as signed and unsigned:\n");
    printf("  As uint32_t: % " PRIu32 "\n", z_neg);
    printf("  As int32_t: % " PRId32 "\n\n", (int32_t)z_neg);

    printf("Demonstrating interpretation of x_neg as unsigned:\n");
    printf("  As unsigned int: %u\n\n", (unsigned int)x_neg);

    printf("And here's the math & logic...\n");
    printf("  As unsigned int: %u (which is (%d mod %llu) = %u)\n",
            (unsigned int)x_neg, x_neg, (unsigned long long)UINT_MAX + 1U, (unsigned int)x_neg);
    printf("  Just like 2 on a 12 hour clock minus 3 is 11. No negatives, just wrapping.\n");

    return 0;
}