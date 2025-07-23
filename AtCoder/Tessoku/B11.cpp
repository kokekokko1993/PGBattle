#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Q;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    cin >> Q;
    vector<int> X(Q);
    for (int i = 0; i < Q; i++) {
        cin >> X[i];
    }

    sort(A.begin(), A.end());
    for (int i = 0; i < Q; i++) {
        int res = lower_bound(A.begin(), A.end(), X[i]) - A.begin();
        cout << res << endl;
    }
    return 0;
}