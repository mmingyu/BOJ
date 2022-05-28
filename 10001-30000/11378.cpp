#include <bits/stdc++.h>
using namespace std;

constexpr int N = 2010;

struct Edge {
    int to, cap, flow;
    Edge *rev;
    int spare() { return cap - flow; }
    void add_flow(int f) {
        this->flow += f;
        rev->flow -= f;
    }
};

Edge edge_list[2 * N * N]; int edge_cnt;
Edge *new_edge(int to, int cap) {
    edge_list[edge_cnt] = {to, cap, 0, nullptr};
    return &edge_list[edge_cnt++];
}

vector<Edge*> adj[N];
int par[N];
Edge *path[N];
int src = 0, sink = N - 1, mid = N - 2;

void add_edge(int u, int v, int cap) {
    Edge *uv = new_edge(v, cap);
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
        int min_amount = 1e9;
        for (int i = sink; i != src; i = par[i]) {
            min_amount = min(min_amount, path[i]->spare());
        }
        for (int i = sink; i != src; i = par[i]) {
            path[i]->add_flow(min_amount);
        }
        ret += min_amount;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    
    for (int i = 1; i <= n; i++) {
        add_edge(mid, i, k);
        add_edge(src, i, 1);
        int t; cin >> t;
        while (t--) {
            int x; cin >> x;
            add_edge(i, x + 1000, 1);
        }
    }
    
    add_edge(src, mid, k);
    for (int i = 1; i <= m; i++) {
        add_edge(1000 + i, sink, 1);
    }
    cout << network_flow(src, sink);
}