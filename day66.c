// Problem: Detect cycle in directed graph using DFS and recursion stack.

// Output:
// - YES if cycle exists

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];
bool recStack[MAX];

bool dfs(int node, int n) {
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i] && dfs(i, n))
                return true;
            else if (recStack[i])
                return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, n))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 3;

    adj[0][1] = 1;
    adj[1][2] = 1;
    adj[2][0] = 1;

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}