#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N, K, A[100009], S[100009];
    cin >> N >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }

    for (int i = 0; i <= N; i++) {
        S[i] = 0;
    }
    for (int i = 1; i <= N; i++) {
        S[i] = S[i - 1] + A[i];
    }

    int r = 0;
    long long ans = 0;
    for (int l = 1; l <= N; l++) {
        while (r < N && S[r + 1] - S[l - 1] <= K) {
            r++;
        }
        ans += r - l + 1;
        // cout << l << " " << r << " " << ans << endl;
    }
    cout << ans << endl;

    return 0;
}