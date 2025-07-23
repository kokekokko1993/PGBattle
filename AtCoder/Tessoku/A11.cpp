#include <bits/stdc++.h>
using namespace std;

int N, X;
vector<int> A;

bool solve(int n) { return A[n] <= X; }

// ok: 解が存在する値
// ng: 解が存在しない値
// [ok, ng) or (ng, ok]となる阪堺区間を考える
int binarySearch(int ok, int ng) {
    while (abs(ok - ng) > 1) {
        int mid = (ok + ng) / 2;
        if (solve(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cin >> N >> X;
    A.push_back(0);
    for (int i = 1; i <= N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
    }
    int ans = binarySearch(0, N + 1);
    cout << ans << endl;

    // lower_bound
    // int pos = lower_bound(A.begin(), A.end(), X) - A.begin();
    // cout << pos << endl;
    return 0;
}