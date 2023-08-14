#include<bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }

    int num=s.top();
    s.pop();

    insertAtBottom(s,x);
    s.push(num);
}

int main(){
    stack<int> s;
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);

    int x=6;
    insertAtBottom(s,x);
    cout<<"modified stack ";
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
    return 0;

}