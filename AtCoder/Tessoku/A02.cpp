#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, X;
    int A[101];

    bool res = false;

    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            res = true;
        }
    }

    if (res) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}