#include <bits/stdc++.h>
using namespace std;

int mp[55][55];
int dir[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    int r = 0, c = 0, d = 0, cur = 1;
    int mv = 1, mv_cnt = 0, mv_mx = 1, mx = 0;
    while (cur <= (10001 * 10001)) {
        if (r1 <= r && r <= r2 && c1 <= c && c <= c2) {
            mp[r - r1][c - c1] = cur;
            mx = max(mx, mp[r - r1][c - c1]);
        }
        if (!mv) {
            d = (d + 1) % 4;
            mv_cnt++;
            if (mv_cnt == 2) mv_mx++, mv_cnt = 0;
            mv = mv_mx;
        }
        r += dir[d][0], c += dir[d][1];
        cur++, mv--;
    }
        
    int lgmx = log10(mx);
    for (int i = 0; i <= r2 - r1; i++) {
        for (int j = 0; j <= c2 - c1; j++) {
            int lgmp = log10(mp[i][j]);
            for (int k = 0; k < lgmx - lgmp; k++) cout << " ";
            cout << mp[i][j] << " ";
        }
        cout << '\n';
    }
}
