// Problem: Given a sorted array of integers and a target value x, implement the Lower Bound and Upper Bound operations using Binary Search.

// Lower Bound: The index of the first element in the array that is greater than or equal to x.
// Upper Bound: The index of the first element in the array that is strictly greater than x.

// Input:
// - First line: integer n representing the size of the array
// - Second line: n space-separated sorted integers
// - Third line: integer x (the target value)

// Output:
// - Print two integers:
//   1) Index of the lower bound of x
//   2) Index of the upper bound of x

// Example:
// Input:
// 7
// 1 2 4 4 4 5 7
// 4

// Output:
// 2 5

// Explanation:
// For the given array [1, 2, 4, 4, 4, 5, 7] and x = 4:
// - The lower bound is at index 2, which is the first occurrence of 4.
// - The upper bound is at index 5, which is the first element greater than 4 (i.e., 5).
// Binary Search is used to find both bounds efficiently in O(log n) time.


#include <stdio.h>

int lower_bound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int upper_bound(int arr[], int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (arr[mid] <= x)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

int main() {
    int n, x;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    scanf("%d", &x);

    printf("%d %d", lower_bound(arr, n, x), upper_bound(arr, n, x));

    return 0;
}