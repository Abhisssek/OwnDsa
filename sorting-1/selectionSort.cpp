#include<bits/stdc++.h>
using namespace std;



void selectionSort(int arr[], int n){
    for(int i=0; i<n-1;i++){
        int mini=i;
        for(int j=i+1; j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[mini], arr[i]);
    }
    
}



int main(){
    int arr[5]={13,9,83,11,7};

    int n = sizeof(arr)/sizeof(arr[0]);

    selectionSort(arr,n);


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}