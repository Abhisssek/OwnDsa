#include <bits/stdc++.h>
using namespace std;

bool checkpalindrome(string str, int i, int j){
    if(i>j){
        return true;
    }

    if(str[i]!=str[j]){
        return false;
    }

    // else{
    //     i++;
    //     j--;
    //     return checkpalindrome(str, i, j);

    // }

     else{
        
        return checkpalindrome(str, i+1, j-1);

    }
}

int main(){
   string name= "abacaba";

   bool check =checkpalindrome(name,0,name.length()-1);

    if(check){
        cout<< "palindrome";

    }

    else{
        cout<<" not palindrome";
    }
    return 0;
}