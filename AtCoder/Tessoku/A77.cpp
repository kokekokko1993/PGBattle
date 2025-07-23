#include <bits/stdc++.h>
using namespace std;

int N, L, K, A[100009];

bool solve(int n) {
    int current = 0;
    int count = 1;
    for (int i = 1; i <= N; i++) {
        if (A[i] - current >= n && L - A[i] >= n) {
            current = A[i];
            count++;
        }
    }
    return count >= K + 1;
}

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
    cin >> N >> L >> K;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    int ok = 0, ng = 1e9 + 1;
    int ans = binarySearch(ok, ng);
    cout << ans << endl;
    return 0;
}