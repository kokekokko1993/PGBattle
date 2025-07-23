#include <bits/stdc++.h>
using namespace std;

template <int mod> class ModInt {
    int x;

  public:
    ModInt() : x(0) {}

    ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator-=(const ModInt &p) {
        if ((x += mod - p.x) >= mod) x -= mod;
        return *this;
    }

    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }

    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+() const { return ModInt(*this); }

    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }

    bool operator!=(const ModInt &p) const { return x != p.x; }

    ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    ModInt pow(int64_t n) const {
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
        return os << p.x;
    }

    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        int64_t t;
        is >> t;
        a = ModInt<mod>(t);
        return (is);
    }

    int get() const { return x; }

    static constexpr int get_mod() { return mod; }
};

const long long MOD = 1000000007;
typedef ModInt<MOD> mint;

long long N, P;
mint A[100009];
map<long long, long long> mp;

int main() {
    cin >> N >> P;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        mp[A[i].get()]++;
    }

    // (n*m) / mod => p -> n*m = K * mod + p -> m = (p)/n
    long long ans = 0;
    mint mP = mint(P);
    for (auto [k, v] : mp) {
        // cout << k << " " << v << endl;
        long long inv = (mint(P) / mint(k)).get();
        // cout << "v: " << k << ", inv: " << inv << endl;
        if (k == inv) {
            ans += v * (v - 1) / 2;
            // cout << ans << endl;
        } else {
            ans += mp[inv] * v;
            mp[k] = 0;
        }
    }
    cout << ans << endl;
    cout << mint(5) / mint(0) << endl;
    cout << mint(0).inverse() << endl;
    // cout << 5 / 0 << endl;
    return 0;
}