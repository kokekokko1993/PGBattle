#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, h[100009], dp[100009];
    vector<int> route;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> h[i];
    }
    dp[1] = 0;
    dp[2] = abs(h[1] - h[2]);

    for (int i = 3; i <= N; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]),
                    dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    int current = N;
    while (true) {
        route.push_back(current);
        if (current == 1) {
            break;
        }

        if (dp[current] == dp[current - 1] + abs(h[current] - h[current - 1])) {
            current -= 1;
        } else {
            current -= 2;
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