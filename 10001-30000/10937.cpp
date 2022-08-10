#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 12;
string s;
int dp[N * N][1 << N], n;
int val[3][3] = {
    {100, 70, 40},
    {70, 50, 30},
    {40, 30, 20}};

inline int cal(char a, char b) {
    if (a == 'F' || b == 'F') return 0;
    return val[a - 'A'][b - 'A'];
}

int dpf(int cur, int bit) {
    int &ret = dp[cur][bit];
    if (cur == n * n) return bit ? -1e9 : 0;
    if (~ret) return ret;
    ret = dpf(cur + 1, bit >> 1);
    if (!(bit & 1) && cur / n != n - 1) 
        ret = max(ret, dpf(cur + 1, (bit | (1 << n)) >> 1) + cal(s[cur], s[cur + n]));
    if (!(bit & 3) && cur % n != n - 1) 
        ret = max(ret, dpf(cur + 2, bit >> 2) + cal(s[cur], s[cur + 1]));
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string ss; cin >> ss;
        s += ss;
    }
    memset(dp, -1, sizeof(dp));
    cout << dpf(0, 0);
}