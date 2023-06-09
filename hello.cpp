#include <iostream>
using namespace std;
void pattern(int n){
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=n){
            cout << "*" << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern2(int n){
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout << "*" << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern3(int n){
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout << j << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern4(int n){
    int i=1;
    while(i<=n){
        int j=1;
        while(j<=i){
            cout << i << " ";
            j++;
        }
        cout << endl;
        i++;
    }
}
void pattern5(int n){
    int i=1;
    while(i<=n){
    int j=n;
        while(j>=i){
            cout << "*" << " ";
            j--;
        }
        cout << endl;
        i++;
    }
}
void pattern6(int n){
    int i=1;
    while(i<=n){
        int j=n;
        int k=1;
        while(j>=i){
            cout << k << " ";
            j--;
            k++;
        }
        cout << endl;
        i++;
    }
}
int main(){
    cout << "enter your number"<<endl;
    int n;
    cin >> n;
    pattern6(n);
    
    return 0;
}