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

constexpr int N = 1002;
vector<Edge *> adj[N];
int par[N];
Edge *path[N];
int mx;

void add_edge(int u, int v, int c) {
    Edge *uv = new Edge({v, c, 0, nullptr});
    Edge *vu = new Edge({u, 0, 0, nullptr});
    uv->rev = vu;
    vu->rev = uv;
    adj[u].push_back(uv);
    adj[v].push_back(vu);
}

void init() {
    for (int i = 0; i < N; i++) adj[i].clear();
    mx = 0;
}

int network_flow(int src, int sink) {
    int ret = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        priority_queue<pair<int, int>> q;
        q.push({1e8, src});
        while (!q.empty() && par[sink] == -1) {
            auto [d, cur] = q.top(); q.pop();
            for (auto &e : adj[cur]) {
                int nxt = e->to;
                if (e->spare() > 0 && par[nxt] == -1) {
                    q.push({min(d, e->cap), nxt});
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
        mx = max(mn, mx);
        ret += mn;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        init();
        int n, e, a, b; cin >> n >> e >> a >> b;
        for (int i = 0; i < e; i++) {
            int u, v, w; cin >> u >> v >> w;
            add_edge(u, v, w);
        }
        int maxflow = network_flow(a, b);
        printf("%.3f\n", 1.0 * maxflow / mx);
    }
}
