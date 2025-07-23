#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    vector<ll> data;
    UnionFind(ll n) : data(n, -1) {}
    bool unite(ll a, ll b) {
        a = root(a);
        b = root(b);
        if (a == b) return 0;
        if (data[a] > data[b]) swap(a, b);
        data[a] += data[b];
        data[b] = a;
        return 1;
    }
    bool find(ll a, ll b) { return root(a) == root(b); }
    ll root(ll a) { return data[a] < 0 ? a : data[a] = root(data[a]); }
    ll size(ll a) { return -data[root(a)]; }
    ll operator[](ll a) { return root(a); }
};

int N, Q;

int main() {
    cin >> N >> Q;
    UnionFind uf = UnionFind(N + 1);

    for (int i = 1; i <= Q; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 1) {
            uf.unite(u, v);
        } else {
            if (uf.find(u, v)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << uf.size(i) << endl;
    }
    return 0;
}