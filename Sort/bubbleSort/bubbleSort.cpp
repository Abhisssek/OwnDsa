#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int bubblesort(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        bool swapped=false;
        for (int j=0; j<n-1; j++){
            if (arr[j]>arr[j+1]){
                swap (arr[j], arr[j+1]);
                swapped =true;
            }
        }
    if(swapped==false){
        break;
    }

    }
}

int main(){
    vector <int> arr= {6,2,8,4,10};
    bubblesort(arr,5);
    printArray(arr,5);
    return 0;
}