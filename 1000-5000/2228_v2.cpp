#include <bits/stdc++.h>
using namespace std;

const int N = 102;
int dp[N][N];
int psum[N];

int dpf(int n, int m) {
    if (m == 0) return 0;
    if (n <= 0) return -1e8;
    int &ret = dp[n][m];
    if (~ret) return ret;
    ret = dpf(n - 1, m);
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dpf(i - 2, m - 1) + psum[n] - psum[i - 1]);
    }
    return ret;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int inp; scanf("%d", &inp);
        psum[i] = psum[i - 1] + inp;
    }
    memset(dp, -1, sizeof(dp));
    printf("%d", dpf(n, m));
}