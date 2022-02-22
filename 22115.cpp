#include <bits/stdc++.h>
using namespace std;

int arr[102], dp[100005];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    for (int i = 1; i <= k; i++) dp[i] = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = k; j >= arr[i]; j--) dp[j] = min(dp[j], dp[j - arr[i]] + 1);
    }

    printf("%d", dp[k] == 1e9 ? -1 : dp[k]);
}