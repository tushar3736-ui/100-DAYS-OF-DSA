// Problem: Read a string and check if it is a palindrome using two-pointer comparison.

// Input:
// - Single line: string s

// Output:
// - Print YES if palindrome, otherwise NO

// Example:
// Input:
// level

// Output:
// YES

#include <stdio.h>
#include <string.h>

int main() {
    char s[30];
    scanf("%s", s);

    int i = 0, j = strlen(s) - 1;

    while (i < j) {
        if (s[i] != s[j]) {
            printf("NO");
            return 0;
        }
        i++;
        j--;
    }

    printf("YES");
    return 0;
}
