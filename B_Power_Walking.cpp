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
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(all(arr));
        arr.erase(unique(all(arr)), arr.end());
        for (int i = 0; i < sz(arr); i++) {
            printf("%d ", sz(arr));
        }
        for (int i = 1; i <= n - sz(arr); i++) {
            printf("%d ", sz(arr) + i);
        }
        printf("\n");
    }
}