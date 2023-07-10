#include <iostream>

// Node structure
struct Node {
    int data;
    Node* next;

    Node(int d) {
        data = d;
        next = NULL;
    }
};

Node* findMid(Node* head) {
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
    Node* mid = findMid(head);
    
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


int main() {
    // Create a sample linked list
    Node* head = new Node(5);
    Node* second = new Node(2);
    Node* third = new Node(8);
    Node* fourth = new Node(1);
    Node* fifth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Print the original linked list
    std::cout << "Original Linked List:" << std::endl;
    Node* current = head;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    // Perform merge sort on the linked list
    Node* sortedHead = mergeSort(head);

    // Print the sorted linked list
    std::cout << "Sorted Linked List:" << std::endl;
    current = sortedHead;
    while (current != NULL) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;

    return 0;
}