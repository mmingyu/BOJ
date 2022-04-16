#include <bits/stdc++.h>
using namespace std;

int dp[202][202][22];
int arr[202];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            dp[i][i][j] = (arr[i] != j);
        }
    }
    for (int d = 1; d <= n - 1; d++) {
        for (int l = 1; l <= n; l++) {
            int r = l + d;
            if (r > n) continue;
            for (int i = 1; i <= k; i++) {
                dp[l][r][i] = min(
                    dp[l][r - 1][i] + !(arr[r] == i || arr[r] == arr[r - 1]), 
                    dp[l + 1][r][i] + !(arr[l] == i || arr[l] == arr[l + 1]));
                for (int mid = l; mid <= r - 1; mid++) 
                    dp[l][r][i] = min(dp[l][r][i], dp[l][mid][i] + dp[mid + 1][r][i]);
            }
            int mn = *min_element(&dp[l][r][1], &dp[l][r][k + 1]);
            for (int i = 1; i <= k; i++) dp[l][r][i] = min(dp[l][r][i], mn + 1);
        }
    }
    int ans = 1e9;
    for (int i = 1; i <= k; i++) ans = min(ans, dp[1][n][i]);
    cout << ans;
}