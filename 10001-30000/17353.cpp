#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

template<class T>
class LazySegtree {
private:
    const int N;
    vector<T> tree;
    vector<T> lazy;
    
    void propagate(int n, int s, int e) {
        if (lazy[n] == 0) return;
        tree[n] += (e - s + 1) * lazy[n];
        if (s != e) {
            lazy[n << 1] += lazy[n];
            lazy[n << 1 | 1] += lazy[n];
        }
        lazy[n] = 0;
    }

    void update(int qs, int qe, T diff, int n, int s, int e) {
        propagate(n, s, e);
        if (e < qs || s > qe) return;
        if (qs <= s && e <= qe) {
            lazy[n] = diff;
            propagate(n, s, e);
            return;
        }
        int mid = s + e >> 1;
        update(qs, qe, diff, n << 1, s, mid);
        update(qs, qe, diff, n << 1 | 1, mid + 1, e);
        tree[n] = tree[n << 1] + tree[n << 1 | 1];
    }

    T query(int qs, int qe, int n, int s, int e) {
        propagate(n, s, e);
        if (e < qs || s > qe) return 0;
        if (qs <= s && e <= qe) return tree[n];
        int mid = s + e >> 1;
        return query(qs, qe, n << 1, s, mid) + query(qs, qe, n << 1 | 1, mid + 1, e);
    }

public:
    LazySegtree(int N) : N(N) {
        tree.resize(N << 2);
        lazy.resize(N << 2);
    }
    void update(int qs, int qe, T diff) { update(qs, qe, diff, 1, 0, N); }
    T query(int qs, int qe) { return query(qs, qe, 1, 0, N); }
};

constexpr int N = 1e5 + 5;
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    LazySegtree<ll> seg(N);
    int prv = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        seg.update(i, i, x - prv);
        prv = x;
    }
    int m; cin >> m;
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int s, e; cin >> s >> e;
            seg.update(s, e, 1);
            seg.update(e + 1, e + 1, -(e - s + 1));
        } else {
            int x; cin >> x;
            cout << seg.query(1, x) << "\n";
        }
    }
}