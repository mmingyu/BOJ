#include <bits/stdc++.h>
using namespace std;

int dp[1200][20];
int prime[1200];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    fill(prime, prime + 1200, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < 1200; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j < 1200; j += i) prime[j] = false;
    }
    dp[0][0] = 1;
    for (int i = 2; i < 1200; i++) if (prime[i]) {
        for (int j = 14; j >= 0; j--) {
            for (int k = 2; k < 1200; k++) {
                if (k - i >= 0) dp[k][j] += dp[k - i][j - 1];
            }
        }
    }
    
    int n; cin >> n;
    while (n--) {
        int a, b; cin >> a >> b;
        cout << dp[a][b] << '\n';
    }
}