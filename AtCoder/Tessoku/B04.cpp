#include <bits/stdc++.h>
using namespace std;

int main() {
    string N;
    cin >> N;
    int ans = 0;
    // int bKeta = 0;

    for (int i = 0; i < N.length(); i++) {
        ans += (N[N.length() - i - 1] == '1') * (1 << i);
    }
    cout << ans << endl;
    return 0;
}