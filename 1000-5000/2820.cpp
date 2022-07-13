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

constexpr int N = 5e5 + 5;
LazySegtree<ll> tree(N);
vector<int> v[N];
int arr[N], pos[N], child[N], cnt;

void dfs(int cur) {
    pos[cur] = cnt++;
    for (auto nxt : v[cur]) dfs(nxt);
    child[cur] = cnt - pos[cur] - 1;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    cin >> arr[1];
    for (int i = 2; i <= n; i++) {
        int x; cin >> arr[i] >> x;
        v[x].push_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; i++) tree.update(pos[i], pos[i], arr[i]);
    while (m--) {
        char c; cin >> c;
        if (c == 'p') {
            int a, x; cin >> a >> x;
            tree.update(pos[a] + 1, pos[a] + child[a], x);
        } else {
            int a; cin >> a;
            cout << tree.query(pos[a], pos[a]) << "\n";
        }
    }
}