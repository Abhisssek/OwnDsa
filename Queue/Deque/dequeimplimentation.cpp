#include<bits/stdc++.h>
using namespace std;


class Deque
{	
    int *arr;
    int front;
    int rear;
    int size;
public:
    // Initialize your data structure.
    Deque(int n)
    {
        size = n;
        arr = new int[n];
        front = -1;
        rear = -1;
    }

    // Pushes 'X' in the front of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushFront(int x)
    {
        //check full or not
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(front == 0 && rear != size-1) {
            front = size-1;
        } 
        else
        {
            front--;
        }
        arr[front] = x;
        return true;
    }

    // Pushes 'X' in the back of the deque. Returns true if it gets pushed into the deque, and false otherwise.
    bool pushRear(int x)
    {
        if( isFull() ) {
            return false;
        }
        else if(isEmpty()) {
            front  = rear = 0;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        } 
        else
        {
             rear++;
        }
        arr[rear] = x;
        return true;
    }

    // Pops an element from the front of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popFront()
    {
        if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[front];
        arr[front] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(front == size - 1) {
            front = 0; //to maintain cyclic nature
        }
        else
        {//normal flow
            front++;
        }
        return ans;
    }

    // Pops an element from the back of the deque. Returns -1 if the deque is empty, otherwise returns the popped element.
    int popRear()
    {
         if(isEmpty()){//to check queue is empty
            //cout << "Queue is Empty " << endl;
            return -1;
        }
        
        int ans = arr[rear];
        arr[rear] = -1;
        
        if(front == rear) { //single element is present
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1; //to maintain cyclic nature
        }
        else
        {//normal flow
            rear--;
        }
        return ans;
    }

    // Returns the first element of the deque. If the deque is empty, it returns -1.
    int getFront()
    {
        if(isEmpty()){
            return -1;
        }
        return arr[front];
    }

    // Returns the last element of the deque. If the deque is empty, it returns -1.
    int getRear()
    {
       if(isEmpty()){
            return -1;
        }
        return arr[rear];
    }

    // Returns true if the deque is empty. Otherwise returns false.
    bool isEmpty()
    {
        if(front == -1)
            return true;
        else
            return false;
    }

    // Returns true if the deque is full. Otherwise returns false.
    bool isFull()
    {
		if( (front == 0 && rear == size-1) || (front != 0 && rear == (front-1)%(size-1) ) ) {
            return true;
        }
        else
        {
            return false;
        }
    }
};


int main() {
    Deque myDeque(5);

    // Check if the deque is empty
    if (myDeque.isEmpty()) {
        cout << "Deque is empty." << endl;
    } else {
        cout << "Deque is not empty." << endl;
    }

    // Push elements to the front of the deque
    bool pushFrontResult1 = myDeque.pushFront(10);
    bool pushFrontResult2 = myDeque.pushFront(20);
    bool pushFrontResult3 = myDeque.pushFront(30);

    if (pushFrontResult1 && pushFrontResult2 && pushFrontResult3) {
        cout << "Elements pushed to the front of the deque." << endl;
    } else {
        cout << "Failed to push elements to the front of the deque." << endl;
    }

    // Get the front and rear elements of the deque
    int frontElement = myDeque.getFront();
    int rearElement = myDeque.getRear();

    cout << "Front element: " << frontElement << endl;
    cout << "Rear element: " << rearElement << endl;

    // Pop elements from the front and rear of the deque
    int poppedFrontElement = myDeque.popFront();
    int poppedRearElement = myDeque.popRear();

    cout << "Popped front element: " << poppedFrontElement << endl;
    cout << "Popped rear element: " << poppedRearElement << endl;

    // Check if the deque is full
    if (myDeque.isFull()) {
        cout << "Deque is full." << endl;
    } else {
        cout << "Deque is not full." << endl;
    }

    return 0;
}
