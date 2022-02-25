#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

int main() {
    int tc; cin >> tc;
    while (tc--) {
        pii arr[3];
        for (int i = 0; i < 3; i++) scanf("%d %d", &arr[i].second, &arr[i].first);
        sort(arr, arr + 3);
        if (arr[1].first == arr[2].first) {
            printf("%d\n", arr[2].second - arr[1].second);
        } else {
            printf("0\n");
        }

        
    }
}