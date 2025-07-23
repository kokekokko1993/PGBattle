#include <bits/stdc++.h>
using namespace std;

int N, M, A[19];
int X[109], Y[109], Z[109];
int dp[1024]; // dp[i]: i(=bit合計)までの最小回数

int rev(int val, int a, int b, int c) {
    int tmp = val;
    if (val & (1 << (a - 1))) {
        tmp -= 1 << (a - 1);
    } else {
        tmp += 1 << (a - 1);
    }

    if (val & (1 << (b - 1))) {
        tmp -= 1 << (b - 1);
    } else {
        tmp += 1 << (b - 1);
    }

    if (val & (1 << (c - 1))) {
        tmp -= 1 << (c - 1);
    } else {
        tmp += 1 << (c - 1);
    }
    return tmp;
}

int main() {
    cin >> N >> M;
    int init = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        init += (1 << i) * (A[i]);
    }
    for (int i = 1; i <= M; i++) {
        cin >> X[i] >> Y[i] >> Z[i];
    }

    for (int i = 0; i < (1 << N); i++) {
        dp[i] = -1;
    }
    // dp[init] = 0;
    queue<pair<int, int>> q; // {bit_val, move_val}
    q.push({init, 0});
    while (!q.empty()) {
        auto [current, n_move] = q.front();
        q.pop();
        if (dp[current] >= 0) {
            continue;
        }
        dp[current] = n_move;
        for (int i = 1; i <= M; i++) {
            int next = rev(current, X[i], Y[i], Z[i]);
            // cout << current << " " << next << endl;
            q.push({next, n_move + 1});
        }
    }
    cout << dp[(1 << N) - 1] << endl;
    return 0;
}