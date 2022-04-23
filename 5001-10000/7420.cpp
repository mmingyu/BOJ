#include <bits/stdc++.h>
using namespace std;
#define sz(x) int((x).size())

const double PI = acos(-1);

struct T {
    long long x, y, p, q;
    T operator-(T o) { return T(x - o.x, y - o.y, 0, 0); }
    bool operator<(T o) {
        if (q * o.p != p * o.q) return q * o.p < p * o.q;
        if (y == o.y) return x < o.x;
        return y < o.y;
    }
};

long long ccw(T a, T b, T c) {
    return a.x * b.y + b.x * c.y + c.x * a.y
        - (a.y * b.x + b.y * c.x + c.y * a.x);
}

long long dist(T a, T b) {
    a = a - b;
    return a.x * a.x + a.y * a.y;
}
T inp[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, l; cin >> n >> l;
    for (int i = 0; i < n; i++) cin >> inp[i].x >> inp[i].y;
    sort(inp, inp + n);
    for (int i = 1; i < n; i++) {
        inp[i].p = inp[i].x - inp[0].x;
        inp[i].q = inp[i].y - inp[0].y;        
    }
    sort(inp + 1, inp + n);
    vector<T> st;
    for (int i = 0; i < n; i++) {
        while (sz(st) >= 2 && ccw(st[sz(st) - 2], st.back(), inp[i]) <= 0) {
            st.pop_back();
        }
        st.push_back(inp[i]);
    }
    // for (auto [x, y, p, q] : st) {
    //     cout << x << " " << y << endl;
    // }
    // cout << ans << endl;
    double ans = 0;
    for (int i = 0; i < sz(st); i++) {
        ans += sqrt(dist(st[i], st[(i + 1) % sz(st)]));
        // cout << dist(st[i], st[(i + 1) % sz(st)]) << endl;
    }
    // cout << ans << endl;
    // cout << sqrt(ans) << endl;
    cout << (int)round(ans + 2 * PI * l);
}