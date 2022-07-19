#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())


constexpr int N = 1e6 + 5;
struct Q { int s, e, i; } q[N];
int a[N], cnt[N], sqn;
ll ans[N], x;

void pl(int i) {
    x -= 1LL * a[i] * cnt[a[i]] * cnt[a[i]];
    cnt[a[i]]++;
    x += 1LL * a[i] * cnt[a[i]] * cnt[a[i]];
}

void mi(int i) {
    x -= 1LL * a[i] * cnt[a[i]] * cnt[a[i]];
    cnt[a[i]]--;
    x += 1LL * a[i] * cnt[a[i]] * cnt[a[i]];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        q[i] = {s, e, i};
    }
    
    sqn = sqrt(n);
    sort(q, q + m, [&](const Q &a, const Q &b) {
        if (a.s / sqn != b.s / sqn) return a.s < b.s;
        return a.e < b.e;
    });

    int s = q[0].s, e = q[0].e;
    for (int i = s; i <= e; i++) pl(i);
    ans[q[0].i] = x;

    for (int i = 1; i < m; i++) {
        const auto &[qs, qe, qi] = q[i];
        while (e < qe) pl(++e);
        while (qs < s) pl(--s); 
        while (s < qs) mi(s++); 
        while (qe < e) mi(e--);
        ans[qi] = x;
    }

    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}