#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(0)->sync_with_stdio(0)

struct T { int x, y, z; };
int arr[200005];

int main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        int y = n - 2, z = n - 1;
        if (arr[y] > arr[z]) {
            printf("-1\n");
        } else {
            if (arr[z] < 0) {
                if (is_sorted(arr, arr + n)) printf("0\n");
                else printf("-1\n");
                continue;
            }
            printf("%d\n", n - 2);
            for (int i = 0; i <= n - 3; i++) {
                printf("%d %d %d\n", i + 1, y + 1, z + 1);
            }
        }
    }
}