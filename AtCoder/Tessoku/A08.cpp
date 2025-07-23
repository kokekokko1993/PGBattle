#include <bits/stdc++.h>
using namespace std;

int H, W;
int X[1509][1509], S[1509][1509];
int Q, A[100009], B[100009], C[100009], D[100009];

int main() {
    cin >> H >> W;
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            X[i][j] = S[i][j] = 0;
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cin >> X[i][j];
        }
    }
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            S[i][j] = S[i - 1][j] + X[i][j];
        }
    }
    for (int j = 1; j <= W; j++) {
        for (int i = 1; i <= H; i++) {
            S[i][j] = S[i][j - 1] + S[i][j];
        }
    }

    for (int i = 1; i <= Q; i++) {
        int res = S[C[i]][D[i]] - S[C[i]][B[i] - 1] - S[A[i] - 1][D[i]] +
                  S[A[i] - 1][B[i] - 1];
        cout << res << endl;
    }

    return 0;
}