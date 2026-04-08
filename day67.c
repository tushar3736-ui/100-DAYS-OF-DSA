// Problem: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include<stdio.h>

int stack[100], top = -1;
int visited[100];

void dfs(int v, int n, int adj[n][n]){
    visited[v] = 1;

    for(int i = 0; i < n; i++){
        if(adj[v][i] && !visited[i]){
            dfs(i, n, adj);
        }
    }

    stack[++top] = v;
}

int main(){
    int n = 6;

    int adj[6][6] = {
        {0,1,0,1,0,0},
        {0,0,1,0,0,0},
        {0,0,0,0,0,0},
        {0,0,1,0,1,0},
        {0,0,0,0,0,1},
        {0,0,0,0,0,0}
    };

    for(int i = 0; i < n; i++){
        visited[i] = 0;
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            dfs(i, n, adj);
        }
    }

    while(top != -1){
        printf("%d ", stack[top--]);
    }

    return 0;
}