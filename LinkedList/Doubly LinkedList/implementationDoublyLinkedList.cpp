#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

   ~Node() {
        int val = this -> data;
        if(next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "memory free for node with data "<< val << endl;
    }
};

void insertAtHead(Node*& tail, Node*& head, int d) {
    if (head == nullptr) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    } else {
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertAtTail(Node*& tail, Node*& head, int d) {
    if (tail == nullptr) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    } else {
        Node* temp = new Node(d);
        temp->prev = tail;
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node* & tail, Node* &head, int position, int d) {
    
    //insert at Start
    if(position == 1) {
        insertAtHead(tail,head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,head,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert ->next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert -> prev = temp;
}

void deleteNode(int position, Node* & head) { 

    //deleting first or start node
    if(position == 1) {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head = temp ->next;
        temp -> next = NULL;
        delete temp;
    }
    else
    {
        //deleting any middle node or last node
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < position) {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        curr -> prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;

    }
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    // Insert elements at the head
    insertAtHead(tail, head, 3);
    insertAtHead(tail, head, 2);
    insertAtHead(tail, head, 1);

    // Insert elements at the tail
    insertAtTail(tail, head, 4);
    insertAtTail(tail, head, 5);

    // Insert element at a specific position
    insertAtPosition(tail, head, 2, 10);

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

    delete head;

    return 0;
}
