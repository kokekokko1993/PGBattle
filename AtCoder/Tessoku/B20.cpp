#include <bits/stdc++.h>
using namespace std;

string S, T;
int dp[2009][2009];

int main() {
    cin >> S >> T;
    for (int j = 0; j <= S.size(); j++) {
        dp[0][j] = j;
    }
    for (int i = 0; i <= T.size(); i++) {
        dp[i][0] = i;
    }

    for (int i = 1; i <= T.size(); i++) {
        for (int j = 1; j <= S.size(); j++) {
            // cout << i << " " << j << " " << S[j - 1] << " " << T[i - 1] << "
            // "
            //      << (S[j - 1] == T[i - 1]) << endl;
            // cout << dp[i - 1][j] + 1 << " " << dp[i][j - 1] + 1 << " "
            //      << dp[i - 1][j - 1] + (1 - S[j - 1] == T[i - 1]) << endl;
            dp[i][j] = min({dp[i - 1][j] + 1, dp[i][j - 1] + 1,
                            dp[i - 1][j - 1] + (1 - (S[j - 1] == T[i - 1]))});
        }
    }
    cout << dp[T.size()][S.size()] << endl;

    // for (int i = 0; i <= T.size(); i++) {
    //     for (int j = 0; j <= S.size(); j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}