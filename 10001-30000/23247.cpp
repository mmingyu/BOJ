#include <bits/stdc++.h>
using namespace std;

int psum[303][303], ans;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        int x; cin >> x;
        psum[i][j] = x + psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1]; 
    }
    
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) {
        for (int r = i; r <= n; r++) for (int c = j; c <= m; c++) {
            int x = psum[r][c] - psum[r][j-1] - psum[i-1][c] + psum[i-1][j-1];
            if (x == 10) ans++;
            if (x > 10) break;
        }
    }
    cout << ans;
}