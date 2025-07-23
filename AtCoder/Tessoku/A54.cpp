#include <bits/stdc++.h>
using namespace std;

int Q;
map<string, int> mp;

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            string x;
            int y;
            cin >> x >> y;
            mp[x] = y;
        } else {
            string x;
            cin >> x;
            cout << mp[x] << endl;
        }
    }
    return 0;
}