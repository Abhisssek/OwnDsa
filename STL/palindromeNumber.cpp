#include <bits/stdc++.h>
using namespace std;
int palindrome(int x){
    int y=0;
    while(x>0){
        int digit= x%10;
        y=y*10+digit;
        x=x/10;
    }
    return y;
}

int main(){
   int x=121;
   int dummy=x;
   int y=palindrome(x);
   if(dummy==y){
    cout<<"palindrome number";

   }
   else{
       cout<<"not palindrome number";
      }
      return 0;
    
}
