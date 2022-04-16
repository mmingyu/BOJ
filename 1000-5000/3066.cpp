#include <bits/stdc++.h>
using namespace std;

int arr[400005];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int tc; cin >> tc;
    while (tc--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> lis;
        lis.push_back(-1);
        for (int i = 0; i < n; i++) {
            if (arr[i] > lis.back()) lis.push_back(arr[i]);
            else *lower_bound(lis.begin(), lis.end(), arr[i]) = arr[i];
        }
        cout << lis.size() - 1 << '\n';
    }
}