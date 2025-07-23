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

const long long MOD = 1e9 + 7;
long long n, r;

typedef ModInt<MOD> mint;

mint factorial(long long n) {
    mint res = mint(1);
    for (int i = 2; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main() {
    cin >> n >> r;
    // long long ans = modcombination(n, r, MOD);
    mint ans = factorial(n) / factorial(r) / factorial(n - r);
    cout << ans << endl;

    return 0;
}