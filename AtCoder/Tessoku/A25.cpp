#include <bits/stdc++.h>
using namespace std;

int H, W;
string c[39];
long long ans[39][39];

int main() {
    cin >> H >> W;
    for (int i = 0; i < H; i++) {
        cin >> c[i];
    }
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            ans[i][j] = 0;
        }
    }
    ans[0][0] = 1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (i + 1 < H && c[i + 1][j] == '.') {
                ans[i + 1][j] += ans[i][j];
            }
            if (j + 1 < W && c[i][j + 1] == '.') {
                ans[i][j + 1] += ans[i][j];
            }
        }
    }
    cout << ans[H - 1][W - 1] << endl;

    // for (int i = 0; i < H; i++) {
    //     for (int j = 0; j < W; j++) {
    //         cout << ans[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return 0;
}