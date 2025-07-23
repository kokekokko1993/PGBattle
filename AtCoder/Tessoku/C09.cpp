#include <bits/stdc++.h>
using namespace std;

int N;
long long A[500009];
long long
    dp[500009]
      [2]; // dp[i][j]:
           // i日目にj=0勉強したとき、j=1勉強しなかったときの累計実力の最大値

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    dp[0][0] = dp[0][1] = 0;
    for (int i = 1; i <= N; i++) {
        dp[i][0] = dp[i - 1][1] + A[i];
        dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]);
    }
    long long ans = max(dp[N][0], dp[N][1]);
    cout << ans << endl;
    return 0;
}