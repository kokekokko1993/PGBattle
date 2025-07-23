#include <bits/stdc++.h>
using namespace std;

int N, Q;
int A[509][509];
int idx[509];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 1; i <= N; i++) {
        idx[i] = i;
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int t, x, y;
        cin >> t >> x >> y;

        if (t == 1) {
            swap(idx[x], idx[y]);
        } else if (t == 2) {
            cout << A[idx[x]][y] << endl;
        }
    }
    return 0;
}