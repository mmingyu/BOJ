#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define sz(x) int((x).size())

ll MOD = 1e9 + 7;

ll mod(ll a) {
    if (a >= 0) return a % MOD;
    return a % MOD + MOD;
}

int main() {
    string a, b; cin >> a >> b;
    ll phash = 0, hash = 0, pw = 1;
    bool ans = false;
    for (int i = 0; i < sz(b); i++) {
        phash = mod(mod(phash * 31) + a[i]);
        hash = mod(mod(hash * 31) + b[i]);
        if (i != 0) pw = mod(pw * 31);
    }
    if (phash == hash) ans = true;
    // printf("hash = %d\n", hash);
    for (int i = sz(b); i < sz(a); i++) {
        phash = mod(mod(mod(phash - a[i - sz(b)] * pw) * 31) + a[i]);
        if (phash == hash) ans = true;
        // printf("%d\n", phash);
    }
    printf("%d", ans);
}