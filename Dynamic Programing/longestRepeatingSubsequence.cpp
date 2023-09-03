#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m){
    int dp[n+1][m+1];

      for(int i=0; i<=n;i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1] && i!=j){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int main(){
    string x="aabcbddfcf";
    int n=x.length();
    cout<<lcs(x,x,n,n)<<endl;
    return 0;
}