#include <bits/stdc++.h>
using namespace std;

int X, Y;
vector<pair<int, int>> ans;

int main() {
    cin >> X >> Y;
    while (X > 1 || Y > 1) {
        ans.push_back({X, Y});
        if (X > Y) {
            X -= Y;
        } else {
            Y -= X;
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}