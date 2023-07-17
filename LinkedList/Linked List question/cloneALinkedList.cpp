#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* arb;
    Node(int d){
        data=d;
        next=nullptr;
        arb=nullptr;
    }
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


void printRandom(Node* head){
    while(head!=nullptr){
        cout<<"head data: "<< head->data<<" ";
        if(head->arb!=nullptr){
            cout<<"head random data"<< head-> arb->data;
        }
        else{
            cout<<"head random data: NULL";
        }

        head=head->next;
        cout<<endl;
    }
}


Node* copylist(Node* head){
    Node* clonehead=nullptr;
    Node* clonetail=nullptr;

    Node* temp=head;
    while(temp!=nullptr){
        insertAtTail(clonehead,clonetail,temp->data);
        temp=temp->next;
    }

    Node* originalnode=head;
    Node* cloneNode=clonehead;

    while(originalnode!=nullptr&& cloneNode!=nullptr){
        Node* next=originalnode->next;
        originalnode->next=cloneNode;
        originalnode=next;
        next=cloneNode->next;
        cloneNode->next=originalnode;
        cloneNode=next;

    }


    originalnode=head;
    cloneNode=clonehead;

    while(originalnode!=nullptr && cloneNode!=nullptr){
        if(originalnode->arb!=nullptr){
            cloneNode->arb=originalnode->arb->next;        
        }
        else{
            cloneNode->arb=nullptr;
        }

        cloneNode=cloneNode->next;
        originalnode=originalnode->next;
    }


    Node* original=head;
    Node* copy=clonehead;

    while(original&&copy){
        original->next=original->next?original->next->next:original->next;
        copy->next=copy->next?copy->next->next:copy->next;
        original=original->next;
        copy=copy->next;
    }

    return clonehead;

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
    Node* head = new Node(1);
    Node* head2=new Node(2);
    Node* head3=new Node(3);


   head->next=head2;
   head2->next=head3;
   head->arb=head3;
   head2->arb=head;

   cout<<"orignal Linked List "<<endl;
   printRandom(head);
   cout<<endl;

   Node* clonehead=copylist(head);

   cout<<"cloned Linked List "<<endl;
   printRandom(clonehead);
   return 0;

    return 0;
}
