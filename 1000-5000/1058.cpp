#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

char arr[55][55];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) if (i != j) {
            if (arr[i][j] == 'Y') { cnt++; continue; }
            for (int k = 0; k < n; k++) {
                if (arr[i][k] == 'Y' && arr[j][k] == 'Y') { cnt++; break; }
            }
        }
        ans = max(cnt, ans);
    }
    cout << ans;
}