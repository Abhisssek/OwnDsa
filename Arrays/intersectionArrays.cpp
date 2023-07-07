#include <bits/stdc++.h>
using namespace std;


vector<int> findintersection(vector<int> &arr, int n, vector<int> &arr2, int m){
    int i=0,j=0;
    vector<int>ans;

    while(i<n&&j<m){
        if(arr[i]==arr2[j]){
            ans.push_back(arr[i]);
            i++;
            j++;
        }
        else if(arr[i]<arr2[j]){
            i++;
        }
        else{
            j++;
        }
    }

    return ans;

}


int main(){
    vector<int> arr1 ={1, 2, 3, 4, 5};
    vector<int> arr2 ={3, 4, 5, 6, 7};
    int n = arr1.size();
    int m = arr2.size();

    vector<int> intersection = findintersection(arr1, n, arr2, m);

    cout << "Intersection: ";
    for (int i = 0; i < intersection.size(); i++) {
        std::cout << intersection[i] << " ";
    }

    return 0;
}
