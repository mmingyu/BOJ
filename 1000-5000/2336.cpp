#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

template<class T>
class SegTree {
private:
    const int N;
    const T INF;
    vector<T> tree;
    
    void update(int idx, T val, int node, int s, int e) {
        if (idx < s || idx > e) return;
        if (s == e) { tree[node] = val; return; }
        int mid = s + e >> 1;
        update(idx, val, node << 1, s, mid);
        update(idx, val, node << 1 | 1, mid + 1, e);
        tree[node] = min(tree[node << 1], tree[node << 1 | 1]);
    }

    T query(int l, int r, int node, int s, int e) {
        if (l <= s && e <= r) return tree[node];
        if (r < s || e < l) return INF;
        int mid = s + e >> 1;
        return min(query(l, r, node << 1, s, mid), query(l, r, node << 1 | 1, mid + 1, e));
    }
    
public:
    SegTree(int N, T INF = 2.1e9) : N(N), INF(INF) { tree.resize(4 * N); }
    void update(int idx, T val) { update(idx, val, 1, 0, N); }
    T query(int l, int r) { return query(l, r, 1, 0, N); }
};

constexpr int N = 5e5 + 5;
struct T { int a, b, c; } arr[N];
SegTree<int> tree(N, 1e9);

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) { int x; cin >> x; arr[x].a = i; }
    for (int i = 0; i < n; i++) { int x; cin >> x; arr[x].b = i; }
    for (int i = 0; i < n; i++) { int x; cin >> x; arr[x].c = i; }
    sort(arr + 1, arr + n + 1, [&](const T &a, const T &b) { return a.a < b.a; });

    int ans = 0;
    for (int i = 0; i < n; i++) tree.update(i, 1e9);
    for (int i = 1; i <= n; i++) {
        const auto &[a, b, c] = arr[i];
        // printf("%d %d %d : %d\n", a, b, c, tree.query(1, b));
        if (tree.query(0, b) > c) ans++;
        tree.update(b, c);
    }
    cout << ans;
}