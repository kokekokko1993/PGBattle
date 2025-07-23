#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

long long N, a[10000009];

int main() {
    cin >> N;

    a[1] = 1;
    a[2] = 1;
    for (int i = 3; i <= N; i++) {
        a[i] = a[i - 1] + a[i - 2];
        a[i] %= MOD;
    }
    cout << a[N] << endl;
    return 0;
}