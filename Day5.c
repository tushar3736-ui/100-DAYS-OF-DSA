// Problem: A system receives two separate logs of user arrival times from two different servers. Each log is already sorted in ascending order. Your task is to create a single chronological log that preserves the correct order of arrivals.

// Input:
// - First line: integer p (number of entries in server log 1)
// - Second line: p sorted integers representing arrival times from server 1
// - Third line: integer q (number of entries in server log 2)
// - Fourth line: q sorted integers representing arrival times from server 2)

// Output:
// - Print a single line containing all arrival times in chronological order, separated by spaces
// Example:
// Input:
// 5
// 10 20 30 50 70
// 4
// 15 25 40 60

// Output:
// 10 15 20 25 30 40 50 60 70
#include <stdio.h>

void mergeLogs(int p, int log1[], int q, int log2[]) {
    int i = 0;
    int j = 0;

    while (i < p && j < q) {
        if (log1[i] <= log2[j]) {
            printf("%d ", log1[i]);
            i++;
        } else {
            printf("%d ", log2[j]);
            j++;
        }
    }

    while (i < p) {
        printf("%d%s", log1[i], (i == p - 1 && j == q) ? "" : " ");
        i++;
    }

    while (j < q) {
        printf("%d%s", log2[j], (j == q - 1) ? "" : " ");
        j++;
    }
    printf("\n");
}

int main() {
    int p, q;
    if (scanf("%d", &p) != 1) return 0;
    int log1[p];
    for (int i = 0; i < p; i++) scanf("%d", &log1[i]);

    if (scanf("%d", &q) != 1) return 0;
    int log2[q];
    for (int i = 0; i < q; i++) scanf("%d", &log2[i]);

    mergeLogs(p, log1, q, log2);

    return 0;
}