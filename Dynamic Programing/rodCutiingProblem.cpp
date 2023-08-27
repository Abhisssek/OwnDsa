#include<bits/stdc++.h>
using namespace std;

int getmaxprofit(int length[], int price[], int n, int l) {
	int dp[n + 1][l + 1];
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= l; j++)
			if (j == 0 || i == 0)
				dp[i][j] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= l; j++) {
			if (length[i - 1] <= j) {
				dp[i][j] = max(dp[i - 1][j],
				               price[i - 1] + dp[i][j - length[i - 1]]);
			}
			else
				dp[i][j] = dp[i - 1][j];
		}
	}

	return dp[n][l];
}

int main(){
    int n=8;
    int length[]={1,2,3,4,5,6,7,8};
    int price[]={1,5,8,9,10,17,17,20};
    int l=8;
    cout<<getmaxprofit(length,price,n,l);
    return 0;
}