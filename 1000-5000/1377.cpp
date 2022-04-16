#include <bits/stdc++.h>
using namespace std;

pair<int, int> arr[500005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int inp; cin >> inp;
        arr[i] = {inp, i};
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, arr[i].second - i);
    }
    cout << ans + 1;
}