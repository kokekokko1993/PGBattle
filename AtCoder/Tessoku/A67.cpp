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

int N, M;
int A[100009], B[100009], C[100009];
vector<tuple<int, int, int>> t; // {C, A, B}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i] >> C[i];
        t.push_back({C[i], A[i], B[i]});
    }
    sort(t.begin(), t.end());
    UnionFind uf = UnionFind(N + 1);

    int ans = 0;
    for (int i = 0; i < t.size(); i++) {
        auto [c, a, b] = t[i];
        // cout << a << " " << b << " " << c << endl;
        if (!uf.find(a, b)) {
            uf.unite(a, b);
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}