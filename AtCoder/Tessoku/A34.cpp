#include <bits/stdc++.h>
using namespace std;

/*
Grundy数：
一回の操作でGrundy数がx1, x2, ..., xkの盤面に遷移することができる場合、
子の盤面のGrundy数は「x1, x2, ..., xk以外の最小の非負整数」である。
→遷移先が存在しないときはGrundy数は0となる

性質(1)
Grundy数が0 -> 負け
※Grundy数が0の盤面に遷移できるとき：Grundy数は1以上
  Grundy数が0の盤面に遷移できないとき：Grundy数は0

性質(2)
山が二つ以上の場合
山iのGrundy数がGiのとき、
※Grundy数が0の盤面に遷移できるとき：Grundy数は1以上
・G1 XOR G2 XOR ... XOR GN = 0：後手必勝(負けの状態)
・G1 XOR G2 XOR ... XOR GN ≠ 0：先手必勝(勝ちの状態)
*/

long long N, X, Y, A[1000009];
int G[1000009];

int main() {
    cin >> N >> X >> Y;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // calc grundy
    for (int i = 0; i <= 1000000; i++) {
        bool tmp[3] = {false, false, false};
        if (i >= X) {
            tmp[G[i - X]] = true;
        }
        if (i >= Y) {
            tmp[G[i - Y]] = true;
        }

        // if (!tmp[0]) G[i] = 0;
        // else if (!tmp[1]) G[i] = 1;
        // else G[i] = 2;

        int res = 0;
        for (int i = 0; i < 3; i++) {
            if (tmp[i] == false) {
                res = i;
                break;
            }
        }
        G[i] = res;
    }

    // calc answer
    int XOR_sum = 0;
    for (int i = 1; i <= N; i++) {
        XOR_sum ^= G[A[i]];
    }
    if (XOR_sum) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }

    // for (int i = 0; i <= 10; i++) {
    //     cout << G[i] << " ";
    // }
    // cout << endl;
    return 0;
}