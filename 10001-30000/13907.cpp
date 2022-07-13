#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ti3 = tuple<int, int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int dist[1003][1003];
vector<pair<int, int>> adj[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    int s, e; cin >> s >> e;
    for (int i = 0; i < m; i++) {
        int a, b, w; cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    priority_queue<ti3, vector<ti3>, greater<>> pq;
    for (int i = 0; i <= n; i++) fill(dist[i], dist[i] + n + 1, 1e9);
    pq.push({0, s, 0});
    dist[s][0] = 0;
    while (!pq.empty()) {
        auto [d, cur, x] = pq.top(); pq.pop();
        if (x >= n || d > dist[cur][x]) continue;
        for (auto [nxt, w] : adj[cur]) {
            if (dist[nxt][x + 1] > d + w) {
                dist[nxt][x + 1] = d + w;
                pq.push({d + w, nxt, x + 1});
            }
        }
    }
    vector<pair<int, int>> v;
    int ret = 1e9;
    for (int i = 1; i <= n; i++) {
        if (dist[e][i] != 1e9) v.push_back({dist[e][i], i}), ret = min(ret, dist[e][i]);
    }
    cout << ret << "\n";
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        int ret = 1e9;
        for (auto &[a, b] : v) a += b * x, ret = min(a, ret);
        cout << ret << "\n";
    }
}