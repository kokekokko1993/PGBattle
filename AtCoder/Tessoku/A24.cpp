#include <bits/stdc++.h>
using namespace std;

int N, A[100009];
int dp[100009], L[100009];
// dp[i]: 最後の要素がA[i]である部分列のうち、最長のものの長さ
// L[i]:
// 長さiの部分列の最後の要素として考えられる最小値。i.e.dp[k]=iを満たすようなkにおけるA[k]の最小値
// -> dp[i] = (L[pos] < A[i]を見たるposの最大値 + 1)

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i <= N; i++) {
        L[i] = 1e9;
    }

    dp[1] = 1;
    L[1] = A[1];

    for (int i = 2; i <= N; i++) {
        int idx = lower_bound(L + 1, L + N + 1, A[i]) - L;
        // L[idx] = min(L[idx], A[i]);
        L[idx] = A[i];
        dp[i] = idx;
    }

    int ans = 1;
    for (int i = 1; i <= N; i++) {
        if (L[i] < 1e9) {
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}