#include <iostream>
#include <stack>
using namespace std;

void sortedinsert(stack<int>& destStack, int num) {
    if (destStack.empty() || destStack.top() <= num) {
        destStack.push(num);
        return;
    }
    int n = destStack.top();
    destStack.pop();
    sortedinsert(destStack, num);
    destStack.push(n);
}

void sortStack(stack<int>& sourceStack) {
    stack<int> tempStack;
    while (!sourceStack.empty()) {
        int num = sourceStack.top();
        sourceStack.pop();
        sortedinsert(tempStack, num);
    }
    sourceStack = tempStack;
}

int main() {
    stack<int> stack;
    stack.push(5);
    stack.push(0);
    stack.push(9);
    stack.push(4);
    stack.push(7);

    sortStack(stack);
    while (!stack.empty()) {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
    return 0;
}
