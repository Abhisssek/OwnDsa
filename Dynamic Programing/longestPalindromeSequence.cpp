#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, int n, int m){
    int dp[n+1][m+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            if(i==0 || j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    return dp[n][m];
}

int lps(string x, int n){
    string rev_x=x;
    reverse(rev_x.begin(), rev_x.end());
    return lcs(x,rev_x,n,n);
}

int main(){
    string x= "abcbda";
    int n= x.length();
    cout<<lps(x,n)<<endl;
    return 0;
}