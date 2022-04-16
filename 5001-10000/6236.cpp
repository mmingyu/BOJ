#include <bits/stdc++.h>
using namespace std;
#define md (l + r >> 1)

vector<int> arr;
int check(int k) {
    int cur = 0, ret = 0;
    for (auto x : arr) {
        if (x > k) return 1e8;
        if (x > cur) {
            cur = k - x;
            ret++;
        } else {
            cur -= x;
        }
    }
    return ret;
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    arr.resize(n);
    for (auto &x : arr) scanf("%d", &x);
    int l = -1, r = 1e9 + 1;
    while (l + 1 < r) {
        if (check(md) <= m) r = md;
        else l = md;
    }
    printf("%d", r);
}