#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
bool vis[N];
int dist = -1, cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    queue<pair<int, int>> q;
    q.push({n, 0});
    while (!q.empty()) {
        auto [x, d] = q.front(); q.pop();
        vis[x] = true;
        if (x == k && dist == -1) dist = d;
        if (x == k && dist == d) cnt++;
        if (x + 1 < N && !vis[x + 1]) q.emplace(x + 1, d + 1);
        if (x - 1 >= 0 && !vis[x - 1]) q.emplace(x - 1, d + 1);
        if (x * 2 < N && !vis[x * 2]) q.emplace(x * 2, d + 1);
    }
    cout << dist << "\n" << cnt;
}
