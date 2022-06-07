#include <bits/stdc++.h>
using namespace std;

constexpr int INF = -2e8;
int arr[100005];
int dp[2][100005];

int dpf(int x, int cur) {
    if (cur < 0) return 0;
    int &ret = dp[x][cur];
    if (ret != INF) return ret;
    ret = max({dpf(x, cur - 1) + arr[cur], arr[cur]});
    if (x == 0) ret = max(ret, dpf(x + 1, cur - 1));
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    fill(dp[0], dp[2], INF);
    dpf(0, n);
    int ans = *max_element(dp[0], dp[2]);
    if (ans == 0) cout << *max_element(arr, arr + n);
    else cout << ans;
    
    // for (int i = 0; i < 2; i++) {
    //     for (int j = 0; j < n; j++) {
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
}