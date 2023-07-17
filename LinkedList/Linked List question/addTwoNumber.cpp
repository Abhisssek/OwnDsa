#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};

void insertAtTail(Node* &head, Node* &tail,int val){
    Node* temp=new Node(val);

    if(head==nullptr){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }
}

Node* add(Node* first, Node* second){
    int carry=0;
    Node* anshead=nullptr;
    Node* anstail=nullptr;

    while(first!=nullptr || second!=nullptr || carry!=0){
        int val1=0;

        if(first!=nullptr){
            val1=first->data;
        }

        int val2=0;
        if(second!=nullptr){
            val2=second->data;
        }

        int sum= carry+val1+val2;
        int digit=sum%10;

        insertAtTail(anshead,anstail,digit);
        carry=sum/10;

        if(first!=nullptr){
            first=first->next;
        }
        if(second!=nullptr){
            second=second->next;
        }
    }return anshead;
}

Node* reverse(Node* head){
    Node* curr=head;
    Node* prev=nullptr;
    Node* next=nullptr;


    while(curr!=nullptr){
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    return prev;
}



void printLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void insertNode(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

Node* addtwolist(Node* first, Node* second){
    first=reverse(first);
    second=reverse(second);

    Node* ans= add(first,second);
    ans=reverse(ans);
    return ans;
}

int main() {
    Node* head = nullptr;
    Node* head2=nullptr;

    insertNode(head, 4);
    insertNode(head, 5);
    insertNode(head2, 1);
    insertNode(head2, 2);
    insertNode(head2, 0);

  Node* sum=addtwolist(head,head2);

  while(sum!=nullptr){
    cout<<sum->data;
    if(sum->next!=nullptr){
        cout<<" -> ";
    }sum=sum->next;
  }cout<<endl;

    return 0;
}
