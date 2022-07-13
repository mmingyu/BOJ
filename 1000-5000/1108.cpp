#include <bits/stdc++.h>
using namespace std;

constexpr int N = 3003;
vector<int> adj[N];
vector<int> rev[N];
map<string, int> m;
long long dp[N];
int visited[N], scc_id[N], scc_cnt, v_cnt, cnt;
stack<int> st;

long long dpf(int cur) {
    if (dp[cur] != 1) return dp[cur];
    auto &ret = dp[cur];
    for (auto nxt : rev[cur]) {
        if (scc_id[cur] != scc_id[nxt]) {
            ret += dpf(nxt);
        }
    }
    return ret;
}

int dfs(int cur) {
    int ret = visited[cur] = scc_cnt++;
    st.push(cur);

    for (auto nxt : adj[cur]) {
        if (visited[nxt] == -1) ret = min(ret, dfs(nxt));
        else if (scc_id[nxt] == -1) ret = min(ret, visited[nxt]);   
    }

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

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (m.find(s) == m.end()) m[s] = cnt++;
        int v = m[s];
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> s;
            if (m.find(s) == m.end()) m[s] = cnt++;
            int u = m[s];
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
    }

    string f; cin >> f;
    memset(scc_id, -1, sizeof(scc_id));
    memset(visited, -1, sizeof(visited));
    for (int i = 0; i < cnt; i++) {
        if (visited[i] == -1) dfs(i);
    }
    fill(dp, dp + N, 1);
    cout << dpf(m[f]);
}