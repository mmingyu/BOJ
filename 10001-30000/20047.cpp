#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

int n, rm[2];
string a, b;
int dp[10004][3];

int dpf(int cur, int cnt) {
    if (cur == n) return cnt == 2;
    int &ret = dp[cur][cnt];
    if (~ret) return ret;
    ret = 0;
    if (a[cur - cnt] == b[cur]) ret = max(ret, dpf(cur + 1, cnt));
    if (cnt < 2 && b[cur] == rm[cnt]) ret = max(ret, dpf(cur + 1, cnt + 1));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    cin >> n >> a >> b >> rm[0] >> rm[1];
    string tmp;
    for (int i = 0; i < n; i++) {
        if (i == rm[0] || i == rm[1]) continue;
        tmp += a[i];
    }
    rm[0] = a[rm[0]];
    rm[1] = a[rm[1]];
    a = tmp;
    cout << (dpf(0, 0) ? "YES" : "NO");
}