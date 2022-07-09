#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define md (s + e >> 1)
#define f first
#define s second
constexpr int MOD = 1e9 + 7;
constexpr int N = 1.01e5;

ll tree[N << 2];
pair<ll, ll> lazy[N << 2];

void propagate(int n, int s, int e) {
    auto &[m ,p] = lazy[n];
    if (m == 1 && p == 0) return;
    tree[n] *= m, tree[n] %= MOD;
    tree[n] += (e - s + 1) * p, tree[n] %= MOD;
    if (s != e) {
        auto &[m1, p1] = lazy[n << 1];
        auto &[m2, p2] = lazy[n << 1 | 1];
        m1 *= m, m1 %= MOD;
        m2 *= m, m2 %= MOD;
        p1 = m * p1 + p, p1 %= MOD;
        p2 = m * p2 + p, p2 %= MOD;
    }
    m = 1, p = 0;
}

void update(int qs, int qe, ll k, int mode, int n = 1, int s = 0, int e = N) {
    propagate(n, s, e);
    if (e < qs || qe < s) return;
    if (qs <= s && e <= qe) {
        auto &[m, p] = lazy[n];
        if (mode == 0) p += k, p % MOD;
        if (mode == 1) m *= k, m % MOD;
        if (mode == 2) m = 0, p = k;
        propagate(n, s, e);
        return;
    }
    update(qs, qe, k, mode, n << 1, s, md);
    update(qs, qe, k, mode, n << 1 | 1, md + 1, e);
    tree[n] = tree[n << 1] + tree[n << 1 | 1], tree[n] %= MOD;
}

ll query(int qs, int qe, int n = 1, int s = 0, int e = N) {
    propagate(n, s, e);
    if (e < qs || qe < s) return 0;
    if (qs <= s && e <= qe) return tree[n] % MOD;
    return (query(qs, qe, n << 1, s, md) + query(qs, qe, n << 1 | 1, md + 1, e)) % MOD;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fill(lazy, lazy + 4 * N, make_pair(1, 0));
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        update(i, i, x % MOD, 0);
    }
    int m; cin >> m;
    while (m--) {
        int q, x, y; cin >> q >> x >> y;
        if (q == 1) {
            int v; cin >> v;
            update(x, y, v, 0);
        } 
        if (q == 2) {
            int v; cin >> v;
            update(x, y, v, 1);
        } 
        if (q == 3) {
            int v; cin >> v;
            update(x, y, v, 2);
        }
        if (q == 4) {
            cout << query(x, y) << "\n";
        }
    }
}
