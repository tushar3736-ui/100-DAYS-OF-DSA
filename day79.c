// Problem Statement
// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX 100

int n,m;
int graph[MAX][MAX];

int minDist(int dist[],int vis[]){
    int min=INT_MAX,idx=-1;
    for(int i=1;i<=n;i++){
        if(!vis[i]&&dist[i]<=min){
            min=dist[i];
            idx=i;
        }
    }
    return idx;
}

void dijkstra(int src){
    int dist[MAX],vis[MAX]={0};
    for(int i=1;i<=n;i++) dist[i]=INT_MAX;
    dist[src]=0;

    for(int i=1;i<=n-1;i++){
        int u=minDist(dist,vis);
        vis[u]=1;
        for(int v=1;v<=n;v++){
            if(!vis[v]&&graph[u][v]&&dist[u]!=INT_MAX&&dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }

    for(int i=1;i<=n;i++) printf("%d ",dist[i]);
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            graph[i][j]=0;

    for(int i=0;i<m;i++){
        int u,v,w;
        scanf("%d%d%d",&u,&v,&w);
        graph[u][v]=w;
        graph[v][u]=w;
    }

    int src;
    scanf("%d",&src);

    dijkstra(src);
    return 0;
}