#include <bits/stdc++.h>
using namespace std;

struct Point { int x, y, car; };
int mat[55][55];
int dist[102][102];
int pnum[55][55];
int vis[102][55][55];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int car, p;
int par[202], match;
vector<int> adj[202];
bool visited[202];
int total;

bool dfs(int a){
    visited[a] = true;
    for (auto b: adj[a]) {
        if (par[b] == -1 || !visited[par[b]] && dfs(par[b])) {
            par[b] = a;
            return true;
        }
    }
    return false;
}

bool check(int k) {
    for (int i = 0; i < 202; i++) adj[i].clear();
    
    for (int i = 1; i <= car; i++) {
        for (int j = 1; j <= p; j++) {
            if (dist[i][j] && dist[i][j] <= k) adj[i].push_back(j + 100);
        }
    }
    memset(par, -1, sizeof(par));
    match = 0;
    for (int i = 1; i <= car; i++) {        
        memset(visited, 0, sizeof(visited));
        if (dfs(i)) match++;
    }
    // cout << match << endl;
    if (match == car) return true;
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int R, C; cin >> R >> C;
    queue<Point> q;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            char c; cin >> c;
            if (c == 'C') q.push({i, j, ++car});
            if (c == 'P') mat[i][j] = 1, pnum[i][j] = ++p;
            if (c == 'X') mat[i][j] = -1;
        }
    }

    while (!q.empty()) {
        auto [r, c, car] = q.front(); q.pop();
        if (mat[r][c] == 1) dist[car][pnum[r][c]] = vis[car][r][c];
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0];
            int nc = c + dir[i][1];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (vis[car][nr][nc] || mat[nr][nc] == -1) continue;
            q.push({nr, nc, car}); 
            vis[car][nr][nc] = vis[car][r][c] + 1;
        }
    }
    
    if (car > p || car == 0) {
        cout << (car > p ? -1 : 0);
        return 0;
    }
    
    int l = -1, r = 250004;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        // cout << "mid = " << mid << " ";
        if (check(mid)) r = mid;
        else l = mid;
    }
    cout << (r == 250004 ? -1 : r);
}
