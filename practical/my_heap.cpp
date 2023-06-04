#include <bits/stdc++.h>
using namespace std;

void max_heapify(int arr[],int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=2*i+2;

    if(l<n && arr[l]>arr[largest]){
        largest=l;
    }
    if(r<n && arr[r]>arr[largest]){
        largest=r;
    }

    if(largest!=i){
        swap(arr[i],arr[largest]);
        max_heapify(arr,n,largest);
        
    }
}

void heap_sort(int arr[],int n){
    for(int i=n/2-1;i>=0;i--){
        max_heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
        max_heapify(arr,i,0);
        
    }
    
}

int main(){
    int n;
    cout<<"Enter number of elements in array = ";
    cin>>n;

    int a[n];
    cout<<"enter array elements = ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    cout<<"original array = ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"After sorting = ";
    heap_sort(a,n);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    




    return 0;
}