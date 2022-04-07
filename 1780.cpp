#include <bits/stdc++.h>
using namespace std;

int arr[2202][2202];

int ans[3];

void solve(int r, int c, int n) {
    int cnt[3] = {0, };
    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (arr[i][j] == 1) cnt[2]++;
            else if (arr[i][j] == -1) cnt[0]++;
            else cnt[1]++;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (cnt[i] == n * n) {
            ans[i]++;
            return;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            solve(r + i * n / 3, c + j * n / 3, n / 3);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];
    solve(0, 0, n);
    for (auto x : ans) cout << x << '\n';
}