#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[59], B[59];
int dp[19][300];
// i章までの割り当てが決まっており、i章の最後のページがjである時の小説の良さの最大値

// 章の区間を[l, r]とするときの区間の良さ
int get_score(int l, int r) {
    int res = 0;
    for (int i = 1; i <= M; i++) {
        if (l <= A[i] && B[i] <= r) res++;
    }
    return res;
}

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
    }
    for (int i = 0; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            dp[i][j] = -1e9;
        }
    }

    dp[0][0] = 0;
    for (int i = 1; i <= K; i++) {
        for (int j = 0; j <= N; j++) {
            int tmp = -1e9;
            for (int k = 0; k < j; k++) {
                tmp = max(tmp, dp[i - 1][k] + get_score(k + 1, j));
            }
            dp[i][j] = tmp;
        }
    }

    cout << dp[K][N] << endl;
    return 0;
}