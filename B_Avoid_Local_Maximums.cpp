#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

int arr[200005];

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int cnt = 0;
        for (int i = 1; i < n - 1; i++) {
            if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
                if (i + 2 < n) arr[i + 1] = max(arr[i], arr[i + 2]);
                else arr[i + 1] = arr[i];
                cnt++;
            }
        }
        printf("%d\n", cnt);
        for (int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}