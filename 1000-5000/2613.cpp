#include <bits/stdc++.h>
using namespace std;

vector<int> arr;

int count(int k) {
    int ret = 0, sum = 0;
    for (auto x : arr) {
        if (sum + x > k) {
            sum = 0;
            ret++;
        }
        sum += x;
    }
    return ret + 1;
}

int main() {
    int n, m; cin >> n >> m;
    arr.resize(n);
    for (auto &x : arr) {
        cin >> x;
    }
    int l = *max_element(arr.begin(), arr.end()) - 1, r = 3e4;
    while (l + 1 < r) {
        int mid = l + r >> 1;
        if (count(mid) > m) l = mid;
        else r = mid;
    }
    printf("%d\n", r);
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (sum + arr[i] > r) {
            printf("%d ", cnt);
            cnt = sum = 0;
            m--;
        }
        sum += arr[i];
        cnt++;
        if (n - i == m) break;
    }
    printf("%d ", cnt);
    m--;
    while (m--) {
        printf("1 ");
    }
}