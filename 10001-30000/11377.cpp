#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, cap, flow;
    Edge *rev;
    int spare() { return cap - flow; }
    void add_flow(int f) {
        this->flow += f;
        rev->flow -= f;
    }
};

constexpr int N = 2020;
vector<Edge *> adj[N];
int par[N];
Edge *path[N]; 
Edge edgelist[2 * N * N];
int edge_cnt;

Edge *new_edge(int v, int c) {
    edgelist[edge_cnt] = {v, c, 0, nullptr};
    return &edgelist[edge_cnt++];
}

void add_edge(int u, int v, int c) {
    Edge *uv = new_edge(v, c);
    Edge *vu = new_edge(u, 0);
    uv->rev = vu;
    vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

int network_flow(int src, int sink) {
    int ret = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(src);
        while (!q.empty() && par[sink] == -1) {
            int cur = q.front(); q.pop();
            for (auto &e : adj[cur]) {
                int nxt = e->to;
                if (e->spare() > 0 && par[nxt] == -1) {
                    q.push(nxt);
                    par[nxt] = cur;
                    path[nxt] = e;
                    if (nxt == sink) break;
                }
            }
        }
        if (par[sink] == -1) break;
        int mn = 1e9;
        for (int i = sink; i != src; i = par[i]) {
            mn = min(mn, path[i]->spare());
        }
        for (int i = sink; i != src; i = par[i]) {
            path[i]->add_flow(mn);
        }
        ret += mn;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int src = 0, sink = N - 1, mid = N - 2, more = N - 3;
    int n, m, k; cin >> n >> m >> k;
    add_edge(src, mid, n);
    add_edge(src, more, k);
    for (int i = 1; i <= n; i++) {
        add_edge(mid, i, 1);
        add_edge(more, i, 1);
        int x; cin >> x;
        while (x--) {
            int c; cin >> c;
            add_edge(i, c + 1000, 2);
        }
    }
    for (int i = 1; i <= m; i++) {
        add_edge(i + 1000, sink, 1);
    }
    cout << network_flow(src, sink);
}