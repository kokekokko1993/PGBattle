#include <bits/stdc++.h>
using namespace std;

long long N, A[100009], B[100009];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    // 総和をどうするか？(方針を固定して全探索する)
    long long ans = 0;
    long long omote, ura;
    // 表：正、裏：正
    omote = ura = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] + B[i] > 0) {
            omote += A[i];
            ura += B[i];
        }
    }
    ans = max(ans, abs(omote) + abs(ura));
    // cout << omote << " " << ura << " " << ans << endl;

    // 表：正、裏：負
    omote = ura = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] - B[i] > 0) {
            omote += A[i];
            ura += B[i];
        }
    }
    ans = max(ans, abs(omote) + abs(ura));
    // cout << omote << " " << ura << " " << ans << endl;

    // 表：負、裏：正
    omote = ura = 0;
    for (int i = 1; i <= N; i++) {
        if (-A[i] + B[i] > 0) {
            omote += A[i];
            ura += B[i];
        }
    }
    ans = max(ans, abs(omote) + abs(ura));
    // cout << omote << " " << ura << " " << ans << endl;

    // 表：負、裏：負
    omote = ura = 0;
    for (int i = 1; i <= N; i++) {
        if (-A[i] - B[i] > 0) {
            omote += A[i];
            ura += B[i];
        }
    }
    ans = max(ans, abs(omote) + abs(ura));
    // cout << omote << " " << ura << " " << ans << endl;

    cout << ans << endl;
    return 0;
}