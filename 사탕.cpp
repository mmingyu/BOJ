#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[500005];
bool prime[500005];
int cnt[10004];
vector<int> arr;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    memset(prime, true, sizeof(prime));
    for (int i = 2; i * i <= 500000; i++) {
        if (!prime[i]) continue;
        for (int j = i * i; j <= 500000; j += i) {
            prime[j] = false;
        }
    }

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int inp; cin >> inp;
        if (inp && !cnt[inp]) {
            arr.push_back(inp);
        }
        cnt[inp]++;
    }

    dp[0] = 1;
    for (auto cur : arr) {
        for (int i = 500000; i >= 0; i--) {
            for (int j = 1; j <= cnt[cur]; j++) {
                if (i - cur * j >= 0) dp[i] += dp[i - cur * j];
            }
        }
    }

    ll ans = 0;
    for (int i = 2; i <= 500000; i++) {
        if (prime[i]) ans += dp[i];
    }
    cout <<  ans * (cnt[0] + 1);
}