#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

int main() {
    int tc; cin >> tc;
    while (tc--) {
        int n, x; cin >> n >> x;
        vector<ll> arr(n);
        multiset<ll> s;
        for (int i = 0; i < n; i++) cin >> arr[i];
        for (auto x : arr) s.insert(x);
        int ans = 0;
        
        while (s.size()) {
            auto cur = s.begin();
            auto lb = s.lower_bound((*cur) * x);
            if (lb != s.end() && *lb == ((*cur) * x)) {
                s.erase(cur);
                s.erase(lb);
            } else {
                ans++;
                s.erase(cur);
            }
        }
        printf("%d\n", ans);
    }
}