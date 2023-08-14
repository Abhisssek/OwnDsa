#include<bits/stdc++.h>
using namespace std;

class nstack{
    public:
    int *arr;
    int *top;
    int *next;
    int n, s;
    int freespot;
    nstack(int n, int s){
        n=n;
        s=s;

        arr=new int[s];
        top= new int[n];
        next= new int[s];
    
    for(int i=0;i<s;i++){
        next[i]=i+1;
    }
    next[s-1]=-1;
    freespot=0;
    }
    bool push(int x, int m){
        if(freespot==-1){
            return false;
        }
        int index=freespot;
        arr[index]=x;
        freespot=next[index];
        next[index]=top[m-1];
        top[m-1]=index;
        return true;
    }

    int pop(int m){
        if(top[m-1]==-1){
            return -1;
        }
        int index=top[m-1];
        top[m-1]=next[index];
        next[index]=freespot;
        freespot=index;
        return arr[index];
    }
};

int main(){
    nstack stack(3,10);

    stack.push(5,1);
    stack.push(10,2);
    stack.push(15,3);

    int popped1=stack.pop(1);
    int popped2= stack.pop(2);
    int popped3= stack.pop(3);


    cout<<"popped element "<< popped1<<endl;
    cout<<"popped element "<<popped2<<endl;
    cout<<"popped element "<<popped3<<endl;
    return 0;
}
