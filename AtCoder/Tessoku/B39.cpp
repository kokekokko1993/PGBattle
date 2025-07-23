#include <bits/stdc++.h>
using namespace std;

int N, D, X[200009], Y[200009];
vector<int> xs[2009];
priority_queue<int> pq;

int main() {
    cin >> N >> D;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        xs[X[i]].push_back(Y[i]);
    }

    int ans = 0;
    for (int i = 1; i <= D; i++) {
        for (int j = 0; j < xs[i].size(); j++) {
            pq.push(xs[i][j]);
        }

        if (!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
    return 0;
}