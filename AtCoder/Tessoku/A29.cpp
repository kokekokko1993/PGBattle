#include <bits/stdc++.h>
using namespace std;

long long MOD = 1e9 + 7;

long long a, b;

long long modpow(long long a, long long b, long long mod) {
    long long base = a;
    long long ans = 1LL;
    while (b > 0) {
        if (b & 1) {
            ans *= base;
            ans %= mod;
        }
        base = base * base;
        base %= mod;
        b /= 2;
    }
    return ans;
}

int main() {
    cin >> a >> b;
    long long ans = modpow(a, b, MOD);
    cout << ans << endl;
    return 0;
}