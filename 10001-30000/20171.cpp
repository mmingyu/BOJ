#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 1e5 + 5;
vector<int> v[N];
bool apt[N], vis[N]; 
int num[N], ans;

int dfs(int cur, int prv) {
    int &ret = num[cur];
    if (apt[cur]) ret++;
    for (auto nxt : v[cur]) {
        if (nxt != prv) ret += dfs(nxt, cur);
    }
    return ret;
}

void solve(int cur, int prv) {
    if (!num[cur]) return;
    int cnt = 0;
    for (auto nxt : v[cur]) {
        if (nxt == prv) continue;
        if (num[nxt]) cnt++;
        solve(nxt, cur);
    }
    if (cnt >= 2) ans++;
    else if (cnt == 1 && num[1] > num[cur]) ans++;
    else if (apt[cur]) ans++;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        apt[x] = true;
    }
    dfs(1, 0);
    solve(1, 0);
    cout << ans;
}