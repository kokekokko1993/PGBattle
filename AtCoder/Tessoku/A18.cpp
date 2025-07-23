#include <bits/stdc++.h>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= 1000; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= 10000; j++) {
            if (j - A[i] >= 0) {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - A[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    if (dp[N][S]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}