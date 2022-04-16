#include <bits/stdc++.h>
using namespace std;

int arr[65][65];
string ans;

void solve(int r, int c, int n) {
    int flag = 0;
    for (int i = r; i < r + n; i++) {
        for (int j = c; j < c + n; j++) {
            if (arr[i][j] != arr[r][c]) flag++;
        }
    }

    if (!flag || flag == n * n) {
        ans += arr[r][c] + '0';
    } else {
        int md = n >> 1;
        ans += '(';
        solve(r, c, md);
        solve(r, c + md, md);
        solve(r + md, c, md);
        solve(r + md, c + md, md);
        ans += ')';
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            scanf("%1d", &arr[i][j]);
    solve(0, 0, n);
    cout << ans;
}