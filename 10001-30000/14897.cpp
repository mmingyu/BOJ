#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

constexpr int N = 1e6 + 6;
struct Q { int s, e, i; } q[N];
int arr[N], cnt[N], ans[N], sqn, k;

inline void pl(int i) { if (cnt[arr[i]]++ == 0) k++; }
inline void mi(int i) { if (--cnt[arr[i]] == 0) k--; }

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> v(arr, arr + n);
    compress(v);
    for (int i = 0; i < n; i++) arr[i] = lower_bound(all(v), arr[i]) - v.begin();
    int m; cin >> m;
    for (int i = 0; i < m; i++) {
        int s, e; cin >> s >> e;
        q[i] = {s - 1, e - 1, i};
    }
    sqn = sqrt(n);
    sort(q, q + m, [&](const Q &a, const Q &b) {
        if (a.s / sqn != b.s / sqn) return a.s < b.s;
        return a.e < b.e;
    });
    int s = q[0].s, e = q[0].e;
    for (int i = s; i <= e; i++) pl(i);
    ans[q[0].i] = k;
    for (int i = 1; i < m; i++) {
        const auto &[qs, qe, qi] = q[i];
        while (qs < s) pl(--s);
        while (e < qe) pl(++e);
        while (s < qs) mi(s++);
        while (qe < e) mi(e--);
        ans[qi] = k; 
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}
