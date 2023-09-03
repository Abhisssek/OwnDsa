#include<bits/stdc++.h>
using namespace std;

string scs(string x, string y, int n, int m){
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
            if(x[i-1]==y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int i=n, j=m;
    string scs="";
    while(i>0 && j>0){
        if(x[i-1]==y[j-1]){
            scs+=x[i-1];
            i--,j--;
        }
        else if(dp[i][j-1]>dp[i-1][j]){
            scs+=y[j-1];
            j--;
        }
        else{
            scs+=x[i-1];
            i--;
        }
    }
    while(i>0){
        scs+=x[i-1];
        i--;
    }
    while(j>0){
        scs+=y[j-1];
        j--;
    }
    reverse(scs.begin(), scs.end());
    return scs;
}

int main(){
    string x="abc", y="acdg";
    int n=x.length(), m=y.length();
    cout<<scs(x,y,n,m)<<endl;
    return 0;
}