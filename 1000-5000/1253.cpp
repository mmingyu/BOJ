#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())

bool chk[2002];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<int> v(n);
    for (int &x : v) {
        cin >> x;
        cnt[x]++;
    }
    compress(v);
    for (int i = 0; i < sz(v); i++) {
        for (int j = 0; j < sz(v); j++) {
            int idx = lower_bound(all(v), v[i] - v[j]) - v.begin();
            // printf("(%d, %d, %d)\n", v[i], v[j], v[idx]);
            if (i == j && cnt[v[i]] < 2) continue; 
            if (idx == sz(v) || v[idx] != v[i] - v[j]) continue;
            if ((idx == i || idx == j) && cnt[v[idx]] <= 1) continue;
            if (idx == i && i == j && cnt[v[idx]] < 3) continue;
            chk[i] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < sz(v); i++) {
        if (chk[i]) ans += cnt[v[i]];
        // if (chk[i]) cout << v[i] << " ";
    }
    cout << ans;
}