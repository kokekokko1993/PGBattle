#include <bits/stdc++.h>
using namespace std;

int N, A[100009];
map<long long, long long> mp;

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }

    long long ans = 0;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        ans += ((*itr).second) * ((*itr).second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}