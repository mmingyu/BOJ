#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 500005;
int par[N];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    iota(par, par + N, 0);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        x = find(x); y = find(y);
        if (x == y) {
            cout << i;
            return 0;
        }
        par[x] = y;
    }
    cout << 0;    
}