#include <bits/stdc++.h>
using namespace std;

bool isValidParenthesis(string expression){
    stack<char> s;
    for(int i = 0; i < expression.length(); i++){
        char ch = expression[i];
        if(ch == '(' || ch == '{' || ch == '['){
            s.push(ch);
        }
        else{
            if(!s.empty()){
                char top = s.top();
                if((ch == ')' && top == '(') ||
                   (ch == '}' && top == '{') ||
                   (ch == ']' && top == '[')){
                    s.pop();
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
    }
    return s.empty();
}

int main(){
    string expression = "((}))";
    cout << "Expression 1 is " << (isValidParenthesis(expression) ? "valid" : "invalid") << endl;
}
