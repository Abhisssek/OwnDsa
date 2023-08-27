#include<bits/stdc++.h>
using namespace std;

int countsubsetwithsum(vector<int>& nums, int sum){
    int n=nums.size();
    int t[n+1][sum+1];
    t[0][0]=1;
    int k=1;

    for(int i=0; i<=n; i++){
        for(int j=0; j<=sum; j++){
            if(i==0 && j>0){
                t[i][j]=0;
            }
            if(j==0 && j>0){
                t[i][j]=pow(2,k);
                k++;
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++){
            if(nums[i-1]<=j){
                t[i][j]=t[i-1][j-nums[i-1]]+t[i-1][j];
            }
            else{
                t[i][j]=t[i-1][j];
            }
        }
    }
}

int findtargetsumways(vector<int>& nums, int diff){
    int n= nums.size();
    int sumofarray=0;
    for(int i=0; i<n; i++){
        sumofarray+=nums[i];

    }
    if((sumofarray+diff)%2!=0){
        return 0;
    }
    else{
        return countsubsetwithsum(nums,(sumofarray+diff)/2);
    }
}


int main(){
    vector<int> nums={1,1,2,3};
    int diff=1;
    int ways= findtargetsumways(nums,diff);
    cout<<"number of ways to achive the target sum: "<<ways<<endl;
    return 0;
}