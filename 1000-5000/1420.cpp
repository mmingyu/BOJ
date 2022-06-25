#include <bits/stdc++.h>
using namespace std;
constexpr int N = 102 * 102;
constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
inline int in(int v) { return v; }
inline int out(int v) { return v + N; }

struct Edge { 
    int cap, flow, to, rev; 
    int spare() { return cap - flow; }
    void add_flow(int f);
};

vector<Edge> adj[2*N];

void Edge::add_flow(int f) {
    flow += f;
    adj[to][rev].flow -= f;
}

char arr[102][102];
int par[2*N];
Edge *epar[2*N];

int network_flow(int src, int sink) {
    int ret = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(src);
        while (!q.empty() && par[sink] == -1) {
            int cur = q.front(); q.pop();
            for (auto &e : adj[cur]) {
                int nxt = e.to;
                if (e.spare() > 0 && par[nxt] == -1) {
                    par[nxt] = cur, epar[nxt] = &e;
                    q.push(nxt);
                    if (nxt == sink) break;
                }
            }
        }
        if (par[sink] == -1) break;
        int mn = 1e8;
        for (int i = sink; i != src; i = par[i]) mn = min(mn, epar[i]->spare());
        for (int i = sink; i != src; i = par[i]) epar[i]->add_flow(mn);
        ret += mn;
    }
    return ret;
}

void add_edge(int u, int v) {
    adj[u].push_back({1, 0, v, (int)adj[v].size()});
    adj[v].push_back({0, 0, u, (int)adj[u].size() - 1});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int src, sink, u = 0, flag = false;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++, u++) {
        add_edge(in(u), out(u));
        if (arr[i][j] == 'K') src = u;
        if (arr[i][j] == 'H') sink = u;
        if (arr[i][j] != '#') {
            for (int k = 0; k < 4; k++) {
                int ni = i + dir[k][0], nj = j + dir[k][1];
                if (ni < 0 || ni >= n || nj < 0 || nj >= m || arr[ni][nj] == '#') continue;
                if (arr[i][j] == 'K' && arr[ni][nj] == 'H') flag = true;
                add_edge(out(u), in(ni * m + nj));
            }
        }
    }
    cout << (flag ? -1 : network_flow(out(src), in(sink)));
}
