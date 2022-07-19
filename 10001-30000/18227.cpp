#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

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

constexpr int N = 2e5 + 5;
vector<int> adj[N];
int pos[N], sz[N], dep[N], p;

void dfs(int cur, int prv) {
    pos[cur] = p++;
    dep[cur] = dep[prv] + 1;
    for (auto nxt : adj[cur]) {
        if (nxt != prv) dfs(nxt, cur);
    }
    sz[cur] = p - pos[cur] - 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    SegTree<ll> t(N);
    int n, root; cin >> n >> root;
    for (int i = 0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(root, 0);
    int m; cin >> m;
    while (m--) {
        int q, x; cin >> q >> x;
        if (q == 1) t.update(pos[x], 1);
        if (q == 2) cout << t.query(pos[x], pos[x] + sz[x]) * dep[x] << "\n";
        
    }
}