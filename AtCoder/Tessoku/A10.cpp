#include <bits/stdc++.h>
using namespace std;

int N, A[100009];
int D, L[100009], R[100009];
int lM[100009], rM[100009];

int main() {
    cin >> N;
    for (int i = 0; i <= N + 1; i++) {
        A[i] = lM[i] = rM[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 1; i <= N; i++) {
        lM[i] = max(A[i], lM[i - 1]);
    }
    for (int i = N; i >= 1; i--) {
        rM[i] = max(A[i], rM[i + 1]);
    }

    // for (int i = 1; i <= N; i++) {
    //     cout << lM[i] << " ";
    // }
    // cout << endl;
    // for (int i = 1; i <= N; i++) {
    //     cout << rM[i] << " ";
    // }
    // cout << endl;

    cin >> D;
    for (int i = 1; i <= D; i++) {
        cin >> L[i] >> R[i];
        // cout << lM[L[i] - 1] << " " << rM[R[i] + 1] << endl;
        int ans = max(lM[L[i] - 1], rM[R[i] + 1]);
        cout << ans << endl;
    }

    return 0;
}