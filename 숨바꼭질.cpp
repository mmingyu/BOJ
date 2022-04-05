#include <bits/stdc++.h>
using namespace std;

vector<int> v[20004];
int dist[20004];
bool visited[20004];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue<int> q;
    q.push(1);
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        for (auto nxt : v[cur]) {
            if (!dist[nxt]) {
                dist[nxt] = dist[cur] + 1;
                q.push(nxt);
            }
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (dist[i] > dist[ans]) ans = i, cnt = 0;
        if (dist[i] == dist[ans]) cnt++;
    }
    cout << ans << " " << dist[ans] << " " << cnt;
}