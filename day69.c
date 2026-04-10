//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define V 100

typedef struct {
    int node;
    int dist;
} HeapNode;

typedef struct {
    HeapNode arr[V * V];
    int size;
} MinHeap;

void swap(HeapNode *a, HeapNode *b){
    HeapNode t = *a;
    *a = *b;
    *b = t;
}

void heapifyUp(MinHeap *h, int i){
    while(i && h->arr[(i-1)/2].dist > h->arr[i].dist){
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

void heapifyDown(MinHeap *h, int i){
    int l = 2*i+1, r = 2*i+2, smallest = i;
    if(l < h->size && h->arr[l].dist < h->arr[smallest].dist) smallest = l;
    if(r < h->size && h->arr[r].dist < h->arr[smallest].dist) smallest = r;
    if(smallest != i){
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

void push(MinHeap *h, int node, int dist){
    h->arr[h->size].node = node;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

HeapNode pop(MinHeap *h){
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    heapifyDown(h, 0);
    return root;
}

int isEmpty(MinHeap *h){
    return h->size == 0;
}

void dijkstra(int graph[V][V], int n, int src){
    int dist[V];
    for(int i=0;i<n;i++) dist[i] = INT_MAX;

    MinHeap h;
    h.size = 0;

    dist[src] = 0;
    push(&h, src, 0);

    while(!isEmpty(&h)){
        HeapNode cur = pop(&h);
        int u = cur.node;

        for(int v=0; v<n; v++){
            if(graph[u][v] && dist[u] + graph[u][v] < dist[v]){
                dist[v] = dist[u] + graph[u][v];
                push(&h, v, dist[v]);
            }
        }
    }

    for(int i=0;i<n;i++)
        printf("%d ", dist[i]);
}

int main(){
    int n = 5;
    int graph[V][V] = {
        {0,10,0,30,100},
        {0,0,50,0,0},
        {0,0,0,0,10},
        {0,0,20,0,60},
        {0,0,0,0,0}
    };

    dijkstra(graph, n, 0);
    return 0;
}