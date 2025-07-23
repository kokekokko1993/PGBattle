#include <bits/stdc++.h>
using namespace std;

int N;
int P[109][109];
int row[109], col[109];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> P[i][j];
            if (P[i][j] > 0) {
                row[P[i][j]] = i;
                col[P[i][j]] = j;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int ii = i + 1; ii <= N; ii++) {
            if (row[i] > row[ii]) ans++;
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int ii = i + 1; ii <= N; ii++) {
            if (col[i] > col[ii]) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}