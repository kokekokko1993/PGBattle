#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, A[100009];
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    // A[N + 1] = 1e12;
    // long long ans = 0;
    // for (int i = 1; i < N; i++) {
    //     long long tmp = upper_bound(A + i, A + N + 2, A[i] + K) - A - i - 1;
    //     ans += tmp;
    // }
    // cout << ans << endl;

    A[N + 1] = 1e12;
    long long ans = 0;
    int r = 1;
    for (int i = 1; i <= N - 1; i++) {
        while (r < N && A[r + 1] - A[i] <= K) {
            r++;
        }
        ans += r - i;
    }
    cout << ans << endl;
    return 0;
}