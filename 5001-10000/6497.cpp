#include <bits/stdc++.h>
using namespace std;

struct Edge { 
    int u, v, w; 
    bool operator<(Edge o) { return w < o.w; }
};

constexpr int N = 2e5 + 5;
Edge arr[N];
int par[N];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void init() {
    for (int i = 0; i < N; i++) par[i] = i;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    while (true) {
        int m, n; cin >> m >> n;
        if (!m && !n) break;
        init();
        for (int i = 0; i < n; i++) {
            int a, b, c; cin >> a >> b >> c;
            arr[i] = {a, b, c};
        }
        int ans = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++) {
            auto [u, v, w] = arr[i];
            u = find(u), v = find(v);
            if (u == v) ans += w;
            else par[u] = v;
        }
        cout << ans << "\n";
    }
}