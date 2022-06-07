#include <bits/stdc++.h>
using namespace std;

int k[102], s[102];
int dp[10004][102];

int dpf(int t, int n) {
    if (t < 0) return -1e8;
    if (n < 0) return 0;
    int &ret = dp[t][n];
    if (ret) return ret;
    return ret = max(dpf(t - k[n], n - 1) + s[n], dpf(t, n - 1));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, t; cin >> n >> t;
    for (int i = 0; i < n; i++) {
        cin >> k[i] >> s[i];
    }
    cout << dpf(t, n - 1);
}