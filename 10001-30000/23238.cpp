#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
constexpr int N = 1e5 + 6;
struct Q { int s, e, i; } q[N];
int buk[400], ori[N], cnt[N], num[400][N], ans[N], sqn;
int mx, grpn, s, e, n, m;
vector<int> tmp, arr;

void pl(int i) {
    int g = i / sqn;
    if (cnt[i] == buk[g]) buk[g]++;
    --num[g][cnt[i]++];
    ++num[g][cnt[i]];
}

void mi (int i) {
    int g = i / sqn;
    --num[g][cnt[i]--];
    ++num[g][cnt[i]];
    if (num[g][buk[g]] == 0) --buk[g];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    arr.resize(n);
    sqn = sqrt(n);
    for (int &x : arr) {
        cin >> x; 
        tmp.push_back(x);
    }
    compress(tmp);
    for (int &x : arr) {
        int idx = lower_bound(all(tmp), x) - tmp.begin();
        ori[idx] = x;
        x = idx;
    }
    mx = arr[n - 1];
    grpn = mx / sqn + 1;
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        q[i] = {l - 1, r - 1, i};
    }
    sort(q, q + m, [&](const Q &a, const Q &b){
        if (a.s / sqn != b.s / sqn) return a.s < b.s;
        return a.e < b.e;
    });

    s = 0, e = -1;
    for (int i = 0; i < m; i++) {
        while (e < q[i].e) pl(arr[++e]);
        while (q[i].s < s) pl(arr[--s]);
        while (q[i].e < e) mi(arr[e--]);
        while (s < q[i].s) mi(arr[s++]);

        int idx = 0;
        for (int j = 0; j <= n / sqn; j++) {
            if(buk[idx] <= buk[j]) idx = j;
        }
        int mxi = sqn * idx;
        for (int j = 0; j < sqn && sqn * idx + j < N; j++) {
            if (cnt[mxi] <= cnt[sqn * idx + j]) mxi = sqn * idx + j;
        }
        ans[q[i].i] = ori[mxi];
    }
    for (int i = 0; i < m; i++) cout << ans[i] << "\n";
}
