#include <bits/stdc++.h>
using namespace std;

class NetworkFlow {
private:
    struct Edge { 
        int cap, flow, to, rev; 
        int spare() { return cap - flow; }
    };
    const int N;
    vector<int> par;
    vector<Edge*> epar;
    vector<vector<Edge>> adj;
public:
    NetworkFlow(int N) : N(N) {
        par.resize(N);
        epar.resize(N);
        adj.resize(N);
    }
    int network_flow(int src, int sink) {
        int ret = 0;
        while (true) {
            fill(par.begin(), par.end(), -1);
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
            for (int i = sink; i != src; i = par[i]) {
                Edge *e = epar[i];
                e->flow += mn;
                adj[e->to][e->rev].flow -= mn;
            }
            ret += mn;
        }
        return ret;
    }

    void add_edge(int u, int v, int c) {
        adj[u].push_back({c, 0, v, (int)adj[v].size()});
        adj[v].push_back({0, 0, u, (int)adj[u].size() - 1});
    }
};

constexpr int N = 222;
constexpr int src = 0, sink = 3*N - 1;
NetworkFlow net(3*N);

inline int in(int x) { return x; }
inline int out(int x) { return x + 111; }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k, d; cin >> n >> k >> d;
    for (int i = 1; i <= d; i++) {
        int c; cin >> c;
        net.add_edge(in(i+N), out(i+N), c);
        net.add_edge(out(i+N), sink, c);
    }
    for (int i = 1; i <= n; i++) {
        int z; cin >> z;
        while (z--) {
            int v; cin >> v;
            net.add_edge(i, in(v+N), 1);
        }
        net.add_edge(src, i, k);
    }

    cout << net.network_flow(src, sink);
}