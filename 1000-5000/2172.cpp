#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 22;
constexpr int dir[8][2] = {
    {1, 0}, {-1, 0}, {0, 1}, {0, -1},
    {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
int dp[N][N][N][N][N];
int arr[N][N];

inline bool chk(int ni, int nj, int n) {
    return ni >= n || ni < 0 || nj >= n || nj < 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, l; cin >> n >> l;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> arr[i][j];
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        dp[1][i][j][i][j] = 1;
        for (int d = 0; d < 8; d++) {
            int ni = i + dir[d][0], nj = j + dir[d][1];
            if (chk(ni, nj, n)) continue;
            if (arr[i][j] == arr[ni][nj]) dp[2][i][j][ni][nj] = 1;
        }
    }

    for (int k = 3; k <= l; k++) {
        for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
            for (int ii = 0; ii < n; ii++) for (int jj = 0; jj < n; jj++) {
                if (arr[i][j] != arr[ii][jj]) continue;
                for (int d = 0; d < 8; d++) for (int dd = 0; dd < 8; dd++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    int nii = ii + dir[dd][0], njj = jj + dir[dd][1];
                    if (chk(ni, nj, n) || chk(nii, njj, n)) continue;
                    dp[k][i][j][ii][jj] += dp[k-2][ni][nj][nii][njj];
                }
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)
        for (int ii = 0; ii < n; ii++) for (int jj = 0; jj < n; jj++) 
            ans += dp[l][i][j][ii][jj];
    cout << ans;
}