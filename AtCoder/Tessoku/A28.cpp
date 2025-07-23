#include <bits/stdc++.h>
using namespace std;

long long N, A[100009];
char T[100009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> T[i] >> A[i];
    }

    long long ans = 0;
    for (int i = 1; i <= N; i++) {
        if (T[i] == '+') {
            ans += A[i];
        } else if (T[i] == '-') {
            ans -= A[i];
        } else {
            ans *= A[i];
        }
        if (ans < 0) ans += 10000;
        ans %= 10000;
        cout << ans << endl;
    }
    return 0;
}