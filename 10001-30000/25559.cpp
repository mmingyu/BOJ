#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    if (n == 1) { cout << 1; return 0; }
    if (n & 1) { cout << -1; return 0; }

    int cur = 1;
    for (int i = n; i >= 1; i--) {
        int nxt = cur;
        if (i & 1) nxt = nxt + i;
        else nxt = (n + nxt - i) % n;
        if (nxt > n) nxt = (nxt + 1) % n;
        cout << ((nxt - cur + n) % n ? (nxt - cur + n) % n : n) << " ";
        cur = nxt;
    }
}