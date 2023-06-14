#include<bits/stdc++.h>
using namespace std;

int count_digit(int n){
    int x=n;
    int count=0;
    while(x>0){
        count++;
        x/=10;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    cout<<count_digit(n)<<endl;
    return 0;
}