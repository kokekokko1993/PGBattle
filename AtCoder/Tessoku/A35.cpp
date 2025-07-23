#include <bits/stdc++.h>
using namespace std;

/*
dp[i][j]: ゲームが状態(i,
j)まで進行したとき、ここから両者が最善を尽くした時のスコア
最下段ではdp[N][j]=A[j]となる。下から上に遷移していけばOK！
・dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) (iが奇数)
・dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]) (iが偶数)
*/

int N, A[100009];
int dp[2009][100009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        dp[N][i] = A[i];
    }

    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            if (i % 2 == 1) {
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]);
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
    }
    cout << dp[1][1] << endl;
    return 0;
}