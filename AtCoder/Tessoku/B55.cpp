#include <bits/stdc++.h>
using namespace std;

int Q;
set<int> st;

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 1) {
            st.insert(x);
        } else {
            if (st.empty()) {
                cout << -1 << endl;
                continue;
            }
            auto itr = st.lower_bound(x);
            int ans;
            if (itr == st.begin()) {
                ans = *itr - x;
            } else if (itr == st.end()) {
                itr--;
                ans = x - *itr;
            } else {
                int tmp = *itr - x;
                itr--;
                ans = min(tmp, x - *itr);
            }
            cout << ans << endl;
        }
    }
    return 0;
}