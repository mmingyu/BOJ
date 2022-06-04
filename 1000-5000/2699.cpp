#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;
#define x first
#define y second
#define sz(x) int((x).size())

ll ccw(p a, p b, p c) {
    return a.x * b.y + b.x * c.y + c.x * a.y
        - (a.y * b.x + b.y * c.x + c.y * a.x);
}
p operator-(p a, p b) { 
    return {a.x - b.x, a.y - b.y}; 
}
ll dist(p a, p b) { 
    p p = a - b; 
    return p.x * p.x + p.y * p.y;
}

vector<p> v;

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        v.resize(n);
        for (auto &[x, y] : v) cin >> x >> y;
        
        swap(v[0], *max_element(v.begin(), v.end(), [](p a, p b) { 
            if (a.y == b.y) return a.x > b.x;
            return a.y < b.y;
        }));

        sort(v.begin() + 1, v.end(), [&](p a, p b) -> bool {
            if (ll c = ccw(v[0], a, b); c != 0) return c < 0;
            return dist(v[0], a) < dist(v[0], b);
        });
        vector<p> hull;
        for (const auto &p : v) {
            while (sz(hull) >= 2 && ccw(hull[sz(hull) - 2], hull.back(), p) >= 0) hull.pop_back();
            hull.push_back(p);
        }
        
        cout << sz(hull) << "\n";
        for (auto [x, y] : hull) {
            cout << x << " " << y << "\n";
        }
    }
}
