#include <bits/stdc++.h>
using namespace std;

long long N, W, w[109], v[109];
long long dp[109][100009];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            dp[i][j] = -1e12;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            if (j - w[i] >= 0) {
                dp[i][j] =
                    max({dp[i][j], dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]});
            } else {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }
    long long ans = -1e12;
    for (int j = 0; j <= W; j++) {
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
    return 0;
}