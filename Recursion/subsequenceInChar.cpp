#include <bits/stdc++.h>
using namespace std;

void solve(vector<string>& ans, string str,string output,  int i) {
    if (i >= str.length()) {
        ans.push_back(output);
        return;
    }

    solve(ans, str, output,  i + 1);
    output.push_back(str[i]);
    solve(ans, str, output, i + 1);
}

vector<string> subsequence(string str) {
    vector<string> ans;
    string output = "";

    solve(ans, str, output, 0);
    return ans;
} 

int main() {
    string str = "abc";
    vector<string> result = subsequence(str);

    for (const auto& subseq : result) {
        cout << subseq << endl;
    }

    return 0;
}
