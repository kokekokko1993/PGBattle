#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    int A[100009], S[100009];
    S[0] = 0;
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }

    int L, R;
    for (int i = 0; i < Q; i++) {
        cin >> L >> R;
        int ans = S[R] - S[L - 1];
        cout << ans << endl;
    }
    return 0;
}