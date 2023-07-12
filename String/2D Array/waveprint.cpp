#include <bits/stdc++.h>
using namespace std;

vector<int> waveprint(vector<vector<int>> arr, int nrows, int mcols){
    vector <int> ans;
    for(int col=0; col<mcols;col++){
        if(col&1){
            for(int row= nrows-1; row>=0;row--){
                ans.push_back(arr[row][col]);
            }

        }

        else{
            for (int row=0; row<nrows; row++){
                ans.push_back(arr[row][col]);
            }
        }
    }
    return ans;
}

int main() {
    int nrows, mcols;
    cin>>nrows;
    cin>>mcols;

    vector<vector<int>> arr(nrows, vector<int>(mcols));
    for (int i=0; i<nrows; i++){
        for (int j=0; j<mcols;j++)
    {
        cin>>arr[i][j];
    }
    }

    vector<int> result = waveprint(arr, nrows, mcols);
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<" ";
    }

    return 0;
}
