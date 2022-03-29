#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;

vector<int> adj[N];
int lev[N];
int dp[20][N];

void dfs(int cur, int prv) {
    lev[cur] = lev[prv] + 1;
    dp[0][cur] = prv;
    for (auto nxt : adj[cur]) {
        if (nxt != prv) dfs(nxt, cur);
    }
}

int lca(int x, int y) {
    if (lev[x] < lev[y]) swap(x, y);
    int diff = lev[x] - lev[y];
    for (int i = 0; i < 20; i++) {
        if (diff & (1 << i)) x = dp[i][x];
    }
    if (x == y) return x;
    for (int i = 19; i >= 0; i--) {
        if (dp[i][x] != dp[i][y]) x = dp[i][x], y = dp[i][y];
    }
    return dp[0][x];
}

int query(int r, int u, int v) {
    int ru = lca(r, u);
    int rv = lca(r, v);
    int uv = lca(u, v);
    int ans = ru;
    if (lev[ans] < lev[rv]) ans = rv;
    if (lev[ans] < lev[uv]) ans = uv;
    return ans;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 0);
    for (int i = 1; i < 20; i++) {
        for (int j = 1; j <= n; j++) {
            dp[i][j] = dp[i - 1][dp[i - 1][j]];
        }
    }
    int m; cin >> m;
    while (m--) {
        int r, u, v; cin >> r >> u >> v;
        cout << query(r, u, v) << '\n';
    }
}
