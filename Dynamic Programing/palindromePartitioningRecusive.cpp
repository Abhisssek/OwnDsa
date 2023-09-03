#include<bits/stdc++.h>
using namespace std;

bool ispalindrome(string x, int i, int j){
    while(i<=j){
        if(x[i]!=x[j]){
            return false;
        }
            i++,j--;
    }
    return true;

}
int solve(string x, int i, int j){
    if(i>=j || ispalindrome(x,i,j)){
        return 0;
    }
    int ans=INT_MAX;
    for(int k=i; k<j; k++){
        int tempans=solve(x,i,k)+solve(x,k+1,j)+1;
        ans=min(ans,tempans);
    }
    return ans;
}


int main(){
    string x="aecar";
    cout<<solve(x,0,x.length()-1)<<endl;
    return 0;
}