#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

ll n, d; 

ll f(vector<ll> v) {
    for (int i = 0; i < sz(v); i++) v[i] -= i * d;
    return *max_element(all(v)) - *min_element(all(v)); 
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> d;
    vector<ll> v(n);
    for (ll &x : v) cin >> x;
    ll ans = f(v);
    reverse(all(v));
    ans = min(ans, f(v));
    cout << (ans / 2) << "." << (5 * (ans & 1));
}