#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

int arr[200005][4];
bool price[200005];

int main() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x >> arr[x][0] >> arr[x][1] >> arr[x][2] >> arr[x][3];
    }
    for (int i = 0; i < 4; i++) {
        int mx = -1, mx_idx = -1;
        for (int j = 1; j <= n; j++) {
            if (price[j]) continue;
            if (mx < arr[j][i]) {
                mx = arr[j][i];
                mx_idx = j;
            }
        }
        price[mx_idx] = true;
        printf("%d ", mx_idx);
    }
}