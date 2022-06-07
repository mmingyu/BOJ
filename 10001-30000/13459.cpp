#include <bits/stdc++.h>
using namespace std;
#define r first
#define c second

using Point = pair<int, int>;
Point operator*(const Point &a, const Point &b) { return {a.r * b.r, a.c * b.c}; }
Point operator-(const Point &a, const Point &b) { return {a.r - b.r, a.c - b.c}; }
Point operator+(const Point &a, const Point &b) { return {a.r + b.r, a.c + b.c}; }

string mat[12];
Point dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
Point goal;
int dist[12][12][12][12], n, m;
bool goal_in;


Point get_position(Point cur, int d) {
    while (goal != cur) {
        Point nxt = cur + dir[d];
        if (mat[nxt.r][nxt.c] == '#') break;
        cur = nxt;
    }
    return cur;
}

int bfs() {
    memset(dist, -1, sizeof(dist));
    queue<pair<Point, Point>> q;
    pair<Point, Point> in;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 'R') in.first = {i, j};
            if (mat[i][j] == 'B') in.second = {i, j};
            if (mat[i][j] == 'O') goal = {i, j};
        }
    }
    q.push(in);
    dist[in.first.r][in.first.c][in.second.r][in.second.c] = 0;
    while (!q.empty()) {
        auto [red, blue] = q.front(); q.pop();
        const int &cur_d = dist[red.r][red.c][blue.r][blue.c];
        if (cur_d >= 10) break;

        for (int i = 0; i < 4; i++) {
            Point n_red = get_position(red, i);
            Point n_blue = get_position(blue, i);
            

            if (n_blue == goal) continue;
            if (n_red == goal) return 1;   
            
            if (n_red == n_blue) {
                Point d = dir[i];
                if (red * d > blue * d) n_blue = n_blue - d;
                else n_red = n_red - d;
            }

            int &nxt_d = dist[n_red.r][n_red.c][n_blue.r][n_blue.c];
            if (nxt_d != -1) continue;
            nxt_d = cur_d + 1;
            q.push({n_red, n_blue});
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
    cout << bfs();
}
