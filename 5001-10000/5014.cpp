#include <bits/stdc++.h>
using namespace std;

int dist[1000006];

int main() {
    int f, s, g, u, d; cin >> f >> s >> g >> u >> d;
    queue<int> q;
    q.push(s);
    dist[s] = 1;
    while (!q.empty()) {
        int cur = q.front(); q.pop();
        if (cur == g) {
            cout << dist[cur] - 1;
            return 0;
        }
        if (cur + u <= f && !dist[cur + u]) {
            q.push(cur + u);
            dist[cur + u] = dist[cur] + 1;
        }
        if (cur - d > 0 && !dist[cur - d]) {
            q.push(cur - d);
            dist[cur - d] = dist[cur] + 1;
        }
    }
    cout << "use the stairs";
}