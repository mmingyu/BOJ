#include <bits/stdc++.h>
using namespace std;

int dp[102][102];
int psum[102];

int dpf(int n, int m) {
    if (!m) return 0;
    if (n <= 0) return -1e9;
    int &ret = dp[n][m];
    if (ret != -1e8) return ret;
    ret = dpf(n - 1, m);
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dpf(i - 2, m - 1) + psum[n] - psum[i - 1]);
    }
    return ret;
}



int main() {
    fill(dp[0], dp[102], -1e8);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        psum[i] = psum[i - 1] + inp;
    }
    cout << dpf(n, m);
}