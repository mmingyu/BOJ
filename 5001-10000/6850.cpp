#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
#define x first
#define y second

p operator-(const p &a, const p &b) { return {a.x - b.x, a.y - b.y}; }
ll dist(const p &a, const p &b) {
    p o = a - b;
    return o.x * o.x + o.y * o.y;
}

ll ccw(const p &a, const p &b, const p &c) {
    return (a.x*b.y + b.x*c.y + c.x*a.y)
        - (a.y*b.x + b.y*c.x + c.y*a.x);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<p> v(n);
    for (auto &[x, y] : v) cin >> x >> y;
    swap(v[0], *min_element(v.begin(), v.end()));   
    sort(v.begin() + 1, v.end(), [&](const p &a, const p &b) -> bool {
        if (ll dir = ccw(v[0], a, b); dir != 0) return dir > 0;
        return dist(v[0], a) < dist(v[0], b);
    });
    vector<p> hull;
    for (const auto &p : v) {
        while (hull.size() >= 2 && ccw(hull[hull.size() - 2], hull.back(), p) <= 0) hull.pop_back();
        hull.push_back(p);
    }
    ll ans = 0;
    for (int i = 1; i + 1 < hull.size(); i++) {
        ans += ccw(hull[0], hull[i], hull[i + 1]);
    }
    cout << ans / 100;
}