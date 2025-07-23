#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, h[100009], dp[100009];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);

    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << dp[N] << endl;
    return 0;
}