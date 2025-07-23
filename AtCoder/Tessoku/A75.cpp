#include <bits/stdc++.h>
using namespace std;

int N, T[109], D[109];
int dp[109][1500];
vector<pair<int, int>> v; // {d, t}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> D[i];
        v.push_back({D[i], T[i]});
    }
    sort(v.begin(), v.end());

    for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 1500; j++) {
            dp[i][j] = -1e6;
        }
    }
    dp[0][0] = 0;
    for (int i = 0; i < v.size(); i++) {
        auto [d, t] = v[i];
        for (int j = 0; j < 1500; j++) {
            if (j + t <= d) {
                dp[i + 1][j + t] = max(dp[i + 1][j + t], dp[i][j] + 1);
            }
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
        }
    }

    int ans = 0;
    for (int j = 0; j < 1500; j++) {
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;

    // for (int i = 0; i <= v.size(); i++) {
    //     for (int j = 0; j <= 10; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}