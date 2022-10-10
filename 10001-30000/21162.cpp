#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 2e5 + 5;

template<ll C, ll M> struct Hashing {
    vector<ll> h, pw;
    void build(const vector<int> &s) {
        h.resize(s.size()+1);
        pw.resize(s.size()+1);
        pw[0] = 1;
        for (int i = 1; i <= s.size(); i++) {
            h[i] = (h[i-1] * C + s[i]) % M;
            pw[i] = (pw[i-1] * C) % M;
        }
    }
    ll get(int l, int r) {
        ll ret = (h[r] - h[l-1] * pw[r-l+1]) % M;
        return ret >= 0 ? ret : ret + M;
    }
};


int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    reverse(all(arr));
    for (int i = 0; i < n; i++) arr.push_back(arr[i]);

    Hashing<524287LL, ll(1e9 + 7)> hash;
    hash.build(arr);

    vector<int> v(n - 1);
    iota(all(v), 1);
    
    stable_sort(v.begin(), v.end(), [&](const int a, const int b) {
        int l = -1, r = n;
        while (l + 1 < r) {
            int mid = l + r >> 1;
            ll h1 = hash.get(a, a + mid);
            ll h2 = hash.get(b, b + mid);
            if (h1 == h2) l = mid;
            else r = mid;
        }
        return r != n && arr[a + r] < arr[b + r];
    });
    for (int i = 0; i < n; i++) cout << arr[v[k - 1] + i] << " ";
}

