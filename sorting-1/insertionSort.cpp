#include<bits/stdc++.h>
using namespace std;



void insertionSort(int arr[], int n){
    for(int i=0; i<=n-1;i++){
        int j=i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j-1], arr[j]);
            j--;
        }
    }
    
}



int main(){
    int arr[5]={13,9,83,11,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    insertionSort(arr,n);


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}