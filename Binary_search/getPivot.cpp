#include<bits/stdc++.h>
using namespace std;


int getpivot(vector<int> v, int n){
    int s=0, e=n-1;
    while(s<e) {
        int mid=s+(e-s)/2; 
        if(v[mid]>=v[0]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }return s;
}

int main(){
    vector<int> arr={2,2,3,3,3,3,4};
    cout<<getpivot(arr,7)<<endl;

    return 0;
}
