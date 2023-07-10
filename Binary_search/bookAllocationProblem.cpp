#include <bits/stdc++.h>
using namespace std;

bool ispossible (vector<int> arr, int n, int m, int mid){
    int studentcount=1;
    int pagesum=0;


    for(int i=0; i<n; i++){
        if(pagesum+arr[i]<=mid){
            pagesum+=arr[i]; 
        }

        else{
            studentcount++;
            if(studentcount>m||arr[i]>mid){
                return false;

            }
            pagesum=arr[i];
        }
        if(studentcount>m){
            return false;
        }
    }return true;
}

int allocatebook(vector<int> arr, int n, int m){
    int s=0;
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];

    }
    int e=sum;
    int ans =-1;
    while(s<=e){
        int mid = s+(e-s)/2;
        if(ispossible(arr,n,m,mid)){
            ans =mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        
    }return ans;
}


int main() {
    // Create a vector to store the book pages
    vector<int> arr = {10, 20, 30, 40}; // Example input, you can modify this

    int n = arr.size(); // Number of books
    int m = 2; // Number of students, you can modify this

    // Call the allocatebook function to find the minimum number of pages
    int minPages = allocatebook(arr, n, m);

    // Print the result
    cout << "Minimum number of pages per student: " << minPages << endl;

    return 0;
}

