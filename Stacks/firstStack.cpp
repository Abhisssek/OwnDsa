#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    int *arr;
    int top;
    int size;

    MyStack(int size) {
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element) {
        if (top < size - 1) {  // Corrected condition
            top++;
            arr[top] = element;
        } else {
            cout << "stack overflow" << endl;
        }
    }

    void pop() {
        if (top >= 0) {
            top--;
        } else {
            cout << "stack underflow" << endl;
        }
    }

    int peek() {
        if (top >= 0) {
            return arr[top];
        } else {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    MyStack myStack(5);

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.push(5);

    cout << "Peek: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop();

    cout << "Peek: " << myStack.peek() << endl;

    myStack.pop();
    myStack.pop();
    myStack.pop();

    cout << "Is stack empty? " << (myStack.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
