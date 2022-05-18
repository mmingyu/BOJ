#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    int l = 1, num = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if ((~k) & x) {
            l = i + 1;
            num = 0;
        } else {
            num |= x;
            if (num == k) {
                cout << l << " " << i;
                return 0;
            }
        }
    }
    cout << -1;
}