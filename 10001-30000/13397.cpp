#include <iostream>
#include <algorithm>

using namespace std;

int arr[5003];
int n, m; 

bool chk(int k) {
    int ret = 0, mn = 1e9, mx = 0;
    for (int i = 0; i < n; i++) {
        mn = min(mn, arr[i]);
        mx = max(mx, arr[i]);
        if (mx - mn > k) ret++, mx = arr[i], mn = arr[i];
    }
    return ret < m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = -1, r = 10004;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (chk(mid)) r = mid;
        else l = mid;
    }
    cout << r;
}