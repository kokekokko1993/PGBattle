#include <bits/stdc++.h>
using namespace std;

// ポイントをW: 0, B: 1, R: 2とする
// カードのポイントの合計をスコアと呼ぶ
// 6つの操作はスコアを-3 or -0するので3で割った余りは変わらない
// →不変量発見！！！
// →最初のスコアを3で割った余りに対応する色が答えになる

int N;
char C;
string A;
char colors[3] = {'W', 'B', 'R'};

int main() {
    cin >> N >> C >> A;
    int score = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] == 'W') {
            score += 0;
            score %= 3;
        } else if (A[i] == 'B') {
            score += 1;
            score %= 3;
        } else if (A[i] == 'R') {
            score += 2;
            score %= 3;
        }
    }

    if (colors[score] == C) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}