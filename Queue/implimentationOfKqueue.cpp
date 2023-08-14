#include<bits/stdc++.h>
using namespace std;

class kqueue{
public:
    int n;
    int k;
    int* front;
    int* rear;
    int* arr;
    int freespot;
    int* next;

    kqueue(int n, int k) {
        this->n = n;
        this->k = k;

        front = new int[k];
        rear = new int[k];
        next = new int[n];
        arr = new int[n];

        for (int i = 0; i < k; i++) {
            front[i] = -1;
            rear[i] = -1;
        }

        for (int i = 0; i < n - 1; i++) {
            next[i] = i + 1;
        }
        next[n - 1] = -1;

        freespot = 0;
    }

    void enqueue(int data, int qn) {
        if (freespot == -1) {
            cout << "No empty space is present." << endl;
            return;
        }
        int index = freespot;
        freespot = next[index];

        if (front[qn - 1] == -1) {
            front[qn - 1] = index;
        } else {
            next[rear[qn - 1]] = index;
        }
        next[index] = -1;

        rear[qn - 1] = index;
        arr[index] = data;
    }

    int dequeue(int qn) {
        if (front[qn - 1] == -1) {
            cout << "Queue underflow." << endl;
            return -1;
        }
        int index = front[qn - 1];
        front[qn - 1] = next[index];

        next[index] = freespot;
        freespot = index;
        return arr[index];
    }
};

int main() {
    kqueue q(10, 3);
    
    q.enqueue(10, 1);
    q.enqueue(15, 1);
    q.enqueue(20, 2);
    q.enqueue(25, 3);
    
    cout << "Dequeue from queue 1: " << q.dequeue(1) << endl;
    cout << "Dequeue from queue 2: " << q.dequeue(2) << endl;
    cout << "Dequeue from queue 3: " << q.dequeue(1) << endl;
    cout << "Dequeue from queue 3: " << q.dequeue(3) << endl;

    return 0;
}
