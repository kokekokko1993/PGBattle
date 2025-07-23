#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
template <class T> struct RmQ : SegmentTree<T> {
    using Base = SegmentTree<T>;
    T f(const T &a, const T &b) const { return min(a, b); }
    RmQ(ll n, const T &def_value) : Base(n, def_value) {}
    RmQ(const vector<T> &v, const T &def_value) : Base(v, def_value) {
        for (ll i = Base::size; --i;)
            Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
    }
};
template <class T> struct RMQ : SegmentTree<T> {
    using Base = SegmentTree<T>;
    T f(const T &a, const T &b) const { return max(a, b); }
    RMQ(ll n, const T &def_value) : Base(n, def_value) {}
    RMQ(const vector<T> &v, const T &def_value) : Base(v, def_value) {
        for (ll i = Base::size; --i;)
            Base::data[i] = f(Base::data[i * 2], Base::data[i * 2 + 1]);
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

int N, Q;

int main() {
    cin >> N >> Q;
    RMQ<int> rMq = RMQ<int>(N, 0);

    for (int i = 1; i <= Q; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        if (t == 1) {
            rMq.set(a - 1, b);
        } else {
            int ans = rMq.get(a - 1, b - 1);
            cout << ans << endl;
        }
    }
    return 0;
}