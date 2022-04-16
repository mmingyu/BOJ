#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int arr[302][22], dp[22][302];
pii par[22][302];

int main() {
    int n, m; scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        int k; scanf("%d", &k);
        for (int j = 1; j <= m; j++) {
            scanf("%d", &arr[k][j]);
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= j; k++) {
                if (dp[i][j] < dp[i - 1][j - k] + arr[k][i]) {
                    dp[i][j] = dp[i - 1][j - k] + arr[k][i];
                    par[i][j] = {i - 1, j - k};
                }
            }
        }
    }

    vector<int> ans;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        auto [ni, nj] = par[i][j];
        ans.push_back(j - nj);
        i = ni;
        j = nj;
    }
    printf("%d\n", dp[m][n]);
    for (int i = m - 1; i >= 0; i--) printf("%d ", ans[i]);
}