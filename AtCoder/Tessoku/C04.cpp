#include <bits/stdc++.h>
using namespace std;

vector<long long> get_divs(long long n) {
    vector<long long> ans;
    for (long long i = 1; i * i <= n; i++) {
        if (i * i == n) {
            ans.push_back(i);
        } else if (n % i == 0) {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}

int main() {
    long long N;
    cin >> N;
    vector<long long> ans = get_divs(N);

    for (long long e : ans) {
        cout << e << endl;
    }
    return 0;
}