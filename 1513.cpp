#include <bits/stdc++.h>
using namespace std;

constexpr int N = 55;
constexpr int MOD = 1e6 + 7;
int dp[N][N][N][N];
int arr[N][N];

int dpf(int r, int c, int last, int cnt) {
    if (r == 1 && c == 1) {
        if (arr[r][c] && arr[r][c] < last && cnt == 1) return 1;
        if (!arr[r][c] && !cnt) return 1;
        return 0;
    }
    if (r < 1 || c < 1) return 0;
    int &ret = dp[r][c][last][cnt];
    if (~ret) return ret;
    ret = 0;
    if (arr[r][c] < last && arr[r][c] && cnt) {
        ret = (ret + dpf(r - 1, c, arr[r][c], cnt - 1)) % MOD;
        ret = (ret + dpf(r, c - 1, arr[r][c], cnt - 1)) % MOD;
    }
    if (!arr[r][c]) {
        ret = (ret + dpf(r - 1, c, last, cnt)) % MOD;
        ret = (ret + dpf(r, c - 1, last, cnt)) % MOD;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    int n, m, c; cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        int a, b; cin >> a >> b;
        arr[a][b] = i;
    }
    for (int i = 0; i <= c; i++) {
        // if (arr[n][m]) cout << dpf(n, m, arr[n][m], i - 1) << " ";
        // else 
        cout << dpf(n, m, N, i) << " ";
    }   
}