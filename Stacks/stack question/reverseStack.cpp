#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& s, int element){
    if(s.empty()){
        s.push(element);
        return;
    }
    int num=s.top();
    s.pop();
    insertAtBottom(s,element);
    s.push(num);
}

void reverseStack(stack<int>& stack){
    if(stack.empty()){
        return;
    }
    int num=stack.top();
    stack.pop();

    reverseStack(stack);
    insertAtBottom(stack,num);
}


int main(){
    stack<int> mystack;

    mystack.push(1);
    mystack.push(2);
    mystack.push(3);
    mystack.push(4);
    mystack.push(5);
    mystack.push(6);

    cout<<"original stack";
    stack<int> tempstack=mystack;

    while(!tempstack.empty()){
        cout<<tempstack.top()<<" ";
        tempstack.pop();
    }

    reverseStack(mystack);

    cout<<"reverse stack ";
    while(!mystack.empty()){
        cout<<mystack.top()<<" ";
        mystack.pop();
    }
    cout<<endl;
    return 0;

}