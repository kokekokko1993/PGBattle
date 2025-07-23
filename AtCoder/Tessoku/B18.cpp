#include <bits/stdc++.h>
using namespace std;

int N, S, A[69];
bool dp[69][10009];

int main() {
    cin >> N >> S;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= S; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = true;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= S; j++) {
            if (j - A[i] >= 0) {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - A[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    if (!dp[N][S]) {
        cout << -1 << endl;
        return 0;
    }

    vector<int> route;
    int current = S;
    for (int i = N; i >= 1; i--) {
        if (dp[i - 1][current]) {
            continue;
        } else {
            route.push_back(i);
            current -= A[i];
        }
    }
    reverse(route.begin(), route.end());
    cout << route.size() << endl;
    for (int i = 0; i < route.size(); i++) {
        cout << route[i] << " ";
    }
    cout << endl;
    return 0;
}