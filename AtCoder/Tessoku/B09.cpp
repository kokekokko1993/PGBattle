#include <bits/stdc++.h>
using namespace std;

int N, A[100009], B[100009], C[100009], D[100009];
int T[1509][1509], S[1509][1509];

int main() {
    cin >> N;
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            T[i][j] = S[i][j] = 0;
        }
    }

    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        T[A[i]][B[i]] += 1;
        T[C[i]][B[i]] -= 1;
        T[A[i]][D[i]] -= 1;
        T[C[i]][D[i]] += 1;
    }

    // cumsum
    for (int j = 0; j <= 1500; j++) {
        S[0][j] = T[0][j];
    }
    for (int i = 1; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            S[i][j] = S[i - 1][j] + T[i][j];
        }
    }
    for (int i = 0; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) {
            S[i][j] = S[i][j - 1] + S[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            ans += S[i][j] > 0;
        }
    }
    // for (int i = 1; i <= 10; i++) {
    //     for (int j = 1; j <= 10; j++) {
    //         cout << S[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}