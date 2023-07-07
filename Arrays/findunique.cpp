#include <bits/stdc++.h>
using namespace std;

int findunique(int *arr, int n){
int ans = 0;
for (int i = 0; i < n; i++) {
        ans = ans^arr[i];
   }
   return ans;
}


int main(){
    int arr[5]={2,1,2,3,3};
    cout<<findunique(arr, 5);
    return 0;
}
