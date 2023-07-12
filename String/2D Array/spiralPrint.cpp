#include <bits/stdc++.h>
using namespace std;

vector<int> spiralprint(vector<vector<int>>& matrix){
    vector <int> ans;
   int row = matrix.size();
   int col= matrix[0].size();
   int count =0;
   int total = row*col;
   int startingrow= 0;
   int startingcol= 0;
   int endingrow= row-1;
   int endingcol= col-1;

   while(count<total){
    for(int index=startingcol; count<total && index <= endingcol; index++){
        ans.push_back(matrix[startingrow][index]);
        count++;
    }
    startingrow++;

    for(int index=startingrow; count<total && index <= endingrow; index++){
        ans.push_back(matrix[index][endingcol]);
        count++;
    }
    endingcol--;

    for(int index=endingcol; count<total && index >= startingcol; index--){
        ans.push_back(matrix[endingrow][index]);
        count++;
    }
    endingrow--;

    for(int index=endingrow; count<total && index >= startingrow; index--){
        ans.push_back(matrix[index][startingcol]);
        count++;
    }
    startingcol++;
 }

 return ans;
}

int main() {
    vector<vector<int>> matrix{
        {1,2,3},
        {1,5,6},
        {7,8,9}
    };

    vector<int> result= spiralprint(matrix);
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }


    return 0;
}
