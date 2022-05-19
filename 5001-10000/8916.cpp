#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int((x).size())

constexpr int MOD = 9'999'991;
int arr[22], n;
ll dp[22][22];

ll com(int n, int r) {
    if (n < r || r < 0) return 0;
    if (n == r || r == 0) return dp[n][r] = 1;
    if (dp[n][r]) return dp[n][r];
    return dp[n][r] = com(n - 1, r - 1) + com(n - 1, r);
}

ll solve(int s, int e) {
    if (s + 1 >= e) return 1;
    vector<int> hi, lo;
    for (int i = s + 1; i < e; i++) {
        if (arr[i] > arr[s]) hi.push_back(arr[i]);
        else lo.push_back(arr[i]);
    }
    for (int i = 0; i < sz(hi); i++) arr[i + s + 1] = hi[i];
    for (int i = 0; i < sz(lo); i++) arr[i + s + 1 + sz(hi)] = lo[i];
    ll l = solve(s + 1, s + 1 + sz(hi));
    ll r = solve(s + 1 + sz(hi), e);
    ll cnt = com(sz(hi) + sz(lo), sz(hi));
    return (((l * r) % MOD) * cnt) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        cout << solve(0, n) << "\n";
    }
}