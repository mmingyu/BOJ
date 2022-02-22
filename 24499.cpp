#include <bits/stdc++.h>
using namespace std;

int arr[200005];

int main() {
    int n, k; scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
        arr[i + n] = arr[i];
    }
    int cur = 0, ans = 0;
    for (int i = 0; i < 2 * n; i++) {
        if (i < k) {
            cur += arr[i];
        } else {
            cur += arr[i];
            cur -= arr[i - k];
        }
        ans = max(cur, ans);
    }
    printf("%d", ans);
}