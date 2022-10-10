#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 102;
constexpr int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
bool vis[N+N][N][N];
string arr[N];
int ans = 2e9;
int n, m;

void dfs(int b, int r, int c) {
    vis[b][r][c] = true;
    if (r == n - 1 && c == m - 1) {
        ans = min(b, ans);
        return;
    }
    for (int i = 0; i < 4; i++) {
        int nr = r + dir[i][0];
        int nc = c + dir[i][1];
        if (nr >= n || nc >= m || nr < 0 || nc < 0) continue;
        if (int nb = b + arr[nr][nc]; nb < N+N && !vis[nb][nr][nc]) {
            dfs(nb, nr, nc);
        }
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        for (char &c : arr[i]) c -= '0';
    }
    dfs(0, 0, 0);
    cout << ans;   
}