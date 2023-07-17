#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
     ~Node(){
        int val= this->data;
        if(next!=nullptr){
            delete next;
            next=nullptr;
        }
        cout<<val<<endl;
    }
};

void insertAtHead(Node* & head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int position, int d) {
    if (position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp->next == nullptr) {
        insertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(int position, Node* &head) {
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
    } else {
        Node* curr = head;
        Node* prev = nullptr;
        int cnt = 1;

        while (cnt < position) {
            prev = curr;
            curr = curr->next;
            cnt++;
        }

        prev->next = curr->next;
        curr->next = nullptr;
        delete curr;
    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert elements at the head
    insertAtHead(head, 3);
    insertAtHead(head, 2);
    insertAtHead(head, 1);

    // Insert elements at the tail
    tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
    }
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    // Insert element at a specific position
    insertAtPosition(head, tail, 2, 10);

    // Print the linked list
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    // Delete element at a specific position
    deleteNode(3, head);

    // Print the linked list after deletion
    current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;

    return 0;
}
