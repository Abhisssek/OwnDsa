#include <bits/stdc++.h>
using namespace std;



int findduplicate(vector<int> &arr){
    int ans = 0;
    for (int i = 0; i < arr.size();i++) {
        ans=ans^arr[i];
    }

    for (int i = 0; i < arr.size(); i++) {
        ans = ans^i;
    }
    return ans;


}


int main(){
    vector<int> arr={4,1,2,3,4};
    cout<<findduplicate(arr);
 
    return 0;
}
