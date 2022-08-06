#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

ll arr[102], n, s;
ll dp[102][102][2];

ll dpf(int l, int r, int isl) {
    ll &ret = dp[l][r][isl];
    if (l == 1 && r == n) return 0;
    if (ret) return ret;
    ret = 1e18;
    if (r + 1 <= n) {
        ll x = (isl ? arr[r + 1] - arr[l] : arr[r + 1] - arr[r]) * (n - (r - l + 1));
        ret = min(ret, dpf(l, r + 1, 0) + x);
    }
    if (l - 1 > 0) {
        ll x = (isl ? arr[l] - arr[l - 1]: arr[r] - arr[l - 1]) * (n - (r - l + 1));
        ret = min(ret, dpf(l - 1, r, 1) + x);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        cin >> n >> s;
        for (int i = 2; i <= n; i++) cin >> arr[i], arr[i] += arr[i - 1];
        memset(dp, 0, sizeof(dp));
        cout << min(dpf(s, s, 0), dpf(s, s, 1)) << "\n";
    }
}