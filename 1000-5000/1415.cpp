#include <iostream> 
#include <algorithm> // swap, fill
#include <vector> 
#include <cstring> // memset
using namespace std;
using ll = long long;

ll dp[500005], dp_nxt[500005];
bool prime[500005];
int cnt[10004];
vector<int> arr; // 사탕을 저장

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    fill(prime, prime + 500005, true);
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
        for (int i = 0; i <= 500000; i++) {
            dp_nxt[i] += dp[i];
            for (int j = 1; j <= cnt[cur]; j++) {
                if (i - cur * j >= 0) dp_nxt[i] += dp[i - cur * j];
            }
        }
        swap(dp, dp_nxt);
        memset(dp_nxt, 0, sizeof(dp_nxt));
    }

    ll ans = 0;
    for (int i = 2; i <= 500000; i++) {
        if (prime[i]) ans += dp[i];
    }
    cout <<  ans * (cnt[0] + 1);
}