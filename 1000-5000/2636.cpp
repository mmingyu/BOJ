#include <bits/stdc++.h>
using namespace std;

int arr[102][102], cnt;
int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
bool visited[102][102];
int n, m; 

bool is_rmv(int r, int c) {
    int ret = 0;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (visited[nr][nc]) ret++;
    }
    return ret >= 2;
}

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m || arr[nr][nc]) continue;
        dfs(nr, nc);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        cin >> arr[i][j], cnt += arr[i][j];
    }
    int ans = 0;
    while (cnt) {
        memset(visited, 0, sizeof(visited));
        dfs(0, 0);
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            if (arr[i][j] && is_rmv(i, j)) arr[i][j] = 0, cnt--;
        }
        ans++;
    }
    cout << ans;
}