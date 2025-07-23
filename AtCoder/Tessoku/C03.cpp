#include <bits/stdc++.h>
using namespace std;

int D, X, A[200009];
int Q, S[200009], T[200009];
int Price[200009];

int main() {
    cin >> D >> X;
    for (int i = 2; i <= D; i++) {
        cin >> A[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> S[i] >> T[i];
    }

    Price[1] = X;
    for (int i = 2; i <= D; i++) {
        Price[i] = Price[i - 1] + A[i];
    }

    for (int i = 1; i <= Q; i++) {
        if (Price[S[i]] > Price[T[i]]) {
            cout << S[i] << endl;
        } else if (Price[S[i]] < Price[T[i]]) {
            cout << T[i] << endl;
        } else {
            cout << "Same" << endl;
        }
    }
    return 0;
}