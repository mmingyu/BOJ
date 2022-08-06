#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int n, ans; 
vector<int> v, ansv;

bool chk() {
    for (int i = 0; i < sz(v); i++) {
        for (int j = i + 1; j < sz(v); j++) {
            for (int k = j + 1; k < sz(v); k++) {
                if ((v[i] ^ v[j] ^ v[k]) == 0) return false;
            }
        }
    }
    return true;
}

void solve(int cur) {
    if (cur == n + 1) {
        if (sz(v) > ans && chk()) ansv = v, ans = sz(v);
        return;
    }
    v.push_back(cur);
    solve(cur + 1);
    v.pop_back();
    solve(cur + 1);
}

void test_case() {
    cin >> n;
    solve(1);
    cout << ans << "\n";
    for (int x : ansv) cout << x << " ";
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int tc; cin >> tc;
    for (int t = 1; t <= tc; t++) {
        test_case();
    }
}