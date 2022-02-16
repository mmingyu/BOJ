#include <bits/stdc++.h>
using namespace std;
#define sz(x) int((x).size())
int arr[102][102];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool visited[102][102];
int n, ans = 1e9; 
vector<pair<int, int>> side;

void dfs(int r, int c, int id) {
    if (visited[r][c]) return;
    visited[r][c] = true;
    arr[r][c] = id;
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0], nc = c + dir[i][1];
        if (arr[nr][nc]) dfs(nr, nc, id);
        else if (nr > 0 && nr <= n && nc > 0 && nc <= n) side.push_back({r, c});
    }
}


int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    int id = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (!visited[i][j] && arr[i][j]) dfs(i, j, ++id);
        }
    }

    for (int i = 0; i < sz(side); i++) {
        for (int j = i + 1; j < sz(side); j++) {
            auto [a, b] = side[i];
            auto [c, d] = side[j];
            if (arr[a][b] == arr[c][d]) continue;
            int dist = abs(c - a) + abs(d - b) - 1;
            ans = min(ans, dist);
        }
    }
    
    printf("%d", ans);
}