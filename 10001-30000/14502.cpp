#include <bits/stdc++.h>
using namespace std;

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int mat[11][11], vis[11][11];
int n, m, ans;

void dfs(int r, int c) {
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (mat[nr][nc] == 1 || vis[nr][nc]) continue;
        vis[nr][nc] = 1;
        dfs(nr, nc);
    }
}

void solve(int x, int cnt) {
    if (cnt == 3) {
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1) vis[i][j] = 1;
            if (mat[i][j] == 2) vis[i][j] = 1, dfs(i, j);
        }
        int x = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            x += !vis[i][j];
        }
        ans = max(ans, x);
        return;
    }
    if (x == n * m) return;
    if (mat[x / m][x % m] == 0) {
        mat[x / m][x % m] = 1;
        solve(x + 1, cnt + 1);
        mat[x / m][x % m] = 0;
    }
    solve(x + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> mat[i][j];
    }
    solve(0, 0);
    cout << ans;
}