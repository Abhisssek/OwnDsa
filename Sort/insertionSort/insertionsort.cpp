#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int insertionsort(int n, vector<int>& arr){
    for (int i=0; i<n-1; i++){
        int temp=arr[i];
        int j=i-1;
        for(; j>=0; j--){
            if(arr[j]>temp){
                arr[j+1]=arr[j];

            }
            else{
                break;
            }
        }
         arr[j+1]=temp;
    }
}

int main(){
    vector <int> arr= {6,2,8,4,100};
    insertionsort(5,arr);
    printArray(arr,5);
    return 0;
}