#include <bits/stdc++.h>
using namespace std;

int N, M, K;
int A[100009], B[100009], S[100009], T[100009];
int cnt[100009]; // 今i駅にいて、これまでの搭乗回数の最大値
vector<pair<int, int>>
    prevs[100009]; // {到着時間, 到着時間までの搭乗回数の最大値}
tuple<int, int, int, int> tpl[100009];

int main() {
    cin >> N >> M >> K;
    for (int i = 1; i <= M; i++) {
        cin >> A[i] >> S[i] >> B[i] >> T[i];
        T[i] += K;
        tpl[i] = {T[i], S[i], A[i], B[i]};
    }
    sort(tpl + 1, tpl + M + 1);
    for (int i = 1; i <= N; i++) {
        cnt[i] = 0;
        prevs[i].push_back({0, 0});
    }

    for (int i = 1; i <= M; i++) {
        auto [t, s, a, b] = tpl[i];
        int idx = upper_bound(prevs[a].begin(), prevs[a].end(),
                              make_pair(s, (int)1e9))
                  - prevs[a].begin() - 1;
        cnt[b] = max(cnt[b], prevs[a][idx].second + 1);
        prevs[b].push_back({t, cnt[b]});
    }

    int ans = 0;
    for (int i = 1; i <= N; i++) {
        ans = max(ans, cnt[i]);
    }
    cout << ans << endl;
    return 0;
}