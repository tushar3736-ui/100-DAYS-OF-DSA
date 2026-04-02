// Problem: Build a graph with n vertices and m edges using adjacency matrix representation.
// The graph may be directed or undirected.

// Input:
// - n (vertices)
// - m (edges)
// - m pairs (u, v)

// Output:
// - n x n adjacency matrix

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    int flag = 1;
    
    for(int i = 0; i <= (n - 2) / 2; i++) {
        if(2*i + 1 < n && arr[i] > arr[2*i + 1]) {
            flag = 0;
            break;
        }
        if(2*i + 2 < n && arr[i] > arr[2*i + 2]) {
            flag = 0;
            break;
        }
    }
    
    if(flag)
        printf("YES");
    else
        printf("NO");
    
    return 0;
}