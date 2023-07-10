#include<bits/stdc++.h>
using namespace std;


int firstocc(vector<int>arr, int n, int key){

    int s=0, e=n-1;

    int ans = -1;

    while(s<=e){
        int mid= s+ (e-s)/2;
        if(arr[mid]==key){
            ans = mid;
            e=mid-1;
        }
        if(key>arr[mid]){
            s=mid+1;

        }
        else if(key<arr[mid]){
            e=mid-1;
        }
    } return ans;

}


int lastocc(vector<int>arr, int n, int key){

    int s=0, e=n-1;

    int ans = -1;

    while(s<=e){
        int mid= s+ (e-s)/2;
        if(arr[mid]==key){
            ans = mid;
            s=mid+1;
        }
        if(key>arr[mid]){
            s=mid+1;

        }
        else if(key<arr[mid]){
            e=mid-1;
        }
    } return ans;

}

int main(){
    vector<int> arr={1,2,2,3,3,3,3,4};
    cout<<firstocc(arr,8,3);
    cout<<lastocc(arr,8,3);

    return 0;
}
