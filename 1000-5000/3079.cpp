#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int arr[100005];
ll n, m; 

ll cnt(ll k) {
    ll ret = 0;
    for (int i = 0; i < n; i++) ret += k / arr[i];
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    ll l = 0, r = ll(1e18);
    while (l + 1 < r) {
        ll mid = l + r >> 1;
        if (cnt(mid) >= m) r = mid;
        else l = mid;
    }
    cout << r;
}