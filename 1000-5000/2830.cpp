#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int cnt[32];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; x > 0; x >>= 1, j++) cnt[j] += (x & 1);
    }
    ll ret = 0;
    for (int i = 0; i < 32; i++) {
        ret += 1LL * (1 << i) * (n - cnt[i]) * cnt[i];
    }
    cout << ret;
}