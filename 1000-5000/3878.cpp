#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int((x).size())

struct P {
    ll x, y, p, q;
    bool operator<(P o) {
        if (q * o.p != p * o.q) return q * o.p < p * o.q;
        if (y != o.y) return y < o.y;
        return x < o.x;
    }
    bool operator>(P o) { return make_pair(x, y) > make_pair(o.x, o.y); }
    bool operator<=(P o) { return make_pair(x, y) <= make_pair(o.x, o.y); }
    bool operator==(P o) { return x == o.x && y == o.y; }
};

ll ccw(P a, P b, P c) {
    ll ret = a.x * b.y + b.x * c.y + c.x * a.y
        - (a.y * b.x + b.y * c.x + c.y * a.x);
    return (ret > 0) - (ret < 0);
}

vector<P> get_hull(vector<P> &v) {
    vector<P> h;
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        v[i].p = v[i].x - v[0].x;
        v[i].q = v[i].y - v[0].y;
    }
    sort(v.begin() + 1, v.end());
    for (int i = 0; i < v.size(); i++) {
        while (sz(h) >= 2 && ccw(h[sz(h) - 2], h.back(), v[i]) <= 0) h.pop_back();
        h.push_back(v[i]);
    }
    return h;
}

bool inner(const vector<P> &h, const P &p) {
    ll s = ccw(h[0], h[1], p);
    for (int i = 1; i < sz(h); i++) {
        if (s * ccw(h[i], h[(i + 1) % sz(h)], p) <= 0) return false;
    }
    return true;
}

bool chk(P a, P b, P c, P d) {
    ll abc = ccw(a, b, c), abd = ccw(a, b, d);
    ll cda = ccw(c, d, a), cdb = ccw(c, d, b);
    if (abc * abd == 0 && cda * cdb == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return a <= d && c <= b;
    }
    return abc * abd <= 0 && cda * cdb <= 0;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<P> nn(n), mm(m);
        for (auto &[x, y, p, q] : nn) cin >> x >> y, p = q = 0;
        for (auto &[x, y, p, q] : mm) cin >> x >> y, p = q = 0;
        auto n_h = get_hull(nn);
        auto m_h = get_hull(mm);
        bool flag = true;
        if (sz(n_h) > 2) for (const auto &p : m_h) if (inner(n_h, p)) flag = false;
        if (sz(m_h) > 2) for (const auto &p : n_h) if (inner(m_h, p)) flag = false;
    
        for (int i = 0; i < sz(n_h); i++) for (int j = 0; j < sz(m_h); j++) {
            if (chk(n_h[i], n_h[(i + 1) % sz(n_h)], m_h[j], m_h[(j + 1) % sz(m_h)])) flag = false;
        }
        cout << (flag ? "YES" : "NO") << '\n';
        
    }
}