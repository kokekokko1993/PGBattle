#include <bits/stdc++.h>
using namespace std;

// borderの値を2分探索する！
// -> borderに対して各党何議席とれるか？
// -> 合計K議席以上＝okとすればよいはず

int N, K;
int A[100009];
int count_[100009];

bool solve(double n) {
    int res = 0;
    for (int i = 1; i <= N; i++) {
        res += A[i] / n;
    }
    return res >= K;
}

// ok: 解が存在する値
// ng: 解が存在しない値
// [ok, ng) or (ng, ok]となる阪堺区間を考える
double binarySearch(double ok, double ng) {
    while (abs(ok - ng) > 1e-6) {
        double mid = (ok + ng) / 2;
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
    // priority_queue<pair<double, int>> pq;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
        // pq.push({A[i], i});
        // count_[i] = 0;
    }

    double ok = 1, ng = 1e9 + 1;
    double border = binarySearch(ok, ng);
    // cout << border << endl;
    for (int i = 1; i <= N; i++) {
        cout << (int)(A[i] / border) << " ";
    }
    cout << endl;

    // for (int i = 0; i < K; i++) {
    //     auto [val, idx] = pq.top();
    //     // cout << i << " " << val << " " << idx << endl;
    //     pq.pop();
    //     count_[idx]++;

    //     pq.push({A[idx] / (count_[idx] + 1), idx});
    // }

    // for (int i = 1; i <= N; i++) {
    //     cout << count_[i] << " ";
    // }
    // cout << endl;
    return 0;
}