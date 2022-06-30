#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int a, b; cin >> a >> b;
        int ans = 1;
        for (int i = 0; i < b; i++) ans = (ans * a) % 10;
        cout << (ans == 0 ? 10 : ans) << "\n";
    }
}