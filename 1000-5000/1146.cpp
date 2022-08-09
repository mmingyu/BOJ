#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 102;
constexpr int MOD = 1e6;
int dp[N][N][N][2], n;

int dpf(int cur, int l, int r, int big) {
    int &ret = dp[cur][l][r][big];
    if (cur == n) return 1;
    if (~ret) return ret;
    ret = 0;
    if (big && r > 0) {
        for (int i = 0; i < r; i++)
            ret += dpf(cur + 1, l + i, r - i - 1, 0), ret %= MOD;
    } 
    if (!big && l > 0) {
        for (int i = 0; i < l; i++)
            ret += dpf(cur + 1, l - i - 1, r + i, 1), ret %= MOD;
    }
    return ret;
}

int main() {
    scanf("%d", &n);
    if (n == 1) return !printf("1");
    int ans = 0;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        ans += dpf(1, i, n - i - 1, 1); ans %= MOD;
        ans += dpf(1, i, n - i - 1, 0); ans %= MOD;
    }
    printf("%d", ans);
}