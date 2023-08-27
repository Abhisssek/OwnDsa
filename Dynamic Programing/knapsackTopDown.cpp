#include<bits/stdc++.h>
using namespace std;


int knapsack(int wt[], int val[], int w, int n){
    int t[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }

            else if(wt[i-1]<=j){
                int val1= val[i-1]+ t[i-1][j-wt[i-1]];
                int val2= t[i-1][j];

                t[i][j]=max(val1,val2);
            }
            else if(wt[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }
        return t[n][w];
}

int main(){
    int n=4;
    int val[]={5,10,15,7};
    int wt[]={2,4,3,4};
    int w=7;

    cout<<"maximum profit: "<<knapsack(wt,val,w,n)<<endl;
    return 0;
}