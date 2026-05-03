// Problem: Implement merge sort (divide, sort halves, merge).
// Print sorted array.
#include<stdio.h>
void merge(int arr[], int low, int mid, int high){
    int left = low ; 
    int right = mid+1 ; 
    int ans [high-low+1] ; 
    int i = 0 ; 
    while(left<=mid && right<=high){
        if(arr[left]<arr[right]){
            ans[i++] = arr[left++] ;  
        }
        else{
            ans[i++] = arr[right++] ; 
        }
    }
    while(right<=high){
        ans[i++] = arr[right++] ; 
    }
    while(left<=mid){
        ans[i++] = arr[left++] ; 
    }
    
    for(int i = low ; i<=high ; i++){
        arr[i] = ans[i-low] ; 
    }
}
void merge_sort(int arr[], int low, int high){
    if(low<high){
        int mid = low + (high-low)/2 ; 
        merge_sort(arr,low,mid) ; 
        merge_sort(arr,mid+1,high) ; 
        merge(arr,low,mid,high) ; 
    }
}
int main(){
    int n = 5 ; 
    int arr[] = {5,4,3,2,1} ;  
    merge_sort(arr,0,n-1) ; 
    for(int i = 0 ; i<n ; i++){
        printf("%d ",arr[i]) ; 
    }
    return 0 ; 
}