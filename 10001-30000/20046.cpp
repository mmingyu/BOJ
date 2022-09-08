#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using t = tuple<int, int, int>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int arr[1003][1003];
int dist[1003][1003];
int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
priority_queue<t, vector<t>, greater<>> pq;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            dist[i][j] = 1e9;
        }
    }
    if (arr[0][0] == -1 || arr[n-1][m-1] == -1) {
        cout << -1;
        return 0;
    }
    pq.push({arr[0][0], 0, 0});    
    dist[0][0] = arr[0][0];
    while (!pq.empty()) {
        auto [d, r, c] = pq.top(); pq.pop();
        if (dist[r][c] < d) continue;
        for (int i = 0; i < 4; i++) {
            int nr = r + dir[i][0], nc = c + dir[i][1];
            if (nr < 0 || nc < 0 || nr >= n || nc >= m || arr[nr][nc] == -1) continue;
            if (d + arr[nr][nc] < dist[nr][nc]) {
                dist[nr][nc] = d + arr[nr][nc];
                pq.push({d + arr[nr][nc], nr, nc});
            }
        }
    }
    if (int d = dist[n-1][m-1]; d == 1e9) cout << -1;
    else cout << d;
}