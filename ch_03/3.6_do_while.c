
#include <stdio.h>
#include <string.h>

void itoa(int, char []);
void reverse(char []);

int main() {
    int num = 61;
    printf("Number as number: %d\n", num);
    printf("Size of number: %zu bytes\n", sizeof(num));

    char s[20];
    itoa(num, s);
    printf("Number as string: %s\n", s);
    printf("Size of string: %zu bytes\n", sizeof(s));

    for (int i =0; i <= strlen(s); i++) {
        printf("Character %c: %d\n", s[i], s[i]);
        printf("Size of character: %zu bytes\n", sizeof(s[i]));
    }
}

// reverse: reverse string s in place
void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i]; // store the character at position i in c moving from left to right
        s[i] = s[j]; // store the character at position j in position i moving from right to left
        // This effectively swaps the characters at positions i and j
        // e.g. if s is "hello", after the first iteration, s becomes "oellh"
        // After the second iteration, s becomes "olleh"
        s[j] = c; // store the character in c at position j, used to get the original character at position i
    }
}

// itoa: convert n to characters in s
void itoa(int n, char s[]) {
    int i, sign;

    if ((sign = n) < 0)         // record sign
        n = -n;                 // make n positive
    i = 0;
    do {                        // generate digits in reverse order (right to left)
        s[i++] = n % 10 + '0';  // get the rightmost digit and conver it to a character
        // Note: '0' is the ASCII code for the character '0', so we add it to the digit to convert it to a character
        // e.g. if n is 61, then n % 10 is 1, and '0' + 1 is '1'
        // If n is 123, then n % 10 is 3, and '0' + 3 is '3'
    } while ((n /= 10) > 0);    // The integer division shifts to the left e.g. 61 becomes 6, then 0, and the loop stops
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}