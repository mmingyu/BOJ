#include <bits/stdc++.h>
using namespace std;

constexpr int N = 5003;
int arr[N];
int dp[N][N];

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) dp[i][j] = 1e9;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0; 
        dp[i][i + 1] = (arr[i] != arr[i + 1]);
    }
    
    
    for (int k = 2; k <= n; k++) {
        for (int i = 1, j = i + k; j <= n; i++, j++) {
            if (arr[i] == arr[j]) dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            else dp[i][j] = min({dp[i][j], dp[i + 1][j] + 1, dp[i][j - 1] + 1});
        }
    }
    
    cout << dp[1][n];
}