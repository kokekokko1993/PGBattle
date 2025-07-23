#include <bits/stdc++.h>
using namespace std;

int N, X[100009], Y[100009];
int P[1509][1509], S[1509][1509];
int Q, a[100009], b[100009], c[100009], d[100009];

int main() {
    for (int i = 0; i <= 1500; i++) {
        for (int j = 0; j <= 1500; j++) {
            P[i][j] = S[i][j] = 0;
        }
    }

    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> X[i] >> Y[i];
        P[X[i]][Y[i]] += 1;
    }

    // cumsum
    for (int i = 1; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) {
            S[i][j] = S[i - 1][j] + P[i][j];
        }
    }
    for (int i = 1; i <= 1500; i++) {
        for (int j = 1; j <= 1500; j++) {
            S[i][j] = S[i][j - 1] + S[i][j];
        }
    }

    cin >> Q;
    for (int i = 1; i <= Q; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];

        int res = S[c[i]][d[i]] - S[c[i]][b[i] - 1] - S[a[i] - 1][d[i]] +
                  S[a[i] - 1][b[i] - 1];
        cout << res << endl;
    }
    return 0;
}