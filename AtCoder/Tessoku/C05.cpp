#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    int idx = N + 1023;
    string ans = "";
    for (int i = 0; i < 10; i++) {
        if (idx & (1 << i)) {
            ans += "7";
        } else {
            ans += "4";
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
    return 0;
}