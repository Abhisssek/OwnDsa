#include <iostream>

class Node {
public:
    int data;
    Node* next;
};

Node* mergeList(Node* head1, Node* head2) {
    if (head1 == nullptr) {
        return head2;
    }

    if (head2 == nullptr) {
        return head1;
    }

    Node* mergehead = nullptr;
    Node* curr = nullptr;

    if (head1->data <= head2->data) {
        mergehead = head1;
        head1 = head1->next;
    } else {
        mergehead = head2;
        head2 = head2->next;
    }

    curr = mergehead;

    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            curr->next = head1;
            head1 = head1->next;
        } else {
            curr->next = head2;
            head2 = head2->next;
        }
        curr = curr->next;
    }

    if (head1 != nullptr) {
        curr->next = head1;
    } else if (head2 != nullptr) {
        curr->next = head2;
    }

    return mergehead;
}

Node* splitList(Node* head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    Node* slow = head;
    Node* fast = head->next;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node* right = slow->next;
    slow->next = nullptr;

    Node* left = head;
    return mergeList(splitList(left), splitList(right));
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

void printLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

int main() {
    Node* head = nullptr;
    Node* head2 = nullptr;

    insertNode(head, 1);
    insertNode(head, 2);
    insertNode(head2, 3);
    insertNode(head2, 4);
    insertNode(head, 9);

    std::cout << "Original Linked List: ";
    printLL(head);
    printLL(head2);

    Node* merged = mergeList(head, head2);
    Node* sorted = splitList(merged);

    std::cout << "Sorted Linked List: ";
    printLL(sorted);

    return 0;
}
