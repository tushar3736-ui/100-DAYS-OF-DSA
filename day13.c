// Problem: You are given a rectangular matrix of integers. Starting from the outer boundary, traverse the matrix in a clockwise manner and continue moving inward layer by layer until all elements are visited.

// Input:
// - First line: two integers r and c representing the number of rows and columns
// - Next r lines: c integers each representing the matrix elements

// Output:
// - Print all visited elements in the order of traversal, separated by spaces

// Example:
// Input:
// 3 3
// 1 2 3
// 4 5 6
// 7 8 9

// Output:
// 1 2 3 6 9 8 7 4 5

// Explanation:
// The traversal begins along the top row, proceeds down the rightmost column, then moves across the bottom row in reverse, and finally goes up the leftmost column. The same pattern repeats for the inner submatrix.

// Test Cases:

// Test Case 1:
// Input:
// 2 3
// 1 2 3
// 4 5 6
// Output:
// 1 2 3 6 5 4

// Test Case 2:
// Input:
// 3 1
// 7
// 8
// 9
// Output:
// 7 8 9

#include <stdio.h>
int main() {
    int r, c;
    scanf("%d %d", &r, &c);
    int a[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    while (top <= bottom && left <= right) {
        for (int j = left; j <= right; j++)
            printf("%d ", a[top][j]);
        top++;
        for (int i = top; i <= bottom; i++)
            printf("%d ", a[i][right]);
        right--;
        if (top <= bottom) {
            for (int j = right; j >= left; j--)
                printf("%d ", a[bottom][j]);
            bottom--;
        }
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                printf("%d ", a[i][left]);
            left++;
        }
    }
    return 0;
}
