#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int i, int j){
    if(i>=j){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i; k<=j-1; k++){
        int temp_ans= solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        ans=min(ans,temp_ans);
    }
    return ans;
}

int main(){
    int n=4;
    int arr[]={10,30,5,60};
    cout<<solve(arr,1,n-1)<<endl;
    return 0;
}