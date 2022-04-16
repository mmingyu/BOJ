#include <bits/stdc++.h>
using namespace std;

struct T { int x, y, z; };
vector<T> arr;

int mat[302][302];
int par[302];

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

void merge(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    par[y] = x;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int inp; cin >> inp;
        arr.push_back({i, 0, inp});
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> mat[i][j];
            if (i != j) arr.push_back({i, j, mat[i][j]});
        }
    }
    for (int i = 0; i <= n; i++) par[i] = i;
    sort(arr.begin(), arr.end(), [](T a, T b) { return a.z < b.z; });
    int ans = 0;
    for (auto [x, y, cost]: arr) {
        x = find(x), y = find(y);
        if (x != y) {
            merge(x, y);
            ans += cost;
        }
    }
    printf("%d", ans);
}   