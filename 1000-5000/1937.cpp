#include <bits/stdc++.h>
using namespace std;

int arr[502][502];
int dp[502][502];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n;

int dpf(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= n) return 0;
    int &ret = dp[r][c];
    if (~ret) return ret;
    ret = 1;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (arr[nr][nc] > arr[r][c]) ret = max(ret, dpf(nr, nc) + 1);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) ans = max(ans, dpf(i, j));
    cout << ans;
}