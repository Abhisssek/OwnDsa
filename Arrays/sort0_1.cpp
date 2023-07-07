#include <bits/stdc++.h>
using namespace std;



void sortOne(int arr[], int n){

    int left=0, right =n-1;
    while(left<right){
        while(arr[left]==0 && left<right){
            left++;
    }
    while(arr[right]==1 && left<right){
        right--;
    }

    if(left<right){
        swap(arr[left],arr[right]);
        left++;
        right--;
    }
    
    }
}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[5]={0,1,1,0,1};
    sortOne(arr,5);
    printArray(arr, 5);
    return 0;
}
