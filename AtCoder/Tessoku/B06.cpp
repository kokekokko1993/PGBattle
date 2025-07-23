#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A[100009], S[100009];
    int Q, L[100009], R[100009];
    cin >> N;
    S[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        S[i] = S[i - 1] + A[i];
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++)
        cin >> L[i] >> R[i];

    for (int i = 1; i <= Q; i++) {
        int atari = S[R[i]] - S[L[i] - 1];
        int hazure = R[i] - L[i] - atari + 1;

        if (atari > hazure) {
            cout << "win" << endl;
        } else if (atari < hazure) {
            cout << "lose" << endl;
        } else {
            cout << "draw" << endl;
        }
    }
    return 0;
}