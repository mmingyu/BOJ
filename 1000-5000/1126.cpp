#include <bits/stdc++.h>
using namespace std;

int arr[52], dp[52][500005], n; 

int dpf(int cur, int diff) {
    int &ret = dp[cur][diff];
    if (ret) return ret;
    if (cur == n) {
        if (diff) return -1e9;
        return 0;
    }
    return ret = max({
        dpf(cur + 1, diff), 
        dpf(cur + 1, diff + arr[cur]) + arr[cur], 
        dpf(cur + 1, abs(diff - arr[cur])) + (diff - arr[cur] < 0 ? arr[cur] - diff : 0)
    });
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = dpf(0, 0);
    printf("%d", ans ? ans : -1);
}