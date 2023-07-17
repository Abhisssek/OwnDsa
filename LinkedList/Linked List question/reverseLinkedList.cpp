#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node* next;
};

node* reverselnkedlist(node* head){
    node* prev=nullptr;
    node* curr=head;
    node* next=nullptr;


    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    return prev;
}

void inserNode(node*& head, int data){
    node* newNode=new node{data,head};
    head=newNode;
}

void printLL(node* head){
    node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

int main(){
    node* head= nullptr;

    inserNode(head,5);
    inserNode(head,4);
    inserNode(head,3);
    inserNode(head,2);
    inserNode(head,1);


    cout<<"original: ";
    printLL(head);

    head=reverselnkedlist(head);
    cout<<"reversed: ";
    printLL(head);
    return 0;
}