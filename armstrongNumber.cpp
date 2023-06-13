#include <bits/stdc++.h>
using namespace std;
bool armstrong(int n){
    int originalnumber =n;
    int count =0;
    int temp =n;
    while(temp!=0){
        count++;
        temp/=10;
    }
    int sumofpower=0;
    while(n!=0){
        int digit=n%10;
        sumofpower+=pow(digit,count);
        n/=10;
    }
    return (sumofpower+=originalnumber);
}
int main(){
   int n=153;
   if(armstrong(n)){
    cout<<"yes"<<endl;
   }
   else{
       cout<<"no"<<endl;
      }
    return 0;
}