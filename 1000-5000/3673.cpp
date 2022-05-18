#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e6 + 6;
int cnt[N];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    while (tc--) {
        memset(cnt, 0, sizeof(cnt));
        int d, n; cin >> d >> n;
        long long sum = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            sum = (sum + x) % d;
            cnt[sum]++;
        }
        ans += cnt[0];
        for (int i = 0; i < d; i++) {
            ans += 1LL * cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans << "\n";
    }
}