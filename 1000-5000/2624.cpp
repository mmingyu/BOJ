#include <bits/stdc++.h>
using namespace std;

int t, n;
pair<int, int> arr[102];
int dp[102][10004];

int dpf(int cur, int last) {
    if (last < 0) return 0;
    if (cur == 0) return !last;
    int &ret = dp[cur][last];
    if (~ret) return ret;
    ret = 0;
    for (int i = 0; i <= arr[cur].second; i++) {
        ret += dpf(cur - 1, last - i * arr[cur].first);
    }
    return ret;
}
int main() {
    memset(dp, -1, sizeof(dp));
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> t >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i].first >> arr[i].second;
    cout << dpf(n, t);
}