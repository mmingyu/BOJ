#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

vector<int> v;
int dp[303][303][2], dist[303][303];
int n, m, ans;
bool zero;

int dpf(int l, int r, int isl, int last) {
    if (!last || (l == 0 && r == n)) return 0;
    int &ret = dp[l][r][isl];
    if (~ret) return ret;
    int cur = isl ? l : r;
    ret = 0;
    if (l > 0) ret = max(ret, dpf(l - 1, r, 1, last - 1) + m - last * dist[cur][l - 1]);
    if (r < n) ret = max(ret, dpf(l, r + 1, 0, last - 1) + m - last * dist[cur][r + 1]);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    v.resize(n);    
    
    for (int &x : v) cin >> x, zero += (x == 0);
    if (!zero) v.push_back(0);
    else n--;

    sort(all(v));

    for (int i = 0; i < sz(v); i++)
        for (int j = i + 1; j < sz(v); j++)
            dist[i][j] = dist[j][i] = v[j] - v[i];

    int idx = lower_bound(all(v), 0) - v.begin();
    for (int i = 0; i < sz(v); i++) {
        memset(dp, -1, sizeof(dp));
        int x = dpf(idx, idx, 0, i);
        if (zero) x += m;
        ans = max(ans, x);
    }
    cout << ans;
}