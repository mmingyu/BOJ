#include <bits/stdc++.h>
using namespace std;

const int N = 404;
int cap[2 * N][2 * N], flow[2 * N][2 * N], par[2 * N];
vector<int> adj[2 * N];

inline int spare(int u, int v) { return cap[u][v] - flow[u][v]; }
inline int out(int a) { return a + N; }

int network_flow(int src, int sink) {
    int ret = 0;
    while (true) {
        memset(par, -1, sizeof(par));
        queue<int> q;
        q.push(src);
        while (!q.empty() && par[sink] == -1) {
            int cur = q.front(); q.pop();
            for (auto nxt : adj[cur]) {
                if (spare(cur, nxt) > 0 && par[nxt] == -1) {
                    par[nxt] = cur;
                    q.push(nxt);
                    if (nxt == sink) break;
                }
            }
        }
        if (par[sink] == -1) break;
        int mn = 1e8;
        for (int i = sink; i != src; i = par[i]) {
            mn = min(mn, spare(par[i], i));
        }
        for (int i = sink; i != src; i = par[i]) {
            flow[par[i]][i] += mn;
            flow[i][par[i]] -= mn;
        }
        ret += mn;
        // cout << ret << endl;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, p; cin >> n >> p;
    for (int i = 1; i <= n; i++) {
        adj[i].push_back(out(i));
        adj[out(i)].push_back(i);
        cap[i][out(i)] = 1;
    }
    for (int i = 0; i < p; i++) {
        int a, b; cin >> a >> b;
        adj[out(a)].push_back(b);
        adj[b].push_back(out(a));
        cap[out(a)][b] = 1;

        adj[out(b)].push_back(a);
        adj[a].push_back(out(b));
        cap[out(b)][a] = 1;       
    }
    cout << network_flow(out(1), 2);
}