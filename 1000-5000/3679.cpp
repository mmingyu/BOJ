#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct P {
    ll x, y, idx;
    P operator-(P o) { return {x - o.x, y - o.y, idx}; }
};

ll ccw(P a, P b, P c) {
    return a.x * b.y + b.x * c.y + c.x * a.y 
        - (a.y * b.x + b.y * c.x + c.y * a.x);
}

ll dist(P a, P b) {
    a = a - b;
    return a.x * a.x + a.y * a.y;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<P> v(n);
        for (int i = 0; i < n; i++) {
            auto &[x, y, idx] = v[i];
            cin >> x >> y, idx = i;
        }
        sort(v.begin(), v.end(), [&](P a, P b)->bool {
            return tie(a.x, a.y) < tie(b.x, b.y);
        });
        sort(v.begin() + 1, v.end(), [&](P a, P b)->bool {
            if (ll d = ccw(v[0], a, b); d != 0) return d > 0;
            return dist(v[0], a) < dist(v[0], b);
        });
        int cnt = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (!ccw(v[0], v[n - 1], v[i])) cnt++;
            else break;
        }
        reverse(v.end() - cnt, v.end());       
        for (auto p : v) cout << p.idx << " ";
        cout << '\n';
    }
}