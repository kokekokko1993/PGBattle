#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> g[100009];
bool visited[100009];
vector<int> route;

bool dfs(int p) {
    visited[p] = true;
    if (p == N) {
        route.push_back(N);
        return true;
    }

    bool res = false;
    for (int i = 0; i < g[p].size(); i++) {
        int next = g[p][i];
        if (!visited[next]) {
            res |= dfs(next);
        }
        if (res) {
            route.push_back(p);
            return true;
        }
    }
    return false;
}

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
    }

    dfs(1);
    reverse(route.begin(), route.end());
    for (int i = 0; i < route.size(); i++) {
        cout << route[i] << " ";
    }
    cout << endl;
    return 0;
}