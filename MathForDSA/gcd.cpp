#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

int gcd2(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}



int gcd(int a, int b){
    if(a==0){
        return b;
    }

    if(b==0){
        return a;
    }

    while(a!=b){
        if(a>b){
            a=a-b;

        }
        else{
            b=b-a;
        }
    }
    return a;
}

int main() {
    int a,b;

    cin>>a>>b;
    int ans= gcd(a,b);
    cout<<a<<" "<<b<<" gcd is "<<ans;

    return 0;
}
