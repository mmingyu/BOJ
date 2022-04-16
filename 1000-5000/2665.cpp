#include <bits/stdc++.h>
using namespace std;

int visited[55][55];
string arr[55];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (auto &c : arr[i]) c -= '0';
    }
    for (int i = 0; i < 55; i++) for (int j = 0; j < 55; j++) visited[i][j] = 1e8;

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 0;

    while (!q.empty()) {
        auto [r, c] = q.front(); 
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr >= n || nc >= n || nr < 0 || nc < 0) continue;
            if (arr[nr][nc] && visited[nr][nc] > visited[r][c]) {
                visited[nr][nc] = visited[r][c];
                q.push({nr, nc});
            }
            if (!arr[nr][nc] && visited[nr][nc] > visited[r][c] + 1) {
                visited[nr][nc] = visited[r][c] + 1;
                q.push({nr, nc}); 
            }
        }
    }
    cout << visited[n - 1][n - 1];
}
