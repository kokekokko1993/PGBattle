#include <bits/stdc++.h>
using namespace std;

int N, K;
int dp[31][300009];

int ketawa(int n) {
    // cout << n << endl;
    int ans = 0;
    while (n > 0) {
        ans += n % 10;
        n /= 10;
    }
    // cout << n << " ketawa: " << ans << endl;
    return ans;
}

int main() {
    cin >> N >> K;

    for (int i = 0; i <= N; i++) {
        dp[0][i] = i - ketawa(i);
        // cout << "dp[0][" << i << "]: " << dp[0][i] << endl;
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (int i = 1; i <= N; i++) {
        int current = i;
        int tmp = K, count = 0;
        while (tmp > 0) {
            if (tmp & 1) {
                current = dp[count][current];
            }
            tmp /= 2;
            count++;
        }
        cout << current << endl;
    }
    return 0;
}