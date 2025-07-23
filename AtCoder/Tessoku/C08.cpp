#include <bits/stdc++.h>
using namespace std;

int N;
string S[109];
int T[109];

int main() {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> S[i] >> T[i];
    }

    vector<string> kouho;
    for (int i = 0; i < 10000; i++) {
        string tmp = to_string(i);
        tmp.insert(0, 4 - tmp.length(), '0');
        // cout << tmp << endl;
        bool res = true;
        for (int j = 1; j <= N; j++) {
            int count = 0;
            for (int k = 0; k < 4; k++) {
                count += tmp[k] == S[j][k];
            }
            if (T[j] == 1) {
                res &= (count == 4);
            } else if (T[j] == 2) {
                res &= (count == 3);
            } else {
                res &= (count <= 2);
            }
        }
        if (res) {
            kouho.push_back(tmp);
        }
    }

    if (kouho.size() > 1) {
        cout << "Can't Solve" << endl;
    } else {
        cout << kouho[0] << endl;
    }
    return 0;
}