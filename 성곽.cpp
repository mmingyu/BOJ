#include <bits/stdc++.h>
using namespace std;

// 서       북      동      남
// (0, -1) (-1, 0) (0, 1) (1, 0)

bool arr[4][55][55];
int dir[4][2] = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
int visited[55][55];
int sz[55];
int cnt, n, m, _1, _2, _3;

void dfs(int r, int c) {
    if (visited[r][c]) return;
    visited[r][c] = _1;
    cnt++;
    for (int i = 0; i < 4; i++) {
        if (arr[i][r][c]) continue;
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (nr >= n || nr < 0 || nc >= m || nc < 0) continue;
        dfs(nr, nc);
    }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int inp; cin >> inp;
            for (int k = 0; k < 4; k++) {
                arr[k][i][j] = !!(inp & (1 << k));
            }
        }
    }
    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        if (!visited[i][j]) {
            cnt = 0;
            ++_1;
            dfs(i, j);
            sz[_1] = cnt;
            _2 = max(_2, cnt); 
        }
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) for (int k = 0; k < 4; k++) {
        int ni = i + dir[k][0], nj = j + dir[k][1];
        if (ni >= n || ni < 0 || nj >= m || nj < 0) continue;
        int r1 = visited[i][j], r2 = visited[ni][nj];
        if (visited[i][j] != visited[ni][nj]) _3 = max(_3, sz[r1] + sz[r2]);
    }

    cout << _1 << "\n" << _2 << "\n" << _3;
}