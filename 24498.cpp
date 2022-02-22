#include <bits/stdc++.h>
using namespace std;

int arr[1000006];

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    int ans = max(arr[0], arr[n - 1]);
    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, arr[i] + min(arr[i - 1], arr[i + 1]));
    }
    printf("%d", ans);
}