#include<bits/stdc++.h>
using namespace std;

const int d=1000;
int t[d][d];

int Solve(int arr[], int i, int j) {
	if (i >= j) {
		t[i][j] = 0;
		return 0;
	}

	if (t[i][j] != -1)// when it is not zero means return the value from the table other than -1
		return t[i][j]; 

	int ans = INT_MAX;
	for (int k = i; k <= j - 1; k++) {
		int temp_ans = Solve(arr, i, k) + Solve(arr, k + 1, j) + arr[i - 1] * arr[k] * arr[j];
		ans = min(ans, temp_ans);
	}

	return t[i][j] = ans; // store it in table 
}

int main(){
    int n=4;
    int arr[]={1,2,3,4};
    memset(t,-1,sizeof(t));
    cout<<Solve(arr,1,n-1)<<endl;
    return 0;
}