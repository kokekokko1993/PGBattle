#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    vector<int> A, E;
    set<int> s;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        A.push_back(tmp);
        if (s.find(tmp) == s.end()) {
            s.insert(tmp);
            E.push_back(tmp);
        }
    }
    sort(E.begin(), E.end());
    // setを使わなければ
    // E.erase(unique(E.begin(), E.end()), E.end());
    // でもよい。
    // また、
    // set<int> s(E.begin(), E.end());
    // vector<int> v(s.begin(), s.end());
    // でvector -> set -> vectorにしてもよい。

    for (int i = 0; i < A.size(); i++) {
        int idx = lower_bound(E.begin(), E.end(), A[i]) - E.begin();
        A[i] = idx + 1;
    }

    for (int i = 0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}