#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, W, w[109], v[109];
ll dp[109][100009];

int main() {
    cin >> N >> W;
    for (int i = 1; i <= N; i++) {
        cin >> w[i] >> v[i];
    }
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= 1e5; j++) {
            dp[i][j] = 1e12;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 1e5; j++) {
            if (j - v[i] >= 0) {
                dp[i][j] =
                    min({dp[i][j], dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]});
            } else {
                dp[i][j] = min({dp[i][j], dp[i - 1][j]});
            }
        }
    }
    ll ans = 0;
    for (ll j = 0; j <= 1e5; j++) {
        if (dp[N][j] <= W) {
            ans = max(ans, j);
        }
    }
    // for (ll j = 0; j <= 10; j++) {
    //     cout << dp[N][j] << " ";
    // }
    // cout << endl;
    cout << ans << endl;
    return 0;
}