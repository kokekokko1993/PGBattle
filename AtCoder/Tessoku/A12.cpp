/*
答えで二分探索：
「答えがx以上か？」に答えられ、単調増加or単調減少関数f(x)に対し、
f(x)=Nとなるxを求める問題とかで使える！！！
*/

#include <bits/stdc++.h>
using namespace std;

long long N, K, A[100009];

bool solve(long long n) {
    long long res = 0;
    for (int i = 0; i < N; i++) {
        res += n / A[i];
    }
    return res >= K;
}

long long binarySearch(long long ok, long long ng) {
    while (abs(ok - ng) > 1) {
        long long mid = (ok + ng) / 2;
        if (solve(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    return ok;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    long long ans = binarySearch(1e9 + 1, 0);
    cout << ans << endl;
    return 0;
}