#include<bits/stdc++.h>
using namespace std;

void reversestring (vector<char>& s){
    int st=0;
    int e=s.size()-1;
    while(st<e){
        swap(s[st++], s[e--]);

    }
}


int main(){
    vector<char> mystring={'h','e','l','l','o'};
    reversestring(mystring);
    for(const char& c:mystring){
        cout<<c<<' ';
    }
    return 0;

}