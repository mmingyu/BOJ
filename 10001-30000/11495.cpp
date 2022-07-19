#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

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

constexpr int N = 2555;
constexpr int src = N-1, sink = N-2;
constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int arr[55][55];

void solve() {
    NetworkFlow flow(N);
    int n, m; cin >> n >> m;
    int ans = 0;
    for (int r = 0, cur = 0; r < n; r++) for (int c = 0; c < m; c++, cur++) {
        cin >> arr[r][c]; ans += arr[r][c];
        if (r + c & 1) {
            flow.add_edge(cur, sink, arr[r][c]);
            continue;
        }
        flow.add_edge(src, cur, arr[r][c]);
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1], nxt = nr * m + nc;
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            flow.add_edge(cur, nxt, 1e9);
        }
    }
    cout << ans - flow.network_flow(src, sink) << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        solve();
    }
}