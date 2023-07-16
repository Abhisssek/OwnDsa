#include <bits/stdc++.h>
using namespace std;

bool issorted(int arr[], int size){
    if(size==0||size==1){
        return true;
    }

    if(arr[0]>arr[1]){
        return false;
    }

    else{
        bool remainingpart= issorted(arr+1,size-1);
        return remainingpart;
    }
}

int main(){
    int arr[6]={9,2,4,9,9,9};
    bool ans= issorted(arr,5);

    if(ans){
        cout<<"sorted"<<endl;
    }

    else{
        cout<<"not sorted"<<endl;
    }
    return 0;
}