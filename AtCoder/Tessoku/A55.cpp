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
        } else if (t == 2) {
            st.erase(x);
        } else {
            auto itr = st.lower_bound(x);
            if (itr == st.end()) {
                cout << -1 << endl;
            } else {

                cout << *itr << endl;
            }
        }
    }
    return 0;
}