#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int dir[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
vector<pair<int, int>> v, pick;
int mat[55][55]; 
bool vis[55][55];
int n, m, ans = 1e8; 

bool chk() {
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0 && !vis[i][j]) return false;
    }
    return true;
}

void solve(int i) {
    if (sz(pick) == m) {
        memset(vis, 0, sizeof(vis));
        queue<tuple<int, int, int>> q;
        for (auto [r, c] : pick) q.push({r, c, 0});
        int cnt = 0;
        while (!q.empty()) {
            auto [r, c, x] = q.front(); q.pop();
            if (vis[r][c]) continue;
            vis[r][c] = true;
            if (mat[r][c] == 0) cnt = max(x, cnt);
            for (int i = 0; i < 4; i++) {
                int nr = r + dir[i][0];
                int nc = c + dir[i][1];
                if (nr >= n || nr < 0 || nc >= n || nc < 0) continue;
                if (mat[nr][nc] == 1 || vis[nr][nc]) continue;
                q.push({nr, nc, x + 1});
            }
        }
        
        if (chk()) ans = min(cnt, ans);
        return;
    }
    if (i == sz(v)) return;
    pick.push_back(v[i]);
    solve(i + 1);
    pick.pop_back();
    solve(i + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> mat[i][j];
        if (mat[i][j] == 2) v.push_back({i, j});
    }
    solve(0);
    cout << (ans == 1e8 ? -1 : ans);
}