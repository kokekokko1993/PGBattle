#include <bits/stdc++.h>
using namespace std;

int N, A, B;
bool dp[100009]; // dp[i]: 残りi個の状況が先手必勝->1, 後手必勝->0
// 負けの状態に遷移できるときは先手が勝つ！！

int main() {
    cin >> N >> A >> B;
    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (i >= A && dp[i - A] == false) {
            dp[i] = true;
        } else if (i >= B && dp[i - B] == false) {
            dp[i] = true;
        } else {
            dp[i] = false;
        }
    }

    if (dp[N]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    // for (int i = 0; i <= N; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    return 0;
}