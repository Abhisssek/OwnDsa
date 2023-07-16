#include <bits/stdc++.h>
using namespace std;

bool binarysearch(int arr[], int s, int e, int k){
    if(s>e){
        return false;
    }
    int mid = s+ (e-s)/2;
    if(arr[mid]==k){
        return true;
    }

    if(arr[mid<k]){
        return binarysearch(arr,mid+1,e,k);
    }

    else{
        return binarysearch(arr,s,mid-1,k);
    }



}

int main(){
    int arr[6]={9,2,4,7,8,11};
    bool ans= binarysearch(arr,0,5,5);

    if(ans){
        cout<<"present"<<endl;
    }

    else{
        cout<<"not present"<<endl;
    }
    return 0;
}