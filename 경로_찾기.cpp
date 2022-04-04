#include <bits/stdc++.h>
using namespace std;

constexpr int MOD = 1e6 + 7;
int arr[55][55];
int dp[55][55][55];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, c; cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = i;
    }
    
    int s = 1;
    if (!arr[1][1]) dp[0][1][1] = 1;
    else dp[1][1][1] = 1, s = arr[1][1];
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        if (!arr[i][j]) dp[0][i][j] = (dp[0][i][j] + dp[0][i - 1][j] + dp[0][i][j - 1]) % MOD;
    }
    for (int k = s; k <= c; k++) {
        for (int l = 1; l <= k - s + 1; l++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (arr[i][j] == k) {
                        dp[l][i][j] = (dp[l][i][j] + dp[l - 1][i - 1][j] + dp[l - 1][i][j - 1]) % MOD;
                    } else if (!arr[i][j]) {
                        dp[l][i][j] = (dp[l][i - 1][j] + dp[l][i][j - 1]) % MOD;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= c; i++) cout << dp[i][n][m] << " ";
}