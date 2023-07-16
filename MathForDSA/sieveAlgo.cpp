#include<bits/stdc++.h>
using namespace std;

void sieve(bool prime[]) {
    for (int i = 2; i <= 1000000; i++) {
        prime[i] = true;
    }

    for (int i = 2; i <= 1000000; i++) {
        if (prime[i]) {
            for (int j = 2 * i; j <= 1000000; j += i) {
                prime[j] = false;
            }
        }
    }

    prime[0] = prime[1] = false;
}

int main() {
    bool prime[1000000];
    sieve(prime);

    int n;
    cin >> n;

    while (n != -1) {
        if (prime[n]) {
            cout << "prime";
            break;
        } else {
            cout << "not prime";
            break;
        }
    }

    return 0;
}
