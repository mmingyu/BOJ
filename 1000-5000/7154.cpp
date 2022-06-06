#include <bits/stdc++.h>
using namespace std;

constexpr int N = 333;
constexpr int src = 0, sink = N - 1;
constexpr int score[3][4] = {
    {4, 3, 2, 1},
    {8, 7, 6, 5},
    {12, 11, 10, 9}
};

vector<int> adj[N];
int cap[N][N], flow[N][N], d[N][N], par[N]; 
int dist[N], inq[N];

void init() {
    for (int i = 0; i < N; i++) adj[i].clear();
    memset(cap, 0, sizeof(cap));
    memset(flow, 0, sizeof(flow));
    memset(d, 0, sizeof(d));
}

inline int spare(int u, int v) { return cap[u][v] - flow[u][v]; }

void spfa() {
    fill(dist, dist + N, 1e8);
    memset(par, -1, sizeof(par));
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

int mcmf() {
    int ret = 0;
    while (true) {
        spfa();        
        if (par[sink] == -1) break;
        int mn = 1e8;
        for (int i = sink; i != src; i = par[i]) {
            mn = min(mn, spare(par[i], i));
        }
        for (int i = sink; i != src; i = par[i]) {
            ret += mn * d[par[i]][i];
            flow[par[i]][i] += mn;
            flow[i][par[i]] -= mn;
        }
    }
    return -ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (true) {
        init();
        int n, m; cin >> n >> m;
        if (!n && !m) break;
        for (int i = 80; i < n + 80; i++) {
            cin >> cap[i][sink];
            adj[i].push_back(sink);
            adj[sink].push_back(i);
        }
        for (int i = 1; i <= m; i++) {
            adj[src].push_back(i);
            adj[i].push_back(src);
            cap[src][i] = 1;
            int y; cin >> y; y--;
            for (int j = 0; j < 4; j++) {
                int c; cin >> c; c += 80;
                adj[i].push_back(c);
                adj[c].push_back(i);
                cap[i][c] = 1;
                d[i][c] = -score[y][j];
                d[c][i] = score[y][j];
            }
        }
        cout << mcmf() << "\n";
    }
}