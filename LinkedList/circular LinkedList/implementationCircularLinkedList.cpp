#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }

    ~Node()
{
    if (next != nullptr)
    {
        delete next;  // Use delete operator to deallocate memory for the next Node
        next = nullptr;
    }
    cout << "Deleting value: " << data << endl;
}

};

void insertNode(Node *&tail, int element, int d)
{
    if (tail == nullptr)
    {
        Node *newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    }
    else
    {
        Node *curr = tail;

        while (curr->data != element)
        {
            curr = curr->next;
        }

        Node *temp = new Node(d);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail, int value) {

    //empty list
    if(tail == NULL) {
        cout << " List is empty, please check again" << endl;
        return;
    }
    else{
        //non-empty

        //assuming that "value" is present in the Linked List
        Node* prev = tail;
        Node* curr = prev -> next;

        while(curr -> data != value) {
            prev = curr;
            curr = curr -> next;
        }

        prev -> next = curr -> next;

        //1 Node Linked List
        if(curr == prev) {
            tail = NULL;
        }

        //>=2 Node linked list
        else if(tail == curr ) {
            tail = prev;
        }

        curr -> next = NULL;
        delete curr;

    }

}



// int getlength(Node* head){
//     int len=0;
//     Node* temp=head;

//     while(temp!=nullptr){
//         len++;
//         temp=temp->next;
//     }
//     return len;
// }


void print(Node* tail) {

    Node* temp = tail;

    //empty list
    if(tail == NULL) {
        cout << "List is Empty "<< endl;
        return ;
    }

    do {
        cout << tail -> data << " ";
        tail = tail -> next;
    } while(tail != temp);

    cout << endl;
} 



int main()
{
    Node *tail = nullptr;

    // Insert nodes
    insertNode(tail, 0, 1);  // Insert 1 as the first Node
    insertNode(tail, 1, 2);  // Insert 2 after the Node with data 1
    insertNode(tail, 2, 3);  // Insert 3 after the Node with data 2
    insertNode(tail, 3, 4);  // Insert 4 after the Node with data 3

    // Print the linked list
    cout << "Linked List: ";
    print(tail);  // Print starting from the Node after tail

    // Delete nodes
    deleteNode(tail, 2);  // Delete the Node with data 2
    deleteNode(tail, 4);  // Delete the Node with data 4

    // Print the linked list after deletion
    cout << "Linked List after deletion: ";
    print(tail);  // Print starting from the Node after tail

    // Get the length of the linked list
    // int length = getlength(tail->next);
    // cout << "Length of the linked list: " << length << endl;

    // Clean up memory
    delete tail;

    return 0;
}
