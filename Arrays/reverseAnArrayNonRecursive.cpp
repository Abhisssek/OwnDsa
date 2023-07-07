#include <bits/stdc++.h>
using namespace std;



void reverse(int arr[], int n){
   
    int start =0;
    int end =n-1;

    while(start < end){
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    

}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[5]={0,1,2,3,4};
    reverse(arr,5);

    printArray(arr, 5);
}
