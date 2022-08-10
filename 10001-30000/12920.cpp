#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

vector<pair<int, int>> arr;
int dp[2003][10004], n, m;

int dpf(int cur, int last) {
    int &ret = dp[cur][last];
    if (cur == n) return 0;
    if (~ret) return ret;
    const auto &[w, v] = arr[cur];
    ret = max((last - w >= 0) ? dpf(cur + 1, last - w) + v : 0, dpf(cur + 1, last));
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int v, c, k; cin >> v >> c >> k;
        for (int i = 1; k > 0; i <<= 1) {
            if (i > k) i = k;
            arr.push_back({v * i, c * i});
            k -= i;
        }
    }
    n = sz(arr);
    memset(dp, -1, sizeof(dp));
    cout << dpf(0, m);
}
