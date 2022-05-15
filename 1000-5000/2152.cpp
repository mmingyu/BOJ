#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e4 + 4;
vector<int> v[N], rev[N], g[N];
int scc[N], sz[N], scc_sz, indeg[N];
stack<int> st;
bool vis[N];
int dp[N];
int n, m, s, t; 

void dfs(int cur, const vector<int> *v, bool rev) {
    vis[cur] = true;
    if (rev) scc[cur] = scc_sz, sz[scc_sz]++;
    for (const auto &nxt : v[cur]) {
        if (!vis[nxt]) dfs(nxt, v, rev);
    }
    if (!rev) st.push(cur);
}


void get_scc() {
    for (int i = 1; i <= n; i++) if (!vis[i]) dfs(i, v, false);
    
    memset(vis, 0, sizeof(vis));
    while (!st.empty()) {
        int cur = st.top(); 
        st.pop();
        if (vis[cur]) continue;
        dfs(cur, rev, true); 
        scc_sz++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m >> s >> t;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        rev[b].push_back(a);
    }
    
    get_scc();

    for (int i = 1; i <= n; i++) {
        for (const auto &cur : v[i]) {
            if (scc[i] != scc[cur]) {
                g[scc[i]].push_back(scc[cur]);
                indeg[scc[cur]]++;
            }
        }
    }

    queue<int> q;
    s = scc[s], t = scc[t];
    memset(dp, -1, sizeof(dp));
    dp[s] = sz[s];
    for (int i = 0; i < scc_sz; i++) if (!indeg[i]) q.push(i);
    
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == t) break;
        for (auto nxt : g[cur]) {
            if (--indeg[nxt] == 0) q.push(nxt);
            if (dp[cur] != -1) dp[nxt] = max(dp[nxt], dp[cur] + sz[nxt]);
        }
    }
    cout << (dp[t] > 0 ? dp[t] : 0);
}

