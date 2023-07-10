#include<bits/stdc++.h>
using namespace std;


int findpivot(vector<int> v){
    int s=0, e=v.size()-1;
    while(s<e) {
        int mid=s+(e-s)/2; 
        if(v[mid]<v[mid+1]){
            s=mid+1;
        }
        else{
            e=mid;
        }
    }return s;
}

int main(){
    vector<int> arr={2,2,3,3,3,3,4};
    cout<<findpivot(arr)<<endl;

    return 0;
}
