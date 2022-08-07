#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int dp[32][32];

int main() {
    string s; cin >> s;
    int n = sz(s), ans = 0;
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) dp[i][i + 1] = 3;
        else dp[i][i + 1] = 2;
    }
    for (int k = 2; k < n; k++) {
        for (int i = 0, j = k; j < n; i++, j++) {
            dp[i][j] = dp[i + 1][j] + dp[i][j - 1];
            if (s[i] == s[j]) dp[i][j] += 1;
            else dp[i][j] -= dp[i + 1][j - 1];
        }
    }
    
    cout << dp[0][n - 1];
}