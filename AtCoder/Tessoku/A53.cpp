#include <bits/stdc++.h>
using namespace std;

int Q;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            pq.push(x);
        } else if (t == 2) {
            cout << pq.top() << endl;
        } else {
            pq.pop();
        }
    }
    return 0;
}