#include <bits/stdc++.h>
using namespace std;
using Point = pair<int, int>;
#define red first
#define blue second
#define r first
#define c second

string mat[12];
Point dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int dist[12][12][12][12];

int n, m;
Point operator*(const Point &a, const Point &b) { return {a.r * b.r, a.c * b.c}; }
Point operator-(const Point &a, const Point &b) { return {a.r - b.r, a.c - b.c}; }
Point operator+(const Point &a, const Point &b) { return {a.r + b.r, a.c + b.c}; }
Point goal;
bool goal_in;

Point get_position(Point cur, int d) {
    goal_in = false;
    while (true) {
        if (goal == cur) goal_in = true;
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
            if (mat[i][j] == 'R') in.red = {i, j};
            if (mat[i][j] == 'B') in.blue = {i, j};
            if (mat[i][j] == 'O') goal = {i, j};
        }
    }
    q.push(in);
    dist[in.red.r][in.red.c][in.blue.r][in.blue.c] = 0;

    while (!q.empty()) {
        auto [red, blue] = q.front(); q.pop();
        int &cur_d = dist[red.r][red.c][blue.r][blue.c];
        if (cur_d >= 10) break;
        for (int i = 0; i < 4; i++) {
            Point n_red = get_position(red, i);
            bool red_goal = goal_in;
            Point n_blue = get_position(blue, i);
            bool blue_goal = goal_in;
            
            if (n_red == n_blue) {
                Point d = dir[i];
                if (red * d > blue * d) n_blue = n_blue - d;
                else n_red = n_red - d;
            }

            int &nxt_d = dist[n_red.r][n_red.c][n_blue.r][n_blue.c];
            if (!blue_goal && red_goal) return cur_d + 1;
            if (blue_goal || nxt_d != -1) continue;
            nxt_d = cur_d + 1;

            if (red_goal) return nxt_d;
            q.push({n_red, n_blue});
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> mat[i];
    cout << bfs();
}
