#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++) {
        int x; cin >> x;
        v.push_back({x, i + 1});
    }
    sort(v.rbegin(), v.rend());
    if (v[0].first > n - v[0].first + 1) { cout << -1; return 0; }

    vector<int> arr;
    vector<int> ans(n);
    for (auto [f, s] : v) while (f--) arr.push_back(s);
    int idx = 0;
    for (int i = 0; i < n; i += 2) ans[i] = arr[idx++];
    for (int i = 1; i < n; i += 2) ans[i] = arr[idx++];
    cout << endl;
    for (int x : ans) cout << x << " ";
}
