#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            ans |= x;
        }
        printf("%d\n", ans);
    }
}