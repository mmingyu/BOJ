#include <bits/stdc++.h>
using namespace std;

int arr[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[102][102];
int h, n;

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = true;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr >= n || nc >= n || nr < 0 || nc < 0 || arr[nr][nc] <= h) continue;
        dfs(nr, nc);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    
    int ans = 0;
    for (h = 0; h <= 100; h++) {
        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            if (!visited[i][j] && arr[i][j] > h) dfs(i, j), cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}