#include<bits/stdc++.h>
using namespace std;

queue<int> rev(queue<int> q){
    stack<int>s;
    while(!q.empty()){
        int element=q.front();
        q.pop();
        s.push(element);
    }
    while(!s.empty()){
        int element=s.top();
        s.pop();
        q.push(element);
    }
    return q;
}

int main(){
    queue<int> myqueue;
    myqueue.push(1);
    myqueue.push(2);
    myqueue.push(3);
    myqueue.push(4);
    myqueue.push(5);

    queue<int> originaqueue=myqueue;
    queue<int>reversedqueue=rev(myqueue);
    cout << "Reversed queue: ";
    while (!reversedqueue.empty()) {
        cout << reversedqueue.front() << " ";
        reversedqueue.pop();
    }
    cout << endl;
    
    return 0;
}