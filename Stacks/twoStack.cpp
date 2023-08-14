#include <bits/stdc++.h>
using namespace std;

class twoStack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;


    twoStack(int s){
        this-> size=s;
        top1=-1;
        top2=s;
        arr=new int[s];
    }

    void push1(int num){
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }
    }

    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        return -1;
    }
};

int main(){
    int size=5;
    twoStack stack(size);

    stack.push1(10);
    stack.push1(20);
    stack.push1(30);

    stack.push2(50);
    stack.push2(40);

    int popped1=stack.pop1();
    if(popped1!=-1){
        cout<<"popped element from stack 1: "<<popped1<<endl;
    }
    else{
        cout<<"stack1 is empty"<<endl;
    }

    int popped2= stack.pop2();
    if(popped2!=-1){
        cout<<"popped element from stack 2: "<<popped2<<endl;
    }

    else{
        cout<<"popped elemnt from stack 2: "<<popped2<<endl;
    }

    return 0;


}