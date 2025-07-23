#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A[109];
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    sort(A + 1, A + N + 1);
    reverse(A + 1, A + N + 1);
    cout << A[1] + A[2] << endl;
    return 0;
}