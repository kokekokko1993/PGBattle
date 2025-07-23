#include <bits/stdc++.h>
using namespace std;

void dfs(int p, vector<vector<int>> &g, vector<bool> &visited) {
    visited[p] = true;

    for (int i = 0; i < g[p].size(); i++) {
        if (!visited[g[p][i]]) {
            dfs(g[p][i], g, visited);
        }
    }
}

int N, M;
int A[100009], B[100009];

int main() {
    cin >> N >> M;
    vector<vector<int>> g(N + 1, vector<int>());
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    vector<bool> visited(N + 1, false);

    dfs(1, g, visited);
    bool ans = true;
    for (int i = 1; i <= N; i++) {
        ans &= visited[i];
    }

    if (ans) {
        cout << "The graph is connected." << endl;
    } else {
        cout << "The graph is not connected." << endl;
    }
    return 0;
}