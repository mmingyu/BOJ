#include <bits/stdc++.h>
using namespace std;


int idx = 1, n;
void solve(int x) {
    if (x == 0) {
        if (idx <= n && n <= idx + 2) {
            cout << (n == idx ? "m" : "o");
            exit(0);
        }
        idx += 3;
        return;
    }
    solve(x - 1);
    for (int i = 0; i <= x + 2; i++) {
        if (idx == n) {
            cout << (i == 0 ? "m" : "o");
            exit(0);
        }
        idx++;
    }
    solve(x - 1);
}


int main() {
    cin >> n;
    solve(29);
}

