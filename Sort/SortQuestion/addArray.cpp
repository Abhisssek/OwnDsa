#include <bits/stdc++.h>
using namespace std;

void printArray(vector<int>& arr, int n){
    for (int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

vector<int> reverse (vector<int> v){
    int s=0;
    int e=v.size()-1;
    while(s<e){
        swap(v[s++], v[e--]);
    }
    return v;
}

vector<int> findarray(vector<int>& a, int n, vector<int>& b, int m){
    int i=n-1;
    int j=m-1;
    vector<int> ans;

    int carry=0;

    while(i>=0&&j>=0){
        int val1=a[i];
        int val2= b[j];
        int sum = val1+val2+carry;
        carry= sum/10;
        sum= sum%10;
        ans.push_back(sum);
        i--;
        j--;
    }


    while(i>=0){
        int sum= a[i]+carry;
        carry= sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }


    while(j>=0){
        int sum= b[j]+carry;
        carry= sum/10;
        int value= sum%10;
        ans.push_back(value);
        j--;
    }


    while(carry!=0){
        int sum= carry;
        carry=sum/10;
        sum=sum%10;
        ans.push_back(sum);

    }
    return reverse(ans);
}


int main(){
    vector <int> arr= {1,2,3,4};
    vector <int> arr2= {6,7};
    vector<int> result= findarray(arr,arr.size(),arr2,arr2.size());
   for(int num : result){
    cout<<num<<" ";
   }
    return 0;
}



//doubt about this code need some improvement