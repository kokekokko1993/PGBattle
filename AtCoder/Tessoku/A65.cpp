#include <bits/stdc++.h>
using namespace std;

int N, A[100009];
vector<int> g[100009];
int dp[100009];

int dfs(int p) {
    int res = 0;
    for (int i = 0; i < g[p].size(); i++) {
        int b = g[p][i];
        res += dfs(b);
    }
    dp[p] = res;
    // cout << p << " " << res << endl;
    return res + 1;
}

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        dp[i] = 0;
    }
    for (int i = 2; i <= N; i++) {
        cin >> A[i];
        g[A[i]].push_back(i);
    }

    dfs(1);
    for (int i = 1; i <= N; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return 0;
}