#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w, int n){
    if(n==0 || w==0){
        return 0;
    }

    if(wt[n-1]<=w){
        return max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1),knapsack(wt,val,w,n-1));
    }

    else if(wt[n-1]>w){
        return knapsack(wt,val,w,n-1);
    }

    else{
        return -1;
    }
}

int main(){
    int n=3; 
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int w=60;

    cout<<"maximum value: "<<knapsack(wt,val,w,n)<<endl;\
    return 0;
}