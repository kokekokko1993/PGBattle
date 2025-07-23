#include <bits/stdc++.h>
using namespace std;

long long N, M, B;
long long A[200009], C[200009];

int main() {
    cin >> N >> M >> B;
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    for (int i = 1; i <= M; i++)
        cin >> C[i];

    long long sumA = 0, sumC = 0;
    for (int i = 1; i <= N; i++)
        sumA += A[i];
    for (int i = 1; i <= M; i++)
        sumC += C[i];

    long long ans = sumA * M + B * N * M + sumC * N;
    cout << ans << endl;
    return 0;
}