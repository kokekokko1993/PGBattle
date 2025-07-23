#include <bits/stdc++.h>
using namespace std;

int N, Q;
int A[100009], X[100009], Y[100009];
int dp[31][100009];

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 1; i <= Q; i++) {
        cin >> X[i] >> Y[i];
    }

    for (int i = 1; i <= N; i++) {
        dp[0][i] = A[i];
    }
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= N; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }

    for (int i = 1; i <= Q; i++) {
        int tmp = Y[i], count = 0;
        int current = X[i];
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