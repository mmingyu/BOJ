#include <bits/stdc++.h>
using namespace std;

int a_psum[2003], b_psum[2003];
int a[2003], b[2003];
int a_size[2000006], b_size[2000006];

int main() {
    int sz; cin >> sz;
    int m, n; cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        a[i + m] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i + n] = b[i];
    }
    
    for (int i = 1; i <= 2 * m; i++) {
        a_psum[i] = a_psum[i - 1] + a[i];
    }
    for (int i = 1; i <= 2 * n; i++) {
        b_psum[i] = b_psum[i - 1] + b[i];
    }
    a_size[a_psum[m]]++;
    b_size[b_psum[n]]++;
    for (int i = 1; i <= 2 * m; i++) {
        for (int j = i; j <= 2 * m; j++) {
            if ((i > m && j > m) || j - i >= m - 1) continue;
            int k = a_psum[j] - a_psum[i - 1];
            a_size[k]++;
        }
    }
    for (int i = 1; i <= 2 * n; i++) {
        for (int j = i; j <= 2 * n; j++) {
            if ((i > n && j > n) || j - i >= n - 1) continue;
            int k = b_psum[j] - b_psum[i - 1];
            b_size[k]++;
        }
    }
    int ans = a_size[sz] + b_size[sz];
    for (int i = 1; i < sz; i++) {
        ans += a_size[i] * b_size[sz - i];
    }
    cout << ans;
}