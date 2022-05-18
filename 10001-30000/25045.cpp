#include <bits/stdc++.h>
using namespace std;

int a[200005], b[200005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(a, a + n, [](const int &a, const int &b) { return a > b; });
    sort(b, b + m);
    long long ans = 0;
    for (int i = 0; i < m; i++) {
        if (a[i] > b[i]) ans += a[i] - b[i];
    }
    // for (int i = 0; i < n; i++) cout << a[i] << " \n"[i == n - 1]; 
    cout << ans;
}