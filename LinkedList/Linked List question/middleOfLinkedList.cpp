#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
};

Node* findMiddle(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void insertNode(Node*& head, int data) {
    Node* newNode = new Node{data, nullptr};
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

void printmiddle(Node* head){
    Node* middle = findMiddle(head);
    if (middle != nullptr) {
        cout << "Middle of the Linked List: " << middle->data << endl;
    }
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

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head, 3);
    insertNode(head, 4);
    insertNode(head, 5);

    cout << "Original Linked List: ";
    printLL(head);
    printmiddle(head);
    

    return 0;
}
