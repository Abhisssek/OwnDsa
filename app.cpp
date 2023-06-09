#include<bits/stdc++.h>
using namespace std;

void pattern7(int n){
  int i=1;
  while(i<=n){
    int j=1;
    int k=1;
    while(j<=n-i){
      cout << " ";
      j++;
    }
    while (k<=2*i-1){
      cout<<"*";
      k++;
    }
    cout << endl;
    i++;
  }
}
void pattern8(int n){
  int i=1;
  while(i<=n){
    int j=1;
    int k=1;
    while(j<=i-1){
      cout << " ";
      j++;
    }
    while (k<=2*n-(2*i-1)){
      cout<<"*";
      k++;
    }
    cout << endl;
    i++;
  }
}
void pattern9(int n){
  int i=1;
  while(i<=n){
    int j=1;
    int k=1;
    while(j<=n-i){
      cout << " ";
      j++;
    }
    while (k<=2*i-1){
      cout<<"*";
      k++;
    }
    cout << endl;
    i++;
  }
  int l=1;
  while(l<=n){
    int j=1;
    int k=1;
    while(j<=l-1){
      cout << " ";
      j++;
    }
    while (k<=2*n-(2*l-1)){
      cout<<"*";
      k++;
    }
    cout << endl;
    l++;
  }
}

  


int main(){
    int n;
    cin>>n;
    pattern9(n);
    return 0;
}