#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v[100005];
bool visited[100005];
int s, e;
bool flag;

void dfs(int cur, int c) {
    if (cur == e) {
        flag = true;
        return;
    }
    if (visited[cur]) return;
    visited[cur] = true;
    for (auto [nxt, cost] : v[cur]) {
        if (cost >= c) dfs(nxt, c);
    }
}

bool is_possible(int k) {
    memset(visited, 0, sizeof(visited));
    flag = false;
    dfs(s, k);
    return flag;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> s >> e;
    int l = 0, r = 1e9 + 9;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (is_possible(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << l;
}