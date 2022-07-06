#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) (x).size()
constexpr int N = 1e6 + 5;

struct Q { int s, e, i; };
int arr[N], cnt[N], ans[N], x, sqrtn;
Q q[N];

void mi(int s, int e) {
    for (int i = s; i <= e; i++) {
        if (--cnt[arr[i]] == 0) x--;
    }
}

void pl(int s, int e) {
    for (int i = s; i <= e; i++) {
        if (cnt[arr[i]]++ == 0) x++;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        q[i] = {l, r, i};
    }
    sqrtn = sqrt(n);
    sort(q, q + m, [&](const Q &a, const Q &b) {
        if (a.s / sqrtn != b.s / sqrtn) return a.s < b.s; 
        return a.e < b.e;
    });
    for (int i = q[0].s; i <= q[0].e; i++) {
        if (cnt[arr[i]]++ == 0) x++;
    }
    ans[q[0].i] = x;
    int s = q[0].s, e = q[0].e;
    for (int i = 1; i < m; i++) {
        if (s < q[i].s) mi(s, q[i].s - 1);
        if (q[i].s < s) pl(q[i].s, s - 1);
        if (q[i].e < e) mi(q[i].e + 1, e);
        if (e < q[i].e) pl(e + 1, q[i].e);
        s = q[i].s, e = q[i].e;
        ans[q[i].i] = x;
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}