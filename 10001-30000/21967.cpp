#include <bits/stdc++.h>
using namespace std;

int arr[1000006], cnt[11];

int get_min() { 
    for (int i = 1; i <= 10; i++) if (cnt[i]) return i; 
    return 0;
}
int get_max() { 
    for (int i = 10; i >= 1; i--) if (cnt[i]) return i;
    return 0;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0, r = 1, ans = 1;
    int mn = arr[l], mx = arr[l]; 
    cnt[arr[l]]++;
    while (r <= n) {
        while (l < r && mx - mn > 2) {
            cnt[arr[l]]--; 
            mn = get_min();
            mx = get_max();
            l++;
        }
        ans = max(ans, r - l);
        mn = min(mn, arr[r]);
        mx = max(mx, arr[r]);
        cnt[arr[r]]++;
        r++;
    }
    cout << ans;
}