#include <bits/stdc++.h>
using namespace std;

int N, T, A[100009], B[100009];
vector<int> g[100009];
int dp[100009];

int dfs(int p, int pre) {
    // if (dp[p] >= 0) {
    //     return dp[p];
    // }
    int res = -1;
    for (int i = 0; i < g[p].size(); i++) {
        int b = g[p][i];
        if (b == pre) continue;
        res = max(res, dfs(b, p));
    }
    dp[p] = res + 1;
    // cout << p << " " << res << endl;
    return dp[p];
}

int main() {
    cin >> N >> T;
    for (int i = 1; i <= N; i++) {
        dp[i] = -1;
    }
    for (int i = 1; i <= N - 1; i++) {
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }

    dfs(T, -1);
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}