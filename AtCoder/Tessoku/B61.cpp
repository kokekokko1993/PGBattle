#include <bits/stdc++.h>
using namespace std;

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

    int idx = 1;
    int val = g[1].size();
    for (int i = 2; i <= N; i++) {
        if (g[i].size() > val) {
            idx = i;
            val = g[i].size();
        }
    }

    cout << idx << endl;
    return 0;
}