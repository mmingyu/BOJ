#include <bits/stdc++.h>
using namespace std;

vector<int> p;
constexpr int N = 1200;

int dp[N][N][15];
int prime[N];

int dpf(int last, int n, int k) {
    if (n < 0) return 0;
    if (k == 0) return n == 0;
    int &ret = dp[last][n][k];
    if (~ret) return ret;
    ret = 0;
    for (int i = 0; i < last; i++) ret += dpf(i, n - p[i], k - 1);
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    fill(prime, prime + N, true);
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < N; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j < N; j += i) prime[j] = false;
    }
    for (int i = 2; i < N; i++) if (prime[i]) p.push_back(i);

    memset(dp, -1, sizeof(dp));
    int t; cin >> t;
    while (t--) {
        int n, k; cin >> n >> k;
        cout << dpf(p.size(), n, k) << "\n";
    }
}