#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<ll, pii>;

constexpr int N = 1e5 + 5;
constexpr ll INF = 1e15;
int n, m, k; 
vector<pii> v[N];
ll dist[22][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    fill(&dist[0][0], &dist[22][0], INF);
    dist[0][1] = 0;
    priority_queue<piii, vector<piii>, greater<>> pq;
    pq.push({0, {1, 0}});
    while (!pq.empty()) {
        auto [d, p] = pq.top();
        auto [cur, rmv] = p;
        pq.pop();
        if (dist[rmv][cur] < d) continue;
        for (auto [nxt, nd] : v[cur]) {
            ll newd = d + nd;
            if (dist[rmv][nxt] > newd) {
                dist[rmv][nxt] = newd;
                pq.push({newd, {nxt, rmv}});
            }
            if (rmv + 1 <= k && dist[rmv + 1][nxt] > d) {
                dist[rmv + 1][nxt] = d;
                pq.push({d, {nxt, rmv + 1}});
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i <= k; i++) ans = min(ans, dist[i][n]);
    
    // for (int i = 0; i <= k; i++) {
    //     for (int j = 1; j <= n; j++) cout << dist[i][j] << ' ';
    //     cout << endl;
    // }

    cout << ans;
}