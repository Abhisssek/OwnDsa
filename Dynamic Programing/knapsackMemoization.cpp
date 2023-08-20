#include<bits/stdc++.h>
using namespace std;

const int d=1000;
int t[d][d];

int knapsack(int wt[],int val[], int w, int n){
    if(n==0 || w==0){
        return 0;
    }

    if(t[n][w]!=-1){
        return t[n][w];
    }

    else{
        if(wt[n-1]<=w){
            t[n][w]=max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
        }
        else if(wt[n-1]>w){
            t[n][w]=knapsack(wt,val,w,n-1);
        }
        return t[n][w];
    }
}

int main(){
    memset(t,-1,sizeof(t));

    int n=4;
    int wt[]={2,3,4,5};
    int val[]={3,4,5,6};
    int w=5;

    int result=knapsack(wt,val,w,n);
    cout<<"max value: "<<result<<endl;

    return 0;
}