#include<bits/stdc++.h>
using namespace std;

int lcs(string X, string Y, int n, int m) {
	int dp[n + 1][m + 1]; // DP - matrix

	// base case of recursion --> for initialization of dp - matrix
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= m; j++){
			if (i == 0 || j == 0){
				dp[i][j] = 0;
            }
        }   
    }
	for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++){
			if (X[i - 1] == Y[j - 1]){ // when last character is same
				dp[i][j] = 1 + dp[i - 1][j - 1];
            }    
			else{ // when last character is not same -> pick max
				dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
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

int mindekforpalindrome(string x, int n){
    return n-lps(x,n);
}

int main(){
    string x="agbcba";
    int n=x.length();
    cout<<mindekforpalindrome(x,n)<<endl;
    return 0;
}