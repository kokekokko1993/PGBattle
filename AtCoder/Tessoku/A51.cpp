#include <bits/stdc++.h>
using namespace std;

int Q;
stack<string> st;

int main() {
    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        int q;
        string S;
        cin >> q;
        if (q == 1) {
            cin >> S;
            st.push(S);
        } else if (q == 2) {
            cout << st.top() << endl;
        } else {
            st.pop();
        }
    }
    return 0;
}