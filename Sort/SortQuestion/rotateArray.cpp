#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

void rotate(vector<int>& arr, int k){
   int n= arr.size();
   vector<int> temp(n);
    for (int i=0; i<n; i++){
        temp[(i+k)%n]=arr[i];
    }

    for(int i=0; i<arr.size();i++){
        arr[i]=temp[i];
    }
}

int main(){
    vector <int> arr= {6,2,8,4,100};
    rotate(arr,2);
    printArray(arr,5);
    return 0;
}