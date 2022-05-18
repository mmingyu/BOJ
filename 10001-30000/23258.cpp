#include <bits/stdc++.h>
using namespace std;

int dp[302][302][302];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) {
        int x; cin >> x;
        dp[0][i][j] = x ? x : 1e8;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k] + dp[k-1][k][j]);
            }
        }
    }
    while (q--) {
        int c, s, e; cin >> c >> s >> e;
        if (s == e) cout << 0 << "\n";
        else cout << (dp[c-1][s][e] == 1e8 ? -1 : dp[c-1][s][e]) << "\n";
    }
}