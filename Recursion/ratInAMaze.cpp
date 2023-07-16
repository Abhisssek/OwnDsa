#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> ans;

void recursion(int i, int j, string path, vector<vector<int>>& matrix, int row, int column) {
    if (i < 0 || i >= row || j < 0 || j >= column) {
        return;
    }

    if (matrix[i][j] == 0) {
        return;
    }

    if (i == row - 1 && j == column - 1) {
        ans.push_back(path);
        return;
    }

    matrix[i][j] = 0;
    recursion(i - 1, j, path + 'U', matrix, row, column);
    recursion(i + 1, j, path + 'D', matrix, row, column);
    recursion(i, j - 1, path + 'L', matrix, row, column);
    recursion(i, j + 1, path + 'R', matrix, row, column);
    matrix[i][j] = 1;
}

vector<string> findpath(vector<vector<int>>& m, int n) {
    string path;
    int row = n;
    int column = n;
    recursion(0, 0, path, m, row, column);
    return ans;
}

int main() {
    vector<vector<int>> matrix = {{1, 0, 0, 0},
                                  {1, 1, 0, 1},
                                  {1, 1, 0, 0},
                                  {0, 1, 1, 1}};

    int n = matrix.size();
    vector<string> paths = findpath(matrix, n);
    for (const string& path : paths) {
        cout << path << endl;
    }
    return 0;
}
