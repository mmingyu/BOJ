#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    vector<tuple<int, int, int>> v;
    for (int i = 0; i < n; i++) {
        int a, b, c, d; cin >> a >> b >> c >> d;
        v.push_back({b * c * d, b + c + d, a});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < 3; i++) cout << get<2>(v[i]) << " ";
}