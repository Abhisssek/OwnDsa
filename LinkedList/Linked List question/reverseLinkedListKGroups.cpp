#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* kreverse(Node* head, int k){
    if(head==nullptr){
        return nullptr;
    }

    Node* next=nullptr;
    Node* curr =head;
    Node* prev=nullptr;

    int cnt=0;

    while(curr!=nullptr&& cnt<k){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
        cnt++;
    }

    if(next!=nullptr){
        head->next=kreverse(next,k);
    }
    return prev;

}

Node* push(Node*& head, int newData ){
    Node* newNode= new Node();
    newNode->data= newData;
    newNode->next= head;
    head=newNode;

    return head;

}




void printLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    push(head, 1);
    push(head, 2);
    push(head, 3);
    push(head, 4);
    // push(head, 5);

    cout << "Original Linked List: ";
    printLL(head);
    int k=2;
    

    head=kreverse(head,k);
    cout<<"reversed k group: ";
    printLL(head);

    

    return 0;
}
