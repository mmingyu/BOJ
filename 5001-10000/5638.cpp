#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> arr;
int v, t, n;
ll ans;

void solve(int i, ll sum, ll cost) {
    if (sum >= v) {
        ans = min(ans, cost);
        return;
    }
    if (i >= n) return;
    solve(i + 1, sum, cost);
    solve(i + 1, sum + arr[i].first * t, cost + arr[i].second);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    arr.resize(n);
    for (auto &[x, y] : arr) cin >> x >> y;
    int q; cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> v >> t;
        ans = 1e15;
        solve(0, 0, 0);
        if (ans == 1e15) printf("Case %d: IMPOSSIBLE\n", i);    
        else printf("Case %d: %d\n", i, ans);
    }
}