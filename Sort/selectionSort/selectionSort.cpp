#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int selectionsort(vector<int>& arr, int n){
    for (int i=0; i<n-1; i++){
        int min_index=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[min_index]){
                min_index=j;
               
            }
        }
        swap(arr[min_index], arr[i]);
    }
}

int main(){
    vector <int> arr= {6,2,8,4,100};
    selectionsort(arr,5);
    printArray(arr,5);
    return 0;
}