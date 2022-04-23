#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int((x).size())

struct T {
    ll x, y, p, q;
    T(ll x = 0, ll y = 0, ll p = 1, ll q = 0) : x(x), y(y), p(p), q(q) {}
    T operator-(const T &a) { return {x - a.x, y - a.y, 0, 0}; }
    bool operator<(const T &a) {
        if (p * a.q != a.p * q) return a.p * q < p * a.q;
        if (y == a.y) return x < a.x;
        return y < a.y;
    }
};

T arr[200005];

ll ccw(const T &a, const T &b, const T &c) {
    return a.x * b.y + b.x * c.y + c.x * a.y 
        - (a.y * b.x + b.y * c.x + c.y * a.x);
}

vector<T> convex_hull(int n) {
    vector<T> st;
    sort(arr, arr + n);
    for (int i = 1; i < n; i++) {
        arr[i].p = arr[i].x - arr[0].x;
        arr[i].q = arr[i].y - arr[0].y;
    }
    sort(arr + 1, arr + n);
    for (int i = 0; i < n; i++) {
        while (sz(st) >= 2 && ccw(st[sz(st) - 2], st.back(), arr[i]) <= 0) st.pop_back();
        st.push_back(arr[i]);
    }
    return st;
}

ll dist(T a, T b) {
    T c = a - b;
    return c.x * c.x + c.y * c.y;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> arr[i].x >> arr[i].y;
            arr[i].p = 1, arr[i].q = 0;
        }
        
        auto v = convex_hull(n);
        
        
        // for (int i = 0; i < sz(v); i++) {
        //     if(v[i].x < v[lp].x) lp = i;
        //     if(v[i].x > v[lp].x) rp = i;
        // }
        
        int lp = 0, rp = 1;
        ll mx = dist(v[lp], v[rp]);
        T ans[2] = {v[lp], v[rp]};
        T zero = {0, 0, 0, 0};

        for (int i = 0; i < 2 * sz(v); i++) {
            int nlp = (lp + 1) % sz(v);
            int nrp = (rp + 1) % sz(v);
            if (ccw(zero, v[nlp] - v[lp], v[nrp] - v[rp]) <= 0) lp = nlp;
            else rp = nrp;
            
            ll nd = dist(v[lp], v[rp]);
            if (nd > mx) ans[0] = v[lp], ans[1] = v[rp], mx = nd;
        }
        printf("%d %d %d %d\n", ans[0].x, ans[0].y, ans[1].x, ans[1].y);
    }

}

// -3 -6
// 6 -6
// 12 0
// 6 9
// 0 9
// -6 3