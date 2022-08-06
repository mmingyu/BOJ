#include <bits/stdc++.h>
using namespace std;

int arr[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int l; cin >> l;
    for (int i = 0; i < l; i++) cin >> arr[i];
    int n; cin >> n;
    sort(arr, arr + l);
    
    int it = lower_bound(arr, arr + l, n) - arr;

    if (n == arr[it]) cout << 0;
    else if (it == 0) cout << n * (arr[0] - n) - 1;
    else cout << (arr[it] - n) * (n - arr[it - 1]) - 1;
}
