#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    for (int i=2; i<sqrt(n);i++){
        if(n%i==0){
                    return false;
        }
    }
    return true;
}
int main(){
    int n=11;
    bool ans = isprime(n);
    if (n!=1&&ans==true){
        cout<<n<<" is prime";
    }
    else{
            cout<<n<<" is not prime";
        }
    return 0;
}