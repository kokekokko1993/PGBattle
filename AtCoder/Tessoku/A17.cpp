#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A[100009], B[100009], dp[100009];
    cin >> N;
    for (int i = 2; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 3; i <= N; i++) {
        cin >> B[i];
    }

    dp[1] = 0;
    dp[2] = A[2];
    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }

    vector<int> route;
    int current = N;

    route.push_back(current);
    while (current > 1) {
        if (dp[current] - dp[current - 1] == A[current]) {
            current -= 1;
            route.push_back(current);
        } else if (dp[current] - dp[current - 2] == B[current]) {
            current -= 2;
            route.push_back(current);
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