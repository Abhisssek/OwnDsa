#include <bits/stdc++.h>
using namespace std;

bool search(int arr[], int size, int key){
    for (int i = 0; i <size; i++){
        if (arr[i] == key) return true;
    }
    return false;
}

int main(){
   
    int arr[5]={1,2,3,4,5};
    int key;
    cin >> key;
    bool found=search(arr,5,key);
    if(found){
        cout<<"Found ";
    }
    else{
        cout<<"No key found"<<endl;
    }
    return 0;
}


