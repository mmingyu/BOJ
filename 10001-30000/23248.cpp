#include <bits/stdc++.h>
using namespace std;

set<int, decltype([](int a, int b) { return a > b; })> st;
vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m, k; cin >> n >> m >> k;
    v.resize(k);
    for (auto &[r, c] : v) cin >> r >> c;
    sort(v.begin(), v.end());
    
    int ans = 0;
    for (auto [r, c] : v) {
        auto it = st.lower_bound(c);
        if (it == st.end()) {
            ans++;
            st.insert(c);
        } else {
            st.erase(it);
            st.insert(c);
        }
    }
    cout << ans;
}