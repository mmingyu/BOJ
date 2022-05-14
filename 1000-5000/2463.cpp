#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e5 + 5;
constexpr int MOD = 1e9;

struct T { 
    int x, y; 
    long long d; 
} arr[N];

int par[N], sz[N];

int find(int x) {
    if (par[x] == x) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    par[y] = x;
    sz[x] += sz[y];
    sz[y] = 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<T> arr(m);
    for (auto &[x, y, d] : arr) cin >> x >> y >> d;

    sort(arr.begin(), arr.end(), [](const T a, const T b) { return a.d > b.d; });

    for (int i = 1; i <= n; i++) par[i] = i, sz[i] = 1;

    long long ans = 0;
    long long cnt = 0;
    
    for (auto [x, y, d] : arr) {
        x = find(x), y = find(y);
        if (x != y) {
            cnt = (cnt + 1LL * sz[x] * sz[y]) % MOD;
            merge(x, y);
        }
        ans = (ans + cnt * d) % MOD;
    }
    cout << ans;
}
