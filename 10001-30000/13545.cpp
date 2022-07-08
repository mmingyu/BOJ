#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 3e5 + 5;
struct Q { int s, e, i; } q[N];
int psum[N], cnt[N], buk[500], ans[N], sqn;
list<int> d[N];

void pl(int i, int f) {
    auto &dq = d[psum[i]];
    if (!dq.empty()) {
        int x = dq.back() - dq.front();
        cnt[x]--; buk[x / sqn]--;
    }
    if (f) dq.push_front(i);
    else dq.push_back(i);
    int x = dq.back() - dq.front();
    cnt[x]++; buk[x / sqn]++;
}

void mi(int i, int f) {
    auto &dq = d[psum[i]];
    int x = dq.back() - dq.front();
    cnt[x]--; buk[x / sqn]--;
    if (f) dq.pop_front();
    else dq.pop_back();
    if (!dq.empty()) {
        int x = dq.back() - dq.front();
        cnt[x]++; buk[x / sqn]++;
    }
}

int query() {
    for (int i = 499; i >= 0; i--) if (buk[i]) {
        for (int j = sqn - 1; j >= 0; j--) {
            if (int x = i * sqn + j; cnt[x] > 0) return x;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    sqn = sqrt(n);
    for (int i = 1; i <= n; i++) cin >> psum[i], psum[i] += psum[i - 1];
    for (int i = 0; i <= n; i++) psum[i] += 1e5;

    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        q[i] = {s - 1, e, i};
    }
    sort(q, q + m, [&](const Q &a, const Q &b) {
        if (a.s / sqn != b.s / sqn) return a.s < b.s;
        return a.e < b.e;
    });
    int s = q[0].s, e = q[0].e;
    for (int i = s; i <= e; i++) pl(i, 0);
    ans[q[0].i] = query();
    for (int i = 1; i < m; i++) {
        const auto &[qs, qe, qi] = q[i];
        while (qs < s) pl(--s, 1);
        while (e < qe) pl(++e, 0);
        while (s < qs) mi(s++, 1);
        while (qe < e) mi(e--, 0);
        ans[qi] = query();
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}