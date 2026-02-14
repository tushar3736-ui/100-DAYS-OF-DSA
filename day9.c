// Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

// Input:
// - Single line: a lowercase string containing only alphabetic characters (no spaces)

// Output:
// - Print the transformed code name after applying the mirror operation

// Example:
// Input:
// hello

// Output:
// olleh

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    scanf("%s", s);

    int n = strlen(s);
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }

    return 0;
}
