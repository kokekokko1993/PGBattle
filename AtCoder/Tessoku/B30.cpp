#include <bits/stdc++.h>
using namespace std;

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

long long moddiv(long long a, long long b, long long mod) {
    long long ans = a * modpow(b, mod - 2, mod);
    ans %= mod;
    return ans;
}

long long modfactorial(long long n, long long mod) {
    long long ans = 1;
    for (int i = 2; i <= n; i++) {
        ans *= i;
        ans %= mod;
    }
    return ans;
}

long long modcombination(long long n, long long r, long long mod) {
    long long ans = moddiv(modfactorial(n, mod), modfactorial(r, mod), mod);
    ans = moddiv(ans, modfactorial(n - r, mod), mod);
    return ans;
}

long long MOD = 1e9 + 7;
long long H, W;

int main() {
    cin >> H >> W;
    long long ans = modcombination(H + W - 2, H - 1, MOD);

    cout << ans << endl;
    return 0;
}