#include <bits/stdc++.h>
using namespace std;

int N, X[20], Y[20];
// dp[i][j] -> i: 通った都市、j: 今いる都市 の時の最短時間
double dp[1 << 20][20];

double dist(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
    }
    for (int i = 0; i < (1 << N); i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = 1e9;
        }
    }

    // for (int j = 1; j <= N; j++) {
    //     int idx = (1 << (j - 1)) - 1;
    //     dp[idx][idx] = 0;
    // }
    dp[1][1] = 0; // 最初は都市1から出発するとしても一般性を失わない！！

    for (int i = 1; i < (1 << N); i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 1; k <= N; k++) {
                int visited = i | (1 << (k - 1));
                dp[visited][k] = min(dp[visited][k],
                                     dp[i][j] + dist(X[j], Y[j], X[k], Y[k]));
            }
        }
    }

    // double ans = 1e9;
    // for (int i = 1; i <= N; i++) {
    //     ans = min(ans, dp[(1 << N) - 1][i] + dist(X[1], Y[1], X[i], Y[i]));
    // }
    // 上をやらなくても最後に位置1にいるdp[(1<<N)-1][1]が答え！！！
    double ans = dp[(1 << N) - 1][1];
    cout << setprecision(15) << ans << endl;
    // for (int i = 1; i < (1 << N); i++) {
    //     for (int j = 1; j <= N; j++) {
    //         cout << setw(20) << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}