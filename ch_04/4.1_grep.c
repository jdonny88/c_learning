/* while (there's another line)
        if (the line contains the pattern)
            print it */

/* To test, leverage the "here-document"/heredoc (<<) operator,
which is used in Unix/Linux shells to provide multiple lines of 
input to a program’s standard input (stdin) directly from the shell.

./my_program << EOF
This is a test line.
Another line with the pattern should be here.
This line does not match.
EOF
*/

#include <stdio.h>
#define MAXLINE 1000 // maximum input line length

int my_getline(char line[], int max);
int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; // pattern to search for

// find all lines matching pattern
main() {
    char line[MAXLINE];
    int found = 0;

    while (my_getline(line, MAXLINE) > 0)
        if (strindex(line, pattern) >= 0) {
            printf("%s", line);
            found++;
        }
        return found;
}

// getline: read line into s, return length
int my_getline(char s[], int lim) {
    int c, i;

    i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

// strindex: return index of t in s, -1 if none
int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (j=i, k=0; t[k]!='\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }
    return -1;
}