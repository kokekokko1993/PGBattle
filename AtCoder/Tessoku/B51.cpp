#include <bits/stdc++.h>
using namespace std;

string S;
stack<int> st;
vector<pair<int, int>> ans;

int main() {
    cin >> S;

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            st.push(i);
        } else {
            ans.push_back({st.top() + 1, i + 1});
            st.pop();
        }
    }
    // sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
}