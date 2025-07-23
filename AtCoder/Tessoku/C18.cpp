#include <bits/stdc++.h>
using namespace std;

int N;
int A[500];
int dp[500][500]; // 区間[i, j]を取り除く際のコストの和の最小値

int main() {
    cin >> N;
    for (int i = 1; i <= N * 2; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= 2 * N; i++) {
        for (int j = 1; j <= 2 * N; j++) {
            dp[i][j] = 1e9;
        }
    }

    for (int i = 1; i <= 2 * N; i++) {
        dp[i][i] = 0;
    }
    for (int i = 1; i < 2 * N; i++) {
        dp[i][i + 1] = abs(A[i] - A[i + 1]);
    }

    for (int LEN = 3; LEN <= 2 * N - 1; LEN += 2) {
        for (int i = 1; i <= 2 * N - LEN; i++) {
            int j = i + LEN;
            int tmp = 1e9;
            for (int k = i; k <= j - 1; k++) {
                tmp = min(tmp, dp[i][k] + dp[k + 1][j]);
            }
            tmp = min(tmp, abs(A[i] - A[j]) + dp[i + 1][j - 1]);
            dp[i][j] = tmp;
        }
    }

    cout << dp[1][2 * N] << endl;

    // for (int i = 1; i <= 2 * N; i++) {
    //     for (int j = 1; j <= 2 * N; j++) {
    //         cout << setw(10) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}