#include<bits/stdc++.h>
using namespace std;

queue<int> modifyqueue(queue<int> q, int k){
    stack<int>s;
    for(int i=0;i<k;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
    }
    int t=q.size()-k;
    while(t--){
        int val=q.front();
        q.pop();
        q.push(val);
    }    
    return q;
    
}

int main(){
    int t=1;
    int n=5;
    int k=3;

    queue<int>q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    queue<int> ans=modifyqueue(q,k);
    while(!ans.empty()){
        int a=ans.front();
        ans.pop();
        cout<<a<<" ";
    }
    return 0;
}
