#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll, ll>> adj[55];
const ll INF = -1e15;
ll dp[55];
ll cost[55];
ll n, s, e, m;
bool vis[55];

void dfs(int cur) {
    vis[cur] = true;
    for (auto [nxt, d] : adj[cur]) if (!vis[nxt]) dfs(nxt);
}

bool bellman() {
    fill(dp, dp + 55, INF);
	dp[s] = cost[s];
	bool flag = false;
	for (int i = 0; i < 2*n; i++) {
		for (int cur = 0; cur < n; cur++) {
			if (dp[cur] == INF) continue;
			for (auto [nxt, d] : adj[cur]) {
				if (dp[nxt] < dp[cur] + d) {
					dp[nxt] = dp[cur] + d;
					if (i == 2*n - 1) {
                        memset(vis, 0, sizeof(vis));
                        dfs(nxt);
                        if (vis[e]) return false;
                    }
				}
			}
		}
	}
    return true;
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> s >> e >> m;
	for (int i = 0; i < m; i++) {
		ll u, v, c; cin >> u >> v >> c;
		adj[u].push_back({v, -c});
	}
	for (int i = 0; i < n; i++) {
		cin >> cost[i];
	}

	for (int cur = 0; cur < n; cur++) {
		for (auto &[nxt, c] : adj[cur]) {
			c += cost[nxt];
		}
	}

	if (!bellman()) cout << "Gee";
	else if (dp[e] == INF) cout << "gg";
	else cout << dp[e];
}

