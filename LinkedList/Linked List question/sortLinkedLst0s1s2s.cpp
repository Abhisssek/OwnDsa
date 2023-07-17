#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {};
};

void insertAtTail(Node*& tail, Node* curr) {
    if (tail != nullptr) {
        tail->next = curr;
    }
    tail = curr;
}

Node* splitList(Node* head) {
    Node* zerohead = new Node(-1);
    Node* zerotail = zerohead;
    Node* onehead = new Node(-1);
    Node* onetail = onehead;
    Node* twohead = new Node(-1);
    Node* twotail = twohead;

    Node* curr = head;
    while (curr != nullptr) {
        int value = curr->data;
        if (value == 0) {
            insertAtTail(zerotail, curr);
        } else if (value == 1) {
            insertAtTail(onetail, curr);
        } else if (value == 2) {
            insertAtTail(twotail, curr);
        }
        curr = curr->next;
    }

    if (onehead->next != nullptr) {
        zerotail->next = onehead->next;
    } else {
        zerotail->next = twohead->next;
    }

    onetail->next = twohead->next;
    twotail->next = nullptr;
    head = zerohead->next;

    delete zerohead;
    delete onehead;
    delete twohead;

    return head;
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
    insertNode(head, 1);

    std::cout << "Original Linked List: ";
    printLL(head);

    Node* sorted = splitList(head);

    std::cout << "Sorted Linked List: ";
    printLL(sorted);

    return 0;
}
