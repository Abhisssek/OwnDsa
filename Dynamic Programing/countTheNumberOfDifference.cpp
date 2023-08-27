#include<bits/stdc++.h>
using namespace std;

int countsubsetwithsum(int arr[], int n, int sum){
    int t[n+1][sum+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0){
                t[i][j]=0;
            }
            if(j==0){
                t[i][j]=1;
            }
        }
    }
        for(int i=1; i<=n; i++){
            for(int j=1; j<=sum; j++){
                if(arr[i-1]<=j){
                    t[i][j]=t[i-1][j-arr[i-1]]+t[i-1][j];
                }
                else{
                    t[i][j]=t[i-1][j];
                }
            }
      
       }
       return t[n][sum];
}


int countsubsetwithdiff(int arr[], int n, int diff){
    int sumofarray=0;
    for(int i=0; i<n; i++){
        sumofarray+=arr[i];

    }
    if((sumofarray+diff)%2!=0){
        return 0;
    }
    else{
        return countsubsetwithsum(arr,n,(sumofarray+diff)/2);
    }
}

int main(){
    int n=4;
    int arr[]={1,1,2,3};
    int diff=1;

    cout<<countsubsetwithdiff(arr,n,diff)<<endl;
    return 0;
}