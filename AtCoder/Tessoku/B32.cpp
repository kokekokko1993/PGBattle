#include <bits/stdc++.h>
using namespace std;

int N, K, a[100009];
bool dp[10000009];

int main() {
    cin >> N >> K;
    for (int i = 1; i <= K; i++) {
        cin >> a[i];
    }

    for (int i = 0; i <= N; i++) {
        bool tmp = false;
        for (int j = 1; j <= K; j++) {
            if (i >= a[j] && dp[i - a[j]] == false) {
                tmp |= true;
                break;
            }
        }
        dp[i] = tmp;
    }
    if (dp[N]) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}