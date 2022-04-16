#include <bits/stdc++.h>
using namespace std;

int arr[100005][4];
int dp[100005][4];
int dir[4][2] = {{-1, -1}, {-1, 1}, {-1, 0}, {0, -1}};

int main() {
    for (int tc = 1; ; tc++) {
        int n; cin >> n;
        if (n == 0) break;
        for (int i = 0; i < n; i++) for (int j = 0; j < 3; j++) cin >> arr[i][j];
        fill(dp[0], dp[100005], 1e9);
        dp[0][1] = arr[0][1];    
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 4; k++) {
                    int nr = i + dir[k][0];
                    int nc = j + dir[k][1];
                    if (nr >= n || nr < 0 || nc >= 3 || nc < 0) continue;
                    dp[i][j] = min(dp[i][j], dp[nr][nc] + arr[i][j]);
                }
            }
        }
        cout << tc << ". " << dp[n - 1][1] << "\n";
    }
}