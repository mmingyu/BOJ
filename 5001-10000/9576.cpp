#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1002;
vector<int> adj[N];
bool visited[N];
int b_match[N];

bool dfs(int a) {
    if (visited[a]) return false;
    visited[a] = true;
    for (auto b : adj[a]) {
        if (b_match[b] == -1 || dfs(b_match[b])) {
            b_match[b] = a;
            return true;
        }
    }
    return false;
}

void init() {
    for (int i = 0; i < N; i++) adj[i].clear();
    memset(b_match, -1, sizeof(b_match));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        init();
        int n, m; cin >> n >> m;
        for (int i = 1; i <= m; i++) {
            int l, r; cin >> l >> r;
            for (int j = l; j <= r; j++) {
                adj[i].push_back(j);
            }           
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            memset(visited, 0, sizeof(visited));
            if (dfs(i)) ans++;
        }
        cout << ans << "\n";
    }
}