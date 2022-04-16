#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

const int N = 5e5 + 5;
pll arr[N];
ll psum[N], mn[N], diff[N];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
       ll a, b; scanf("%lld %lld", &a, &b);
       arr[i] = {b, a};
    }
    sort(arr, arr + n);
    psum[0] = arr[0].first;
    diff[0] = arr[0].first - arr[0].second;
    for (int i = 1; i < n; i++) {
        auto [b, a] = arr[i];
        psum[i] = psum[i - 1] + b;
        diff[i] = max(diff[i - 1], b - a);
    }
    mn[n - 1] = arr[n - 1].second;
    for (int i = n - 2; i >= 0; i--) {
        mn[i] = min(mn[i + 1], arr[i].second);
    }
    printf("%lld\n", mn[0]);
    for (int i = 1; i < n; i++) {
        auto [b, a] = arr[i];
        ll ans = min(psum[i - 1] + mn[i], psum[i] - diff[i]);
        // printf("%lld : %lld %lld\n", psum[i], psum[i - 1] + mn[i], psum[i] - diff[i]);
        printf("%lld\n", ans);
    }
}