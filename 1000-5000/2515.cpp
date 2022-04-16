#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[300005];
int dp[300005], n, s;

int dpf(int cur) {
    if (cur >= n) return 0;
    int &ret = dp[cur];
    if (~ret) return ret;
    int idx = lower_bound(arr, arr + n, pair(arr[cur].first + s, 0)) - arr;
    return ret = max({ret, dpf(idx) + arr[cur].second, dpf(cur + 1)});
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    memset(dp, -1, sizeof(dp));
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }
    sort(arr, arr + n);
    cout << dpf(0);
}