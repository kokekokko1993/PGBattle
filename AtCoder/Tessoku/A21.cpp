#include <bits/stdc++.h>
using namespace std;

int N, P[2009], A[2009];
int dp[2009][2009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> P[i] >> A[i];
    }

    dp[1][N] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = N; j >= i; j--) {
            if (i > 1 && j < N) {
                dp[i][j] = max(
                    dp[i - 1][j]
                        + A[i - 1] * ((i - 1 <= P[i - 1]) && (P[i - 1] <= j)),
                    dp[i][j + 1]
                        + A[j + 1] * ((i <= P[j + 1]) && (P[j + 1] <= j + 1)));
            } else if (i > 1) {
                dp[i][j] =
                    dp[i - 1][j]
                    + A[i - 1] * ((i - 1 <= P[i - 1]) && (P[i - 1] <= j));
            } else if (j < N) {
                dp[i][j] =
                    dp[i][j + 1]
                    + A[j + 1] * ((i <= P[j + 1]) && (P[j + 1] <= j + 1));
            }
        }
    }

    int res = 0;
    for (int i = 1; i <= N; i++) {
        res = max(res, dp[i][i]);
    }
    cout << res << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}