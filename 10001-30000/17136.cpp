#include <bits/stdc++.h>
using namespace std;

int arr[12][12], ans = 1e9;
int check[10];

bool is_possible(int r, int c, int k) {
    if (r + k > 10 || c + k > 10) return false;
    for (int i = r; i < r + k; i++) {
        for (int j = c; j < c + k; j++) {
            if (!arr[i][j]) return false;
        }
    }
    return true;
}

void set_num(int r, int c, int k, int num) {
    for (int i = r; i < r + k; i++) {
        for (int j = c; j < c + k; j++) {
            arr[i][j] = num;
        }
    }
}

void solve(int r, int c, int cnt) {
    if (r == 10 || cnt > ans) {
        // printf("ret = %d %d\n", c, cnt);
        ans = min(ans, cnt);
        return;
    }
    if (!arr[r][c]) {
        solve(r + (c + 1) / 10, (c + 1) % 10, cnt);
    } else {
        for (int k = 1; k <= 5; k++) {
            if (check[k] < 5 && is_possible(r, c, k)) {
                set_num(r, c, k, 0);
                check[k]++;
                solve(r + (c + 1) / 10, (c + 1) % 10, cnt + 1);
                set_num(r, c, k, 1);
                check[k]--;
            }
        }    
    }
}

int main() {
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) cin >> arr[i][j];
    solve(0, 0, 0);
    cout << (ans == 1e9 ? -1 : ans);
}