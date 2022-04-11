#include <bits/stdc++.h>
using namespace std;

bool arr[2][102][102];
long long dp[102][102];

// 0 왼쪽 1 위
int dir[2][2] = {{-1, 0}, {0, -1}};

void check_dir(int a, int b, int c, int d) {
    for (int i = 0; i < 2; i++) {
        if (a + dir[i][0] == c && b + dir[i][1] == d) {
            arr[i][a][b] = true;
            return;
        }
    }
    swap(a, c);
    swap(b, d);
    for (int i = 0; i < 2; i++) {
        if (a + dir[i][0] == c && b + dir[i][1] == d) {
            arr[i][a][b] = true;
            return;
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    int k; cin >> k;
    while (k--) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        check_dir(a, b, c, d);        
    }
    for (int i = 0; i <= n; i++) {
        if (arr[0][i][0]) break;
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++) {
        if (arr[1][0][i]) break;
        dp[0][i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j] * !arr[0][i][j] + dp[i][j - 1] * !arr[1][i][j];
        }
    }
    cout << dp[n][m];
}