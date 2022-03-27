#include <bits/stdc++.h>
using namespace std;

int arr[1003], dp[1003], par[1003];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 1; i <= n; i++) {
        int mx = 0;
        for (int j = 1; j < i; j++) {
            if (arr[i] > arr[j] && mx <= dp[j]) {
                mx = dp[j];
                par[i] = j;
            }
        }
        dp[i] = mx + 1;
    }
    int *mx = max_element(dp + 1, dp + n + 1);
    cout << *mx << '\n';
    
    vector<int> ans;
    int cur = mx - dp;
    while (cur) {
        ans.push_back(arr[cur]);
        cur = par[cur];
    }
    for (int i = ans.size() - 1; i >= 0; i--) cout << ans[i] << ' ';
}