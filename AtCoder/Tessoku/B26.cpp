#include <bits/stdc++.h>
using namespace std;

int N;

vector<long long> eratosthenes(long long N) {
    vector<bool> isPrime(N + 1, true);
    isPrime[1] = false;
    for (int i = 2; i * i <= N; i++) {
        for (int j = 2; i * j <= N; j++) {
            isPrime[i * j] = false;
        }
    }
    vector<long long> result;
    for (int i = 2; i <= N; i++) {
        if (isPrime[i]) {
            result.push_back(i);
        }
    }
    return result;
}

int main() {
    cin >> N;
    vector<long long> ans = eratosthenes(N);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}