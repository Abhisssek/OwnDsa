#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};

Node* getmid(Node* head){
    Node* slow=head;
    Node* fast=head->next;

    while(fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
    }return slow;
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

bool ispalindrome(Node* head){
    if(head->next==nullptr){
        return true;
    }

    Node* middle=getmid(head);

    Node* temp=middle->next;
    middle->next=reverse(temp);

    Node* head1=head;
    Node* head2 = middle->next;

    while(head2!=nullptr){
        if(head2->data!=head1->data){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
    }

    temp=middle->next;
    middle->next=reverse(temp);
    return true;
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

int main() {
    Node* head = nullptr;

    insertNode(head, 0);
    insertNode(head, 2);
    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 0);

   if(ispalindrome(head)){
    cout<<"palindrome"<<endl;
   }
   else{
    cout<<"not palindrome";
   }

    return 0;
}
