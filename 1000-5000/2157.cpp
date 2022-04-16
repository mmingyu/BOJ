#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<pair<int, int>> v[302];
int dp[302][302];

int dpf(int cur, int vis) {
    if (cur == n) {
        if (vis <= m) return 0;
        return -1e8;
    }
    int &ret = dp[cur][vis];
    if (ret) return ret;
    ret = -1e8;
    for (auto [nxt, cost] : v[cur]) {
        if (cur > nxt) continue;
        ret = max(ret, dpf(nxt, vis + 1) + cost);
    }
    // printf("%d %d %d\n", cur, vis, ret);
    return ret;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cout << dpf(1, 1);
}