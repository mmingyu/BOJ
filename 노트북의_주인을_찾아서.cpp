#include <bits/stdc++.h>
using namespace std;

vector<int> v[102];
bool vis[102];
int b[102];

bool dfs(int cur) {
    vis[cur] = true;
    for (auto nxt : v[cur]) {
        if (b[nxt] == -1 || (!vis[b[nxt]] && dfs(b[nxt]))) {
            b[nxt] = cur;
            return true;
        }
    }
    return false;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);        
    }
    memset(b, -1, sizeof(b));
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) ans++;
    }
    cout << ans;
}