// Problem Statement
// Given an array of integers where each element represents the number of pages in a book, and m students, allocate books such that each student gets at least one book and the maximum number of pages assigned to a student is minimized.

// Books must be allocated in contiguous order.

// Input Format
// n m
// n space-separated integers representing pages in books

// Output Format
// Print the minimum possible value of the maximum pages assigned to any student.

// Sample Input
// 4 2
// 12 34 67 90

// Sample Output
// 113

// Explanation
// One optimal allocation is:
// Student 1: 12 + 34 + 67 = 113
// Student 2: 90
// Maximum pages = 113 (minimum possible).

#include <stdio.h>

int isPossible(int arr[], int n, int m, int maxPages) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxPages)
            return 0;
        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
            if (students > m)
                return 0;
        } else {
            pages += arr[i];
        }
    }
    return 1;
}

int allocateBooks(int arr[], int n, int m) {
    int low = 0, high = 0, result = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    while (low <= high) {
        int mid = (low + high) / 2;
        if (isPossible(arr, n, m, mid)) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("%d", allocateBooks(arr, n, m));
    return 0;
}
