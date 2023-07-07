#include <bits/stdc++.h>
using namespace std;

bool unique(vector<int> &arr)
{
    int i = 0;
    sort(arr.begin(), arr.end());
    vector<int> ans;
    while (i < arr.size())
    {
        int count = 1;

        for (int j = 0; j < arr.size(); j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }
        ans.push_back(count);
        i = i + count;
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    vector<int> arr = {4, 2, 2, 4};
    // cout << unique(arr);
    bool found = unique(arr);

    if (found == true)
    {
        cout << "Found " << endl;
    }
    else
    {
        cout << "not found " << endl;
    }

    return 0;
}
