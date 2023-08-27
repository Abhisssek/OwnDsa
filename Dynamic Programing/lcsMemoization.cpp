#include<bits/stdc++.h>
using namespace std;

int dp[1001][1001];
int lcs(string x, string y, int n, int m){
    if(n==0 || m==0){
        dp[n][m]=0;
    }
    if(dp[n][m]!=-1){
        return dp[n][m];
    }
    if(x[n-1]==y[m-1]){
        dp[n][m]=1+lcs(x,y,n-1,m-1);
    }
    else{
        dp[n][m]=max(lcs(x,y,n-1,m), lcs(x,y,n,m-1));
    }
    return dp[n][m];
}


int main(){
    string x= "AGGBAC";
    string y= "AGBCRC";
    int n= x.length(), m=y.length();
    memset(dp,-1,sizeof(dp));
    cout<<lcs(x,y,n,m)<<endl;
    return 0;
}