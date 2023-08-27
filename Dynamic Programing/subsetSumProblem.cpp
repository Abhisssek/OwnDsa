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


int main(){
    int arr[]={2,4,6,8,10};
    int n= sizeof(arr)/sizeof(arr[0]);
    int sum=18;

    if(issubsetposs(arr,n,sum)){
        cout<<"yes\n";
    }
    else{
        cout<<"no\n";
    }

    return 0;
}