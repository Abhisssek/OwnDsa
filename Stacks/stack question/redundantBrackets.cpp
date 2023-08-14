#include <bits/stdc++.h>
using namespace std;

bool findRedundant(string &s) {
    stack<char> st;
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];

        if (ch != ')') {
            st.push(ch);
        } else {
            bool operatorFound = false;
            while (!st.empty() && st.top() != '(') {
                char top = st.top();
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    operatorFound = true;
                }
                st.pop();
            }
            st.pop(); // Remove the '(' from the stack
            if (!operatorFound) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string expression = "((a+b))";
    cout << (findRedundant(expression) ? "yes" : "no") << endl;
    return 0;
}



//wrong expression code is not right