#include <bits/stdc++.h>
using namespace std;

// 不正解数を考える！！
int N, M;
int A[200009];

int main() {
    cin >> N >> M;
    for (int i = 1; i <= M; i++) {
        cin >> A[i];
    }
    vector<int> fails(N + 1, 0);
    for (int i = 1; i <= M; i++) {
        fails[A[i]]++;
    }

    for (int i = 1; i <= N; i++) {
        cout << M - fails[i] << endl;
    }
    return 0;
}