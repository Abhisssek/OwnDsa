#include <bits/stdc++.h>
using namespace std;

bool searchmatrix(vector<vector<int>> matrix, int target){
    int row= matrix.size();
    int col= matrix[0].size();
    int rowindex=0;
    int colindex= col-1;


    while(rowindex<row && colindex>=0){
        int element= matrix[rowindex][colindex];

        if(element==target){
            return -1;
        }

        if(element<target){
            rowindex++;
        }

        else{
            colindex--;
        }
    }
        return 0;

    

}

int main() {
    int target=1;
    vector<vector<int>> matrix{
        {1,2,3},
        {1,5,6},
        {7,8,9}
    };

    target =0;

    bool found= searchmatrix(matrix,target);
    if(found){
        cout<<"found ";

    }
    else{
        cout<<"not found ";
    }

    return 0;
}
