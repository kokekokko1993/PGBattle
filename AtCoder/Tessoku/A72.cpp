#include <bits/stdc++.h>
using namespace std;

int H, W, K;
char c[11][101], tmp[11][101];

void reset() {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            tmp[i][j] = c[i][j];
        }
    }
}

int main() {
    cin >> H >> W >> K;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> c[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < (1 << H); i++) {
        int count = 0;
        reset();
        // 行選択
        for (int ii = 0; ii < H; ii++) {
            if ((i & (1 << ii)) && count < K) {
                count++;
                for (int j = 0; j < W; j++) {
                    tmp[ii][j] = '#';
                }
            }
        }

        // 列選択
        pair<int, int> colval[W];
        for (int j = 0; j < W; j++) {
            int val = 0;
            for (int ii = 0; ii < H; ii++) {
                val += (tmp[ii][j] == '#');
            }
            colval[j] = {val, j};
        }
        sort(colval, colval + W);
        for (int k = 0; k < K - count; k++) {
            int j = colval[k].second;
            for (int ii = 0; ii < H; ii++) {
                tmp[ii][j] = '#';
            }
        }

        int res = 0;
        for (int ii = 0; ii < H; ii++) {
            for (int j = 0; j < W; j++) {
                res += (tmp[ii][j] == '#');
            }
        }
        ans = max(ans, res);
    }
    cout << ans << endl;
    return 0;
}