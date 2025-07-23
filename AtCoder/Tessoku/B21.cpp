#include <bits/stdc++.h>
using namespace std;

int N;
string S;
int dp[1009][1009];

int main() {
    cin >> N;
    cin >> S;

    for (int i = 1; i <= N; i++) {
        dp[i][i] = 1;
    }
    for (int l = 1; l <= N - 1; l++) {
        dp[l][l + 1] = (S[l - 1] == S[l] ? 2 : 1);
    }
    for (int LEN = 2; LEN <= N - 1; LEN++) {
        for (int l = 1; l <= N - LEN; l++) {
            int r = l + LEN;

            if (r > 1 && l < N) {
                dp[l][r] = max({dp[l + 1][r], dp[l][r - 1],
                                dp[l + 1][r - 1] + 2 * (S[l - 1] == S[r - 1])});
            } else if (l < N) {
                dp[l][r] = dp[l + 1][r];
            } else if (r > 1) {
                dp[l][r] = dp[l][r - 1];
            }
        }
    }
    cout << dp[1][N] << endl;
    // for (int i = 1; i <= N; i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}