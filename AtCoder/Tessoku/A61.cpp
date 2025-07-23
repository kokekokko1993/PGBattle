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

    for (int i = 1; i <= N; i++) {
        sort(g[i].begin(), g[i].end());
        cout << i << ": {";
        for (int j = 0; j < g[i].size(); j++) {
            if (j > 0) {
                cout << ", ";
            }
            cout << g[i][j];
        }
        cout << "}" << endl;
    }
    return 0;
}