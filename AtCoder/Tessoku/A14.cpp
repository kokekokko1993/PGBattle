#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    int V[5][1009];
    cin >> N >> K;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> V[i][j];
        }
    }

    vector<int> AB, CD;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            AB.push_back(V[0][i] + V[1][j]);
            CD.push_back(V[2][i] + V[3][j]);
        }
    }
    sort(CD.begin(), CD.end());
    CD.push_back(2e9);

    bool ans = false;
    for (auto itr = AB.begin(); itr != AB.end(); itr++) {
        int idx = lower_bound(CD.begin(), CD.end(), K - *itr) - CD.begin();
        // cout << *itr << " " << CD[idx] << endl;
        if (*itr + CD[idx] == K) {
            ans = true;
        }
    }

    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}