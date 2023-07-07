#include <bits/stdc++.h>
using namespace std;



int majoelement(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int n= arr.size();
    return arr[n/2];


}


int main(){
    vector<int> arr={4,1,2,3,4};
    cout<<majoelement(arr);
 
    return 0;
}
