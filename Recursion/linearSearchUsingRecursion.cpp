#include <bits/stdc++.h>
using namespace std;

bool linearsearch(int arr[], int size, int k){
    if(size==0){
        return false;
    }

    if(arr[0]==k){
        return true;
    }

    else{
        bool remainingpart= linearsearch(arr+1,size-1,k);
        return remainingpart;
    }
}

int main(){
    int arr[6]={9,2,4,7,8,11};
    bool ans= linearsearch(arr,6,0);

    if(ans){
        cout<<"present"<<endl;
    }

    else{
        cout<<"not present"<<endl;
    }
    return 0;
}