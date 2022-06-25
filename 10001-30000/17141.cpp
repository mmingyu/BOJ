#include <bits/stdc++.h>
using namespace std;
#define r first
#define c second

int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dist[55][55], arr[55][55], n, m;
queue<pair<int, int>> q;
vector<pair<int, int>> v;
int ret, ans = 1e8;
bool check[55];

void bfs() {
	while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
		ret = max(ret, dist[r][c]);
		// printf("%d %d\n", r, c);
		for (int i = 0; i < 4; i++) {
			int nr = r + dir[i][0];
			int nc = c + dir[i][1];
			if (nr >= n || nr < 0 || nc >= n || nc < 0) continue;
			if (dist[nr][nc] != -1 || arr[nr][nc] == 1) continue;
			dist[nr][nc] = dist[r][c] + 1;
			q.push({ nr, nc });
		}
	}
}

void solve(int cur, int cnt) {
	if (cnt == m) {
		memset(dist, -1, sizeof(dist));
		for (int i = 0; i < v.size(); i++) {
			if (check[i]) {
				q.push({v[i].r, v[i].c});
				dist[v[i].r][v[i].c] = 0;
			}
		}
		ret = 0;
		bfs();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] != 1 && dist[i][j] == -1) ret = 1e8;
			}
		}
		ans = min(ans, ret);
		return;
	}
	if (cur == v.size()) return;
	if (cnt < m) {
		check[cur] = true;
		solve(cur + 1, cnt + 1);
		check[cur] = false;
		solve(cur + 1, cnt);
	}
}


int main() {
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) v.push_back({i, j});
		}
	}
	solve(0, 0);
	cout << (ans == 1e8 ? -1 : ans);
}
