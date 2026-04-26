// Problem: Implement Merge Sort - Implement the algorithm.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the sorted array or search result

// Example:
// Input:
// 5
// 64 34 25 12 22

// Output:
// 12 22 25 34 64


#include <stdio.h>

void merge(int arr[],int l,int m,int r){
    int i=l,j=m+1,k=0;
    int temp[r-l+1];
    while(i<=m&&j<=r){
        if(arr[i]<=arr[j]) temp[k++]=arr[i++];
        else temp[k++]=arr[j++];
    }
    while(i<=m) temp[k++]=arr[i++];
    while(j<=r) temp[k++]=arr[j++];
    for(i=l,k=0;i<=r;i++,k++) arr[i]=temp[k];
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}