#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

template<class T>
class SegTree {
private:
    const int N;
    vector<T> tree;
    void update(int idx, T diff, int node, int s, int e) {
        if (idx < s || idx > e) return;
        tree[node] += diff;
        if (s == e) return;
        int mid = s + e >> 1;
        update(idx, diff, node << 1, s, mid);
        update(idx, diff, node << 1 | 1, mid + 1, e);
    }
    T query(int l, int r, int node, int s, int e) {
        if (l <= s && e <= r) return tree[node];
        if (r < s || e < l) return 0;
        int mid = s + e >> 1;
        return query(l, r, node << 1, s, mid) + query(l, r, node << 1 | 1, mid + 1, e);
    }

public:
    SegTree(int N) : N(N) { tree.resize(4 * N); }
    void update(int idx, T diff) { update(idx, diff, 1, 0, N); }
    T query(int l, int r) { return query(l, r, 1, 0, N); }
};

struct T { int l, r; ll c; };
constexpr int N = 1e6 + 6;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<T> arr(n);
    vector<int> cm;
    for (auto &[l, r, c] : arr) {
        cin >> l >> r >> c; 
        cm.push_back(l);
    }
    compress(cm);
    SegTree<ll> seg(N);
    sort(all(arr), [](T a, T b) { 
        if (a.r == b.r) return a.l > b.l;
        return a.r < b.r; 
    });
    
    ll ans = 0;
    for (auto &[l, r, c] : arr) {
        l = lower_bound(all(cm), l) - cm.begin();
        seg.update(l, c);
        ans = max(ans, seg.query(l, N));
    }
    cout << ans;
}