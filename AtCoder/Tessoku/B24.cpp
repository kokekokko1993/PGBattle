#include <bits/stdc++.h>
using namespace std;

int N, X[100009], Y[100009];
pair<int, int> boxes[100009];
int dp[100009], L[100009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        boxes[i] = {X[i], -Y[i]};
    }
    sort(boxes + 1, boxes + N + 1);
    for (int i = 1; i <= N; i++) {
        L[i] = 1e9;
    }

    dp[1] = 1;
    L[1] = -boxes[1].second;
    for (int i = 2; i <= N; i++) {
        int idx = lower_bound(L + 1, L + N + 1, -boxes[i].second) - L;
        L[idx] = -boxes[i].second;
        dp[i] = idx;
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << endl;

    // for (int i = 1; i <= N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << L[i] << " ";
    // }
    // cout << endl;
    return 0;
}