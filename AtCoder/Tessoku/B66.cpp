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

int N, M, Q;
int A[100009], B[100009];
int q[100009][3];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
    }

    cin >> Q;
    vector<bool> restored(N + 1, false);
    for (int i = 1; i <= Q; i++) {
        cin >> q[i][0];
        if (q[i][0] == 1) {
            cin >> q[i][1];
            restored[q[i][1]] = true;
        } else {
            cin >> q[i][1] >> q[i][2];
        }
    }

    UnionFind uf = UnionFind(N + 1);
    for (int i = 1; i <= M; i++) {
        if (!restored[i]) {
            uf.unite(A[i], B[i]);
        }
    }

    vector<string> ans;
    for (int i = Q; i >= 1; i--) {
        if (q[i][0] == 1) {
            uf.unite(A[q[i][1]], B[q[i][1]]);
        } else {
            if (uf.find(q[i][1], q[i][2])) {
                ans.push_back("Yes");
            } else {
                ans.push_back("No");
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}