// Problem: Given a weighted graph with n vertices, implement the Floyd-Warshall algorithm to compute the shortest distances between every pair of vertices. The graph may contain positive or negative edge weights, but it does not contain any negative weight cycles.

// Input:
// - First line: integer n representing the number of vertices
// - Next n lines: n space-separated integers representing the adjacency matrix of the graph
//   (use -1 to indicate no direct edge between two vertices)

// Output:
// - Print the shortest distance matrix where the value at row i and column j represents the shortest distance from vertex i to vertex j

// Example:
// Input:
// 4
// 0 5 -1 10
// -1 0 3 -1
// -1 -1 0 1
// -1 -1 -1 0

// Output:
// 0 5 8 9
// -1 0 3 4
// -1 -1 0 1
// -1 -1 -1 0

// Explanation:
// The Floyd-Warshall algorithm works by considering each vertex as an intermediate point and updating the shortest paths between all pairs of vertices. For example, the shortest path from vertex 1 to vertex 3 is improved via vertex 2 with total cost 8. This process is repeated for all vertices, resulting in the final shortest distance matrix.


#include<stdio.h>
#define INF 1000000000

int main(){
int n,i,j,k;
scanf("%d",&n);
int a[n][n];

for(i=0;i<n;i++){
for(j=0;j<n;j++){
scanf("%d",&a[i][j]);
if(a[i][j]==-1 && i!=j) a[i][j]=INF;
}
}

for(k=0;k<n;k++){
for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][k]+a[k][j]<a[i][j])
a[i][j]=a[i][k]+a[k][j];
}
}
}

for(i=0;i<n;i++){
for(j=0;j<n;j++){
if(a[i][j]==INF) printf("-1 ");
else printf("%d ",a[i][j]);
}
printf("\n");
}
return 0;
}