#include <bits/stdc++.h>
using namespace std;

bool ispossible(vector<int>& stalls, int k, int mid, int n){
    int cowcount=1;
    int lastpos= stalls[0];

    for(int i=0; i<n; i++){
        if(stalls[i]-lastpos>=mid){
            cowcount++;
        
        if(cowcount==k){
            return true;
        }
        lastpos=stalls[i];
    }
    
 }return false;

}

int aggresivecows(vector<int>& stalls, int k){
    sort(stalls.begin(), stalls.end());
    int s=0;
    int n=stalls.size();
    int e= stalls[n-1];
    int ans =-1;
    while(s<=e){
        int mid= s+(e-s)/2;
        if(ispossible(stalls,k,mid,n)){
            ans=mid;
            s=mid+1;
        }

        else{
            e=mid-1;
        }
    }
    return ans;
}


int main(){
    vector<int> stalls={4,2,5,3,9};
    int k=2;

    cout<<aggresivecows(stalls,k);
    return 0;
}