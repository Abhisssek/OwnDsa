#include <bits/stdc++.h>
using namespace std;

int getmini(int arr[], int n){
    int mini = INT_MAX;
    for(int i=0; i<n; i++){
        mini = min (mini, arr[i]);
    }
    return mini;
}

int getmax(int arr[], int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        maxi = max (maxi, arr[i]);
    }
    return maxi;
}


int main(){
    int size;
    cin >> size;
    int num[100];
    for (int i=0; i<size; i++){
        cin >> num[i];
    }
    cout<<getmax(num,size);
    cout<<getmini(num,size);
    return 0;
}