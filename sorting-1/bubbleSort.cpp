#include<bits/stdc++.h>
using namespace std;



void bubbleSort(int arr[], int n){
   for(int i = n-1; i>=1; i--){
    for(int j =0; j<i; j++){
        if(arr[j]>arr[j+1]){
            swap(arr[j], arr[j+1]);
        }
    }
   }
}






int main(){
    int arr[]={13,9,83,11,7,99,7219,2,12123,32,1,2332432,12,124343352,0s};

    int n = sizeof(arr)/sizeof(arr[0]);

    bubbleSort(arr,n);


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}