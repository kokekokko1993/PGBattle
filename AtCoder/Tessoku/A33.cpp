#include <bits/stdc++.h>
using namespace std;

int N, A[100009];

// A[1] XOR A[2] XOR ... XOR A[N] == 0 -> 後手勝利
// A[1] XOR A[2] XOR ... XOR A[N] != 0 -> 先手勝利

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    int ans = A[1];
    for (int i = 2; i <= N; i++) {
        ans ^= A[i];
    }

    if (ans) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}