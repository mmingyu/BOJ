#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define endl '\n'

bool chk(ll x) {
    ll l = -1, r = 1e9 + 1;
    while (l + 1 < r) {
        ll mid = l + r >> 1LL;
        if (mid * mid <= x) l = mid;
        else r = mid;
    }
    return l * l == x;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    vector<ll> b(all(a));
    sort(all(a));
    for (int i = 0; i < n; i++) {
        ll g = gcd(a[i], b[i]);
        if (!chk(a[i] / g) || !chk(b[i] / g)) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}