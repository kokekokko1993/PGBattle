#include <bits/stdc++.h>
using namespace std;

int N, H, W, A[100009], B[100009];

int main() {
    cin >> N >> H >> W;
    for (int i = 1; i <= N; i++) {
        cin >> A[i] >> B[i];
    }

    int XOR_sum = (A[1] - 1) ^ (B[1] - 1);
    for (int i = 2; i <= N; i++) {
        XOR_sum ^= (A[i] - 1) ^ (B[i] - 1);
    }

    if (XOR_sum) {
        cout << "First" << endl;
    } else {
        cout << "Second" << endl;
    }
    return 0;
}