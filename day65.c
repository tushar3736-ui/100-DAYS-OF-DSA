// Problem: Using DFS and parent tracking, detect if undirected graph has a cycle.

// Output:
// - YES or NO

#include <stdio.h>
#include <stdbool.h>

#define MAX 100

int adj[MAX][MAX];
bool visited[MAX];

bool dfs(int node, int parent, int n) {
    visited[node] = true;

    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node, n))
                    return true;
            }
            else if (i != parent) {
                return true;
            }
        }
    }
    return false;
}

bool hasCycle(int n) {
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, n))
                return true;
        }
    }
    return false;
}

int main() {
    int n = 4;

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][0] = adj[0][2] = 1;

    if (hasCycle(n))
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}