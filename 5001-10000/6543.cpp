#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5005;
vector<int> adj[N];
stack<int> st;
int visited[N];
int scc_cnt, v_cnt;
int scc_id[N];
int outd[N];

int dfs(int cur) {
    int ret = visited[cur] = v_cnt++;
    st.push(cur);
    for (auto nxt : adj[cur]) {
        if (visited[nxt] == -1) ret = min(ret, dfs(nxt));
        else if (scc_id[nxt] == -1) ret = min(ret, visited[nxt]); // (cur, nxt)가 무시해야하는 교차간선 아님
    }
    // cur에서 부모로 올라가는거 끊음
    if (ret == visited[cur]) {
        while (true) {
            int t = st.top(); st.pop();
            scc_id[t] = scc_cnt;
            if (t == cur) break;
        }
        scc_cnt++;
    }
    return ret;
}

void init() {
    for (int i = 0; i < N; i++) adj[i].clear();
    memset(scc_id, -1, sizeof(scc_id));
    memset(visited, -1, sizeof(visited));
    memset(outd, 0, sizeof(outd));
    scc_cnt = v_cnt = 0;
}

void tarjan(int n) {
    for (int i = 1; i <= n; i++) {
        if (visited[i] == -1) dfs(i);
    }
}

int main() {
    while (true) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        init();
        int n, m; 
        cin >> n;
        if (n == 0) break;
        cin >> m;
        for (int i = 0; i < m; i++) {
            int u, v; cin >> u >> v;
            adj[u].push_back(v);
        }
        tarjan(n);
        for (int u = 1; u <= n; u++) {
            for (auto v : adj[u]) if (scc_id[u] != scc_id[v]) outd[scc_id[u]]++;
        }
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (!outd[scc_id[i]]) cout << i << " ", flag = true;
        }
        if (flag) cout << "\n";
    }
}