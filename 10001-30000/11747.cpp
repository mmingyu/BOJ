#include <bits/stdc++.h>
using namespace std;

const int N = 10004;
bool chk[N];

int main() {
    int n; cin >> n;
    string s;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        s += c;
    }

    for (int i = 1; i <= n && i <= 3; i++) {
        for (int j = 0; j + i <= n; j++) {
            int x = stoi(s.substr(j, i));
            chk[x] = true;
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (!chk[i]) {
            cout << i;
            return 0;
        }
    }
}