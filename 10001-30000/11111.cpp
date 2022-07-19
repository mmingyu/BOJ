#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

class MCMF {
private:
    struct Edge { 
        int cap, flow, to, rev, d; 
        int spare() { return cap - flow; }
    };
    const int N;
    vector<int> par, dist, inq;
    vector<vector<int>> d;
    vector<Edge*> epar;
    vector<vector<Edge>> adj;
public:
    MCMF(int N) : N(N) {
        inq.resize(N);
        dist.resize(N);
        par.resize(N);
        epar.resize(N);
        adj.resize(N);
    }

    bool spfa(int src, int sink) {
        fill(dist.begin(), dist.end(), 1e8);
        fill(par.begin(), par.end(), -1);
        queue<int> q;
        q.push(src);
        inq[src] = true;
        dist[src] = 0;

        while (!q.empty()) {
            int cur = q.front(); q.pop();
            inq[cur] = false;
            for (auto &e : adj[cur]) {
                int nxt = e.to;
                if (e.spare() > 0 && dist[nxt] > dist[cur] + e.d) {
                    dist[nxt] = dist[cur] + e.d;
                    par[nxt] = cur;
                    epar[nxt] = &e;
                    if (!inq[nxt]) q.push(nxt), inq[nxt] = true;
                }
            }
        }
        return par[sink] != -1;
    }

    pair<int, int> mcmf(int src, int sink) {
        int max_flow = 0, min_cost = 0;
        while (spfa(src, sink)) {
            int mn = 1e8;
            for (int i = sink; i != src; i = par[i]) {
                mn = min(mn, epar[i]->spare());
            }
            for (int i = sink; i != src; i = par[i]) {
                Edge *e = epar[i];
                e->flow += mn;
                adj[e->to][e->rev].flow -= mn;
                min_cost += mn * e->d;
            }
            max_flow += mn;
        }
        return {max_flow, min_cost};
    }

    void add_edge(int u, int v, int c, int d) {
        adj[u].push_back({c, 0, v, (int)adj[v].size(), d});
        adj[v].push_back({0, 0, u, (int)adj[u].size() - 1, -d});
    }
};

constexpr int N = 2555;
constexpr int src = N-1, sink = N-2;
constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
constexpr int cost[5][5] = {
    {10, 8, 7, 5, 1},
    {8, 6, 4, 3, 1},
    {7, 4, 3, 2, 1},
    {5, 3, 2, 2, 1},
    {1, 1, 1, 1, 0}
};

int arr[55][55];
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    MCMF mcmf(N);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char c; cin >> c;
        if (c == 'F') c--;
        arr[i][j] = c - 'A';
    }
    for (int r = 0; r < n; r++) for (int c = 0; c < m; c++) {
        int cur = r * m + c;
        mcmf.add_edge(cur, sink, 1, 0);
        if (r + c & 1) continue;
        mcmf.add_edge(src, cur, 1, 0);
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            mcmf.add_edge(cur, nr * m + nc, 1, -cost[arr[r][c]][arr[nr][nc]]);
        }
    }
    cout << -mcmf.mcmf(src, sink).second;
}