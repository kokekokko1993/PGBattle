#include <bits/stdc++.h>
using namespace std;

int H, W, N;
int A[100009], B[100009], C[100009], D[100009];
int T[1509][1509], S[1509][1509];

int main() {
    cin >> H >> W >> N;
    for (int i = 0; i <= H; i++) {
        for (int j = 0; j <= W; j++) {
            T[i][j] = S[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];

        T[A[i]][B[i]] += 1;
        T[A[i]][D[i] + 1] -= 1;
        T[C[i] + 1][B[i]] -= 1;
        T[C[i] + 1][D[i] + 1] += 1;
    }
    // cumsum
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            S[i][j] = S[i - 1][j] + T[i][j];
        }
    }
    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            S[i][j] = S[i][j - 1] + S[i][j];
        }
    }

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            cout << S[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}