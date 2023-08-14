#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    s.push(n);

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        while (!s.empty() && arr[i] <= arr[s.top() - 1]) {
            s.pop();
        }
        ans[i] = (s.empty() ? n : s.top() - 1);
        s.push(i + 1);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int> arr, int n) {
    stack<int> s;
    s.push(-1);
    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        while (!s.empty() && arr[i] <= arr[s.top()]) {
            s.pop();
        }
        ans[i] = (s.empty() ? -1 : s.top());
        s.push(i);
    }
    return ans;
}

int largestrectangle(vector<int>& heights) {
    int n = heights.size();
    vector<int> next = nextSmallerElement(heights, n);
    vector<int> prev = prevSmallerElement(heights, n);

    int area = INT_MIN;
    for (int i = 0; i < n; i++) {
        int b = next[i] - prev[i] - 1;
        int newarea = heights[i] * b;
        area = max(area, newarea);
    }
    return area;
}

int main() {
    vector<int> height = {2, 1, 6, 7, 2, 3};
    int result = largestrectangle(height);
    cout << "largest rectangle area: " << result << endl; 
    return 0;
}
