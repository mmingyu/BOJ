#include <bits/stdc++.h>
using namespace std;

vector<int> v[52];
int dist[52];
int po[52];

int main() {
    int n; scanf("%d", &n);
    while (true) {
        int a, b; scanf("%d %d", &a, &b);
        if (a == -1 && b == -1) break;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        memset(dist, 0, sizeof(dist));
        queue<int> q;
        q.push(i);
        dist[i] = 1;
        int mx = -1;
        while (!q.empty()) {
            int cur = q.front(); q.pop();
            mx = max(mx, dist[cur]);
            for (auto nxt : v[cur]) {
                if (!dist[nxt]) {
                    dist[nxt] = dist[cur] + 1;
                    q.push(nxt);
                }
            }
        }
        po[i] = mx - 1;
    }

    int mn = *min_element(po + 1, po + n + 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (po[i] == mn) ans.push_back(i);
    }
    printf("%d %d\n", mn, ans.size());
    for (auto x : ans) printf("%d ", x);
}