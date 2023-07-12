#include <bits/stdc++.h>
using namespace std;

string removeoccurence(string s, string part){
    while(s.length()!=0 && s.find(part)<s.length()){
        s.erase(s.find(part), part.length());

    }
    return s;
}

int main()
{
    string input= "abccbabccbabc";
    string part="abc";
    string result= removeoccurence(input, part);
    cout << "modified String: "<< result<< endl;
    return 0;
}