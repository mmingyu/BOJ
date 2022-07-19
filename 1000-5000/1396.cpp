#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 1e5 + 5;
struct E { int u, v, w; } e[N];
struct UnionFind {
    UnionFind() { 
        iota(par, par + N, 0);
        fill(sz, sz + N, 1);
    }
    int par[N], sz[N];
    int find(int x) {
        if (x == par[x]) return x;
        return par[x] = find(par[x]); 
    }
    void merge(int x, int y) {
        x = find(x), y = find(y);
        if (x == y) return;
        par[x] = y;
        sz[y] += sz[x];
        sz[x] = 0;
    }
    int size(int x) {
        return sz[find(x)];
    }
};

int lo[N], hi[N];
pair<int, int> q[N], ans[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        e[i] = {a, b, c};
    }
    int qq; cin >> qq;
    for (int i = 0; i < qq; i++) {
        cin >> q[i].first >> q[i].second;
    }

    sort(e, e + m, [](E a, E b) { return a.w < b.w; });
    fill(hi, hi + qq, m + 1);
    
    while (true) {
        bool flag = false;
        vector<int> g[N];
        for (int i = 0; i < qq; i++) if (lo[i] + 1 < hi[i]) {
            g[lo[i] + hi[i] >> 1].push_back(i);
            flag = true;
        }
        if (!flag) break;

        UnionFind uf;
        for (int i = 0; i < m; i++) {
            auto [u, v, w] = e[i];
            uf.merge(u, v);
            for (int j : g[i + 1]) {
                int a = uf.find(q[j].first);
                int b = uf.find(q[j].second);
                if (a == b) {
                    hi[j] = i + 1;
                    ans[j] = {w, uf.size(a)};
                } else {
                    lo[j] = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < qq; i++) {
        if (lo[i] == m) cout << -1 << "\n";
        else cout << ans[i].first << " " << ans[i].second << "\n";
    }
}