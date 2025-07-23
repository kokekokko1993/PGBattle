#include <bits/stdc++.h>
using namespace std;

int N, C[100009], S[100009];
int Q, X[100009];

int main() {
    cin >> N;
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> C[i];
    }
    sort(C + 1, C + N + 1);
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + C[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> X[i];
    }

    for (int i = 1; i <= Q; i++) {
        int idx = upper_bound(S + 1, S + N + 1, X[i]) - S;
        cout << idx - 1 << endl;
    }
    return 0;
}