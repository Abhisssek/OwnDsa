#include <bits/stdc++.h>
using namespace std;

bool searchmatrix(vector<vector<int>> matrix, int target){
    int row= matrix.size();
    int col= matrix[0].size();
    int start=0;
    int end= row*col;

    while(start<=end){
        int mid = start+(end-start)/2;
        int element = matrix[mid/col][mid%col];
        if(element==target){
            return true;
        }
        if(element <target){
            start =mid+1;

        }
        else{
            end=mid-1;
        }


    }

    return false;

}

int main() {
    int target=1;
    vector<vector<int>> matrix{
        {1,2,3},
        {1,5,6},
        {7,8,9}
    };


    bool found= searchmatrix(matrix,target);
    if(found){
        cout<<"found ";

    }
    else{
        cout<<"not found ";
    }

    return 0;
}
