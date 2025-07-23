#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int tmp = K - (i + j);
            if (tmp >= 1 && tmp <= N) {
                ans += 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}