#include <bits/stdc++.h>
using namespace std;
void divisor(int n){
    cout<<"the divisors of "<<n<<" are"<<endl;
    for(int i=1; i<=n; i++){
    if (n%i==0){
        cout<<i<<endl;
        
                
    }
    
    
}
    cout<<endl;
}
int main(){
   divisor(17);
    return 0;
}