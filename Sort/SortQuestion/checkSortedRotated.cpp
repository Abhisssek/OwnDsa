#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

bool check(vector<int>& arr){
    int cnt=0;
    for (int i=1; i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            cnt++;
        }
    }

    if(arr[arr.size()-1]>arr[0]){
        cnt++;
    }
    return cnt<=1;
}

int main(){
    vector <int> arr= {2,4,6,7,0};
    bool result = check(arr);

    if(result){
        cout<<"sorted rotated Array";
    }
    else{
        cout<<"not Sorted Rotated Array";
    }

    // printArray(arr,5);
    return 0;
}