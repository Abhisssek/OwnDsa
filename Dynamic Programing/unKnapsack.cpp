#include<bits/stdc++.h>
using namespace std;

int unknapsack(int wt[], int val[], int w, int n){
    int t[n+1][w+1];

    for(int i=0; i<=n; i++){
        for(int j=0; j<=w; j++){
            if(i==0 || j==0){
                t[i][j]=0;
            }
            else if(wt[i-1]<=j){
                int val1= val[i-1]+t[i][j-wt[i-1]];
                int val2= t[i-1][j];
                t[i][j]=max(val1,val2);
            }
            else if(wt[i-1]>j){
                t[i][j]=t[i-1][j];
            }
        }
    }return t[n][w];
}

int main(){
    int n=4;
    int val[]={10,40,80,50};
    int wt[]={5,4,6,3};
    int w=10;

    cout<<unknapsack(wt,val,w,n)<<endl;
    return 0;
}