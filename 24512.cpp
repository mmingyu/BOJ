#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

const int INF = 1e9;
int arr[11][11];

int main() {
    fastio;
    int n, m; cin >> n >> m;
    for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) arr[i][j] = INF;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        arr[a][b] = min(arr[a][b], c);
    }
    vector<int> v, ans_ord;
    for (int i = 1; i <= n; i++) v.push_back(i);
    int ans = INF;
    do {
        int mx = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int cost = INF;
            if (i == n - 1) cost = arr[v[i]][v[0]];
            else cost = arr[v[i]][v[i + 1]];
            if (cost == INF) {
                flag = false;
                break;
            }
            mx = max(cost, mx);
        }
        if (flag && ans > mx) {
            ans = mx;
            ans_ord = v;
        }
    } while(next_permutation(all(v)));

    if (ans == INF) {
        cout << -1;
    } else {
        cout << ans << '\n';
        for (auto x : ans_ord) cout << x << ' ';
    }
}