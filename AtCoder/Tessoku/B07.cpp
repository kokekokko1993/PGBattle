#include <bits/stdc++.h>
using namespace std;

int main() {
    int T, N;
    int L[500009], R[500009];
    int D[500009], S[500009];
    cin >> T >> N;
    for (int i = 0; i <= T; i++) {
        D[i] = S[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> L[i] >> R[i];
        D[L[i]] += 1;
        D[R[i]] -= 1;
    }
    for (int i = 0; i < T; i++) {
        if (i == 0) {
            S[i] = D[i];
        } else {
            S[i] = S[i - 1] + D[i];
        }
    }
    for (int i = 0; i < T; i++) {
        cout << S[i] << endl;
    }
    return 0;
}