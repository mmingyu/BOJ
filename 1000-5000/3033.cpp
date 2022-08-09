#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr ll MOD = 1e5 + 3;
struct modint {
    modint(ll x) : x(x) {}
    ll x;
    void operator+=(const ll &y) { x = (x + y) % MOD; }
    void operator-=(const ll &y) { x = (x - y + MOD) % MOD; }
    void operator*=(const ll &y) { x = (x * y) % MOD; }
    void operator=(const ll &y) { x = y; }
    ll operator*(const ll &y) { return (x * y) % MOD; }
};

string s; 
int len;

bool chk(int n) {
    vector<int> vis[MOD];
    for (int i = 0; i < MOD; i++) vis[i].clear();
    modint hash(0), pw(1);
    for (int i = n - 1; i >= 0; i--) {
        hash += pw * (s[i] - 'a');
        pw *= 31;
    }
    vis[hash.x].push_back(0);
    for (int i = n; i < len; i++) {
        hash *= 31;
        hash -= pw * (s[i - n] - 'a');
        hash += s[i] - 'a';
        if (sz(vis[hash.x])) {
            for (const int &x : vis[hash.x]) {
                if (!s.compare(x, n, s, i - n + 1, n)) return true;
            }
        }
        vis[hash.x].push_back(i - n + 1);
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> len >> s;
    int l = 0, r = len;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (chk(mid)) l = mid;
        else r = mid;
    }

    cout << l;
}