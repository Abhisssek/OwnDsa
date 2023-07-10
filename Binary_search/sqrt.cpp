#include <bits/stdc++.h>
using namespace std;

long long int sqrtinteger(long long int n)
{
    int s = 0;
    int e = 0;
    long long int ans = -1;
    while (s < e)
    {
        long long int mid = s + (e - s) / 2;
        long long int square = mid * mid;

        if (square == n)
        {
            return mid;
        }

        else if (square > n)
        {
            ans = mid;
            s = mid;
        }

        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

double moreprecision(int n, int precision, int tempsol)
{
    double factor = 1;
    double ans = tempsol;
    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;

        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }return ans;
}

int main(){
    long long int n;
    cin>>n;
    long long int tempsol=sqrtinteger(n);
    cout<<moreprecision(n,3,tempsol);
    return 0;
}