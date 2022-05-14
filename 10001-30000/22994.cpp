#include <bits/stdc++.h>
using namespace std;

char arr[1003][1003];
int r_chk[1003], c_chk[1003];
int n, m; 

bool is_c_same(int x, int y) {
    for (int i = 0; i < n; i++) if (arr[i][x] != arr[i][y]) return false;
    return true;
}

bool is_r_same(int x, int y) {
    for (int i = 0; i < m; i++) if (arr[x][i] != arr[y][i]) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < max(n, m); i++) r_chk[i] = c_chk[i] = i;

    for (int i = 0; i < n - 1; i++) {
        if (is_r_same(i, i + 1)) r_chk[i + 1] = r_chk[i];
    }
    for (int i = 0; i < m - 1; i++) {
        if (is_c_same(i, i + 1)) c_chk[i + 1] = c_chk[i];
    }
    
    // for (int i = 0; i < n; i++) cout << r_chk[i];
    // cout << endl;
    // for (int i = 0; i < m; i++) cout << c_chk[i];
    // cout << endl;
    
    int div_n = 1, div_m = 1;
    for (int i = 2; i <= n; i++) {
        if (n % i) continue;
        bool flag = true;
        for (int j = 0; j < n; j += i) for (int k = j; k < j + i; k++) {
            if (r_chk[k] != r_chk[j]) flag = false;
        }
        if (flag) div_n = i;
    }
    for (int i = 2; i <= m; i++) {
        if (m % i) continue;
        bool flag = true;
        for (int j = 0; j < m; j += i) {
            for (int k = j; k < j + i; k++) if (c_chk[k] != c_chk[j]) flag = false;
        }
        if (flag) div_m = i;
    }
    cout << n / div_n << " " << m / div_m << "\n";
    for (int i = 0; i < n; i += div_n) {
        for (int j = 0; j < m; j += div_m) {
            cout << arr[i][j];
        }
        cout << "\n";
    }
}