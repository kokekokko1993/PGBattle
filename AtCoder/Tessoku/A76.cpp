#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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

// indexは0-origin
// rangeは半開区間[l, r)と扱われる
template <class T> struct SegmentTree {
    virtual T f(const T &, const T &) const = 0;
    const T def_value;
    ll size = 1, rank = 0, expected_size;
    vector<T> data;
    SegmentTree(ll n, const T &def_value)
        : def_value(def_value), expected_size(n) {
        while (size < expected_size) {
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
    }
    SegmentTree(const vector<T> &v, const T &def_value)
        : def_value(def_value), expected_size(v.size()) {
        while (size < expected_size) {
            size *= 2;
            rank++;
        }
        data.assign(size * 2, def_value);
        for (ll i = 0; i < v.size(); i++)
            data[size + i] = v[i];
        // for(ll i = Base::size; --i;) Base::data[i] = f(Base::data[i * 2],
        // Base::data[i * 2 + 1]);
    }
    T operator[](ll at) const { return data[size + at]; }
    void update(ll at) {
        while (at /= 2)
            data[at] = f(data[at * 2], data[at * 2 + 1]);
    }
    void set(ll at, const T &val) {
        at += size;
        data[at] = val;
        update(at);
    }
    void add(ll at, const T &val) {
        at += size;
        data[at] += val;
        update(at);
    }
    T get(ll l, ll r) const {
        T L = def_value, R = def_value;
        l += size;
        r += size;
        for (; l < r; l /= 2, r /= 2) {
            if (l & 1) L = f(L, data[l++]);
            if (r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }
    template <class F>
    ll find_last(const F &check,
                 ll l = 0) const { // max x  s.t. check(get(l, x)) == true
        if (l == expected_size) return expected_size;
        ll height = 0, at = l + size;
        T val = def_value;
        for (; height <= rank; height++)
            if (at >> height & 1) {
                T val2 = f(val, data[at >> height]);
                if (check(val2)) {
                    at += 1 << height;
                    if (at == size * 2) return expected_size;
                    val = val2;
                } else break;
            }
        for (; height--;) {
            T val2 = f(val, data[at >> height]);
            if (check(val2)) {
                at += 1 << height;
                if (at == size * 2) return expected_size;
                val = val2;
            }
        }
        return min(at - size, expected_size);
    }
    template <class F>
    ll find_first(const F &check,
                  ll r) const { // min x  s.t. check(get(x, r)) == true
        if (!r) return 0;
        ll height = 0, at = r + size;
        T val = def_value;
        for (; height <= rank; height++)
            if (at >> height & 1) {
                T val2 = f(val, data[at >> height ^ 1]);
                if (check(val2)) {
                    at -= 1 << height;
                    if (at == size) return 0;
                    val = val2;
                } else break;
            }
        for (; height--;) {
            T val2 = f(val, data[(at >> height) - 1]);
            if (check(val2)) {
                at -= 1 << height;
                if (at == size) return 0;
                val = val2;
            }
        }
        return at - size;
    }
    void clear() {
        for (auto &i : data)
            i = def_value;
    }
};

template <class T> struct RSQ : SegmentTree<T> {
    using Base = SegmentTree<T>;
    T f(const T &a, const T &b) const { return a + b; }
    RSQ(ll n, const T &def_value = T()) : Base(n, def_value) {}
    RSQ(const vector<T> &v, const T &def_value = T()) : Base(v, def_value) {
        for (ll i = Base::size; --i;)
            Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};

typedef ModInt<1000000007> mint;

int N, W, L, R;
int X[150009];

int main() {
    cin >> N >> W >> L >> R;
    for (int i = 1; i <= N; i++) {
        cin >> X[i];
    }
    X[0] = 0;
    X[N + 1] = W;

    RSQ rsq = RSQ<mint>(N + 2, 0);
    rsq.set(0, 1);
    for (int i = 1; i <= N + 1; i++) {
        int l = 0, r = -1;
        l = lower_bound(X, X + N + 2, X[i] - R) - X;
        r = upper_bound(X, X + N + 2, X[i] - L) - X;
        // if (X[i] > R) {
        //     l = X[i] - R;
        //     r = X[i] - L;
        // } else if (X[i] > L) {
        //     l = 0;
        //     r = X[i] - L;
        // }
        rsq.set(i, rsq.get(l, r).get());
    }
    cout << rsq.get(N + 1, N + 2).get() << endl;
    return 0;
}