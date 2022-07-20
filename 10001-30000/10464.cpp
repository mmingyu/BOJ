#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int cal(int x) {
    int ret = 0;
    for (int i = x / 4 * 4; i <= x; i++) ret ^= i;
    return ret;
}

void solve() {
    int n, m; cin >> n >> m;
    cout << (cal(n - 1) ^ cal(m)) << "\n";    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}