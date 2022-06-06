#include <bits/stdc++.h>
using namespace std;

constexpr int N = 222;
constexpr int src = 0, sink = N - 1;

int cap[N][N], flow[N][N], d[N][N];
int par[N], dist[N];
bool inq[N];
vector<int> adj[N];

void input() {
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> cap[i + 100][sink];
        adj[sink].push_back(i + 100);
        adj[i + 100].push_back(sink);
    }
    for (int i = 1; i <= m; i++) {
        cin >> cap[src][i];
        adj[src].push_back(i);
        adj[i].push_back(src);
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 101; j <= n + 100; j++) {
            cin >> cap[i][j];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 101; j <= n + 100; j++) {
            cin >> d[i][j];
            d[j][i] = -d[i][j];
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
}

inline int spare(int u, int v) { return cap[u][v] - flow[u][v]; }

void spfa() {
    fill(dist, dist + N, 1e8);
    queue<int> q;
    q.push(src);
    inq[src] = true;
    dist[src] = 0;

    while (!q.empty()) {
        int cur = q.front(); q.pop();
        inq[cur] = false;
        for (auto nxt : adj[cur]) {
            if (spare(cur, nxt) > 0 && dist[nxt] > dist[cur] + d[cur][nxt]) {
                dist[nxt] = dist[cur] + d[cur][nxt];
                par[nxt] = cur;
                if (!inq[nxt]) q.push(nxt), inq[nxt] = true;
            }
        }
    }
}

pair<int, int> mcmf() {
    int max_flow = 0, min_dist = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        spfa();        
        if (par[sink] == -1) break;
        int mn = 1e8;
        for (int i = sink; i != src; i = par[i]) {
            mn = min(mn, spare(par[i], i));
        }
        for (int i = sink; i != src; i = par[i]) {
            min_dist += mn * d[par[i]][i];
            flow[par[i]][i] += mn;
            flow[i][par[i]] -= mn;
        }
        max_flow += mn;
    }
    return {max_flow, min_dist};
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    input();
    auto [max_flow, min_dist] = mcmf();
    cout << max_flow << "\n" << min_dist;
}