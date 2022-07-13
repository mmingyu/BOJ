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
        tree[n] ^= lazy[n] * (s - e + 1 & 1);
        if (s != e) {
            lazy[n << 1] ^= lazy[n];
            lazy[n << 1 | 1] ^= lazy[n];
        }
        lazy[n] = 0;
    }
public:
    LazySegtree(int N) : N(N) {
        tree.resize(N << 2);
        lazy.resize(N << 2);
    }


    void update(int qs, int qe, T diff, int n, int s, int e) {
        propagate(n, s, e);
        if (e < qs || s > qe) return;
        if (qs <= s && e <= qe) {
            tree[n] ^= diff * (s - e + 1 & 1);
            if (s != e) {
                lazy[n << 1] ^= diff;
                lazy[n << 1 | 1] ^= diff;
            }
            return;
        }
        int mid = s + e >> 1;
        update(qs, qe, diff, n << 1, s, mid);
        update(qs, qe, diff, n << 1 | 1, mid + 1, e);
        tree[n] = tree[n << 1] ^ tree[n << 1 | 1];
    }
    void update(int qs, int qe, T diff) { update(qs, qe, diff, 1, 0, N); }

    T query(int qs, int qe, int n, int s, int e) {
        propagate(n, s, e);
        if (e < qs || s > qe) return 0;
        if (qs <= s && e <= qe) return tree[n];
        int mid = s + e >> 1;
        return query(qs, qe, n << 1, s, mid) ^ query(qs, qe, n << 1 | 1, mid + 1, e);
    }
    T query(int qs, int qe) { return query(qs, qe, 1, 0, N); }
};

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    LazySegtree<int> seg(n);
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        seg.update(i, i, x);
    }
    int m; cin >> m;
    while (m--) {
        int q; cin >> q;
        if (q == 1) {
            int s, e, k; cin >> s >> e >> k;
            seg.update(s, e, k);
        }
        if (q == 2) {
            int i; cin >> i;
            cout << seg.query(i, i) << "\n";
        }
    }
}