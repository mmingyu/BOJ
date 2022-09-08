#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> arr(n+n);
    for (auto &x : arr) cin >> x;
    sort(all(arr));
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        ans = min(ans, arr[i] + arr[n + n - i - 1]);
    }
    cout << ans;
}