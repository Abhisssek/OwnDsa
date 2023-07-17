#include <iostream>

class Node {
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

Node* findMidddle(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    
    if(left == NULL)
        return right;
    
    if(right == NULL)
        return left;
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    //merge 2 sorted Linked List
    while(left != NULL && right != NULL) {
        if(left -> data < right -> data ) {
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        else
        {
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
    }
    
    while(left != NULL) {
        temp -> next = left;
        temp = left;
        left = left -> next;
    }
    
    while(right != NULL) {
        temp -> next = right;
        temp = right;
        right = right -> next;
    }
    
    ans = ans -> next;
    return ans;
    
}

Node* mergeSort(Node *head) {
    //base case
    if( head == NULL || head -> next == NULL ) {
        return head;
    }
    
    // break linked list into 2 halvs, after finding mid
    Node* mid = findMidddle(head);
    
    Node* left = head;
    Node* right = mid->next;
    mid -> next = NULL;
    
    //recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);
    
    //merge both left and right halves
    Node* result = merge(left, right);
    
    return result;
}

void printLL(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " ";
        curr = curr->next;
    }
    std::cout << std::endl;
}

void deleteLL(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(5);
    Node* second = new Node(2);
    Node* third = new Node(8);
    Node* fourth = new Node(4);
    Node* fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    std::cout << "Original List: ";
    printLL(head);

    Node* sortedHead = mergeSort(head);

    std::cout << "Sorted List: ";
    printLL(sortedHead);

    deleteLL(sortedHead);

    return 0;
}
