#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const ull mod = 0x1fffffffffffffff,
          base = chrono::duration_cast<chrono::microseconds>(
                     chrono::system_clock::now().time_since_epoch())
                     .count()
                 % mod;

struct RollingHash {
    vector<ull> hashed, power;

    static constexpr ull mask(ll a) { return (1ULL << a) - 1; }

    inline ull mul(ull a, ull b) const {
        //*
        __uint128_t ans = __uint128_t(a) * b;
        /*/
         // without __uint128_t
         ull a31 = a >> 31, b31 = b >> 31;
         a &= mask(31);
         b &= mask(31);
         ull x = a * b31 + b * a31;
         ull ans = (a31 * b31 << 1) + (x >> 30) + ((x & mask(30)) << 31) + a *
         b;
         //*/
        ans = (ans >> 61) + (ans & mod);
        if (ans >= mod) ans -= mod;
        return ans;
    }

    RollingHash(const string &s) {
        ll n = s.size();
        hashed.assign(n + 1, 0);
        power.assign(n + 1, 0);
        power[0] = 1;
        for (ll i = 0; i < n; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    ull get(ll l, ll r) const {
        ull ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
        if (ret >= mod) ret -= mod;
        return ret;
    }

    ull connect(ull h1, ull h2, ll h2len) const {
        ull ret = mul(h1, power[h2len]) + h2;
        if (ret >= mod) ret -= mod;
        return ret;
    }

    void connect(const string &s) {
        ll n = hashed.size() - 1, m = s.size();
        hashed.resize(n + m + 1);
        power.resize(n + m + 1);
        for (ll i = n; i < n + m; i++) {
            power[i + 1] = mul(power[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i - n];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    ll LCP(const RollingHash &b, ll l1, ll r1, ll l2, ll r2) {
        ll len = min(r1 - l1, r2 - l2);
        ll low = -1, high = len + 1;
        while (high - low > 1) {
            ll mid = (low + high) / 2;
            if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
            else high = mid;
        }
        return low;
    }
};

int N, Q;
string S;
int L[100009], R[100009];

int main() {
    cin >> N >> Q >> S;
    for (int i = 1; i <= Q; i++) {
        cin >> L[i] >> R[i];
    }
    RollingHash rh1 = RollingHash(S);
    reverse(S.begin(), S.end());
    RollingHash rh2 = RollingHash(S);

    for (int i = 1; i <= Q; i++) {
        if (rh1.get(L[i] - 1, R[i])
            == rh2.get(S.size() - R[i], S.size() - L[i] + 1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}