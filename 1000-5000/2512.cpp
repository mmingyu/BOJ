#include <bits/stdc++.h>
using namespace std;

int n, m, arr[10004];

bool chk(int k) {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > k) ret += k;
        else ret += arr[i];
        if (ret > m) return true;
    }
    return false;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    cin >> m;
    int l = -1, r = *max_element(arr, arr + n) + 1;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (chk(mid)) r = mid;
        else l = mid;
    }
    cout << l;
}