#include <bits/stdc++.h>
using namespace std;



void swapAlternate(int arr[], int n){

    for(int i=0; i<n; i+=2){
        if(i+1<n){
        swap(arr[i], arr[i+1]);
        }
    }
    

}

void printArray(int arr[], int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    int arr[5]={0,1,2,3,4};
    swapAlternate(arr,5);
    printArray(arr, 5);
    return 0;
}
