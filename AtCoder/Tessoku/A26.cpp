#include <bits/stdc++.h>
using namespace std;

int Q, X[10009];

bool isPrime(int x) {
    bool result = true;
    for (int i = 2; i * i <= x; i++) {
        result &= (x % i != 0);
    }
    return result;
}

int main() {
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> X[i];
    }

    for (int i = 1; i <= Q; i++) {
        bool res = isPrime(X[i]);
        if (res) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}