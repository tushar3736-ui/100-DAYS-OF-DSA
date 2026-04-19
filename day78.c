// Problem Statement
// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)


#include <stdio.h>
#include <limits.h>

#define MAX 100

int minKey(int key[], int visited[], int n){
    int min = INT_MAX, min_index = -1;
    for(int i = 1; i <= n; i++){
        if(!visited[i] && key[i] < min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int graph[MAX][MAX];

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            graph[i][j] = 0;

    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int key[MAX], visited[MAX];

    for(int i=1;i<=n;i++){
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;

    int total = 0;

    for(int i=1;i<=n;i++){
        int u = minKey(key, visited, n);
        visited[u] = 1;
        total += key[u];

        for(int v=1;v<=n;v++){
            if(graph[u][v] && !visited[v] && graph[u][v] < key[v]){
                key[v] = graph[u][v];
            }
        }
    }

    printf("%d", total);

    return 0;
}