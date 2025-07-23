#include <bits/stdc++.h>
using namespace std;

int N, M;
int A[100009], B[100009];
vector<int> g[100009];
int route[100009];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> B[i];
        g[A[i]].push_back(B[i]);
        g[B[i]].push_back(A[i]);
    }
    for (int i = 1; i <= N; i++) {
        route[i] = -1;
    }

    // bfs
    route[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        for (int i = 0; i < g[current].size(); i++) {
            int next = g[current][i];
            if (route[next] < 0) {
                route[next] = route[current] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << route[i] << endl;
    }
    return 0;
}