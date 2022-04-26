#include <bits/stdc++.h>
using namespace std;
#define sz(x) int((x).size())

struct T {
    using ll = long long;
    ll x, y, p, q;
    T (ll x = 0, ll y = 0, ll p = 0, ll q = 0) : x(x), y(y), p(p), q(q) {}
    bool operator<(T o) {
        if (q * o.p != p * o.q) return q * o.p < p * o.q;
        if (y != o.y) return y < o.y;
        return x < o.x;
    }
};

long long ccw(T a, T b, T c) {
    long long t = a.x * b.y + b.x * c.y + c.x * a.y
        - (a.y * b.x + b.y * c.x + c.y * a.x);
    return (t > 0) - (t < 0);
}

int n; 
T p;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> p.x >> p.y;
    vector<T> inp(n);
    for (auto &[x, y, p, q] : inp) cin >> x >> y;
    int ans = 0;
    while (sz(inp) > 2) {
        sort(inp.begin(), inp.end());
        for (int i = 1; i < sz(inp); i++) {
            inp[i].p = inp[i].x - inp[0].x;
            inp[i].q = inp[i].y - inp[0].y;
        }
        sort(inp.begin() + 1, inp.end());
        vector<T> tmp, st;
        for (int i = 0; i < sz(inp); i++) {
            while (sz(st) >= 2 && ccw(st[sz(st) - 2], st.back(), inp[i]) <= 0) {
                tmp.push_back(T(st.back().x, st.back().y, 0, 0));
                st.pop_back();
            }
            st.push_back(inp[i]);
        }

        if (sz(st) <= 2) break;
        bool flag = true;
        auto m = ccw(st[0], st[1], p);
        for (int i = 1; i < sz(st); i++) {
            if (m * ccw(st[i], st[(i + 1) % sz(st)], p) <= 0) flag = false;
        }
        inp = tmp;
        ans += flag;
    }
    cout << ans;
}