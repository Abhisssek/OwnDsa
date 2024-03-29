#include<bits/stdc++.h>
using namespace std;

bool issubsetposs(int arr[], int n, int sum){
    bool t[n+1][sum+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                t[i][j]=false;
            }
            if(j==0){
                t[i][j]=true;
            }
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(arr[i-1]<=j){
                t[i][j]= t[i-1][j-arr[i-1]] || t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    return t[n][sum];
}

bool equalsumpartitionpossible(int arr[], int n){
    int sum=0;
    for(int i=0; i<n; i++){
        sum+=arr[i];
    }
    if(sum%2!=0){
        return false;
    }
    return issubsetposs(arr,n, sum/2);
}

int main(){
    int arr[]={2,5,11,5};
    int n=4;
    if(equalsumpartitionpossible(arr,n)){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }
    return 0;
}