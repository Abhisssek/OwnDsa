#include <bits/stdc++.h>
using namespace std;

bool knows(vector<vector<int>> &m, int a, int b, int n)
{
    if (m[a][b] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int celebrity(vector<vector<int>> &m, int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();

        int b = s.top();
        s.pop();

        if (knows(m, a, b, n))
        {
            s.push(b);
        }
        else
        {
            s.push(a);
        }
    }
    int ans = s.top();

    int zerocount = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[ans][i] == 0)
        {
            zerocount++;
        }
    }
    if (zerocount != n)
    {
        return -1;
    }

    int onecount = 0;
    for (int i = 0; i < n; i++)
    {
        if (m[i][ans] == 1)
        {
            onecount++;
        }
    }
    if (onecount != n - 1)
    {
        return -1;
    }
return ans;
}



int main()
{
    vector<vector<int>> m = {{0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 0}, {0, 0, 1, 0}};

    int n = m.size();
    int result = celebrity(m, n);
    cout << "celebrity: " << result << endl;
    return 0;
}