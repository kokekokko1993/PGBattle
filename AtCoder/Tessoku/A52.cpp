#include <bits/stdc++.h>
using namespace std;

int Q;
queue<string> q;

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            string S;
            cin >> S;
            q.push(S);
        } else if (t == 2) {
            cout << q.front() << endl;
        } else {
            q.pop();
        }
    }
    return 0;
}