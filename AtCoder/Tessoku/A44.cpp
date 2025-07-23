#include <bits/stdc++.h>
using namespace std;

int N, Q;
int A[200009];

int main() {
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        A[i] = i;
    }

    bool rev = false;
    for (int i = 1; i <= Q; i++) {
        int idx;
        cin >> idx;
        if (idx == 1) {
            int s, v;
            cin >> s >> v;
            int t = rev ? N - s + 1 : s;
            A[t] = v;
        } else if (idx == 2) {
            rev = 1 - rev;
        } else {
            int t;
            cin >> t;
            int ans = rev ? A[N - t + 1] : A[t];
            cout << ans << endl;
        }
    }
    return 0;
}