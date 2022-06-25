#include <bits/stdc++.h>
using namespace std;
constexpr int N = 505;

struct Edge { 
    int cap, flow, to, rev; 
    int spare() { return cap - flow; }
    void add_flow(int f);
};

vector<Edge> adj[N];

void Edge::add_flow(int f) {
    flow += f;
    adj[to][rev].flow -= f;
}

int par[N];
Edge *epar[N];

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

void add_edge(int u, int v, int c) {
    adj[u].push_back({c, 0, v, (int)adj[v].size()});
    adj[v].push_back({c, 0, u, (int)adj[u].size() - 1});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v, c; cin >> u >> v >> c;
        add_edge(u, v, c);
    }
    int src, sink; cin >> src >> sink;
    cout << network_flow(src, sink);
}
