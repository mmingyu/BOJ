#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int x, n;

void solve() {
    x *= 10000000;
    vector<int> v(n);
    for (int &i : v) cin >> i;
    sort(all(v));
    for (int i = 0; i < n; i++) {
        int lo = lower_bound(all(v), x - v[i]) - v.begin();
        int up = upper_bound(all(v), x - v[i]) - v.begin();
        if (up - lo == 1 && v[i] == v[lo]) continue;
        if (x - v[i] == v[lo]) {
            cout << "yes " << v[i] << " " << v[lo] << "\n";
            return;
        }
    }
    cout << "danger\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (cin >> x >> n) {
        solve();
    }
}