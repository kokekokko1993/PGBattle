#include <bits/stdc++.h>
using namespace std;

int N, M;
bool A[109][19];
int dp[109][2009];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i <= M; i++) {
        for (int j = 0; j <= (1 << N) - 1; j++) {
            dp[i][j] = 1e9;
        }
    }

    // dp[0][0] = 0;
    for (int i = 0; i <= M; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i <= M; i++) {
        int current = 0;
        for (int j = 1; j <= N; j++) {
            current |= (1 << (j - 1)) * A[i][j];
        }

        for (int j = 0; j <= (1 << N) - 1; j++) {
            int tmp = j | current;
            // cout << current << " " << j << " " << tmp << endl;
            dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            dp[i][tmp] = min({dp[i][tmp], dp[i - 1][tmp], dp[i - 1][j] + 1});
        }
    }
    if (dp[M][(1 << N) - 1] > 1e5) {
        cout << -1 << endl;
    } else {
        cout << dp[M][(1 << N) - 1] << endl;
    }

    // for (int i = 0; i <= M; i++) {
    //     for (int j = 0; j <= (1 << N) - 1; j++) {
    //         cout << setw(10) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}