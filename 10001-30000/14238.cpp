#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

int dp[52][52][52][4][4];
char ans[52]; 
int A, B, C;
string s; 

int dpf(int a, int b, int c, int last1, int last2) {
    if (!a && !b && !c) return true;
    int &ret = dp[a][b][c][last1][last2];
    if (ret != -1) return ret;

    if (a) {
        ans[sz(s) - (a + b + c)] = 'A';
        if (dpf(a - 1, b, c, last2, 1)) return ret = true;
    }
    if (b && last2 != 2) {
        ans[sz(s) - (a + b + c)] = 'B';
        if (dpf(a, b - 1, c, last2, 2)) return ret = true;
    }
    if (c && last1 != 3 && last2 != 3) {
        ans[sz(s) - (a + b + c)] = 'C';
        if (dpf(a, b, c - 1, last2, 3)) return ret = true;
    }
    return ret = false;
}

int main() {
    cin >> s;
    for (auto x : s) {
        if (x == 'A') A++;
        else if (x == 'B') B++;
        else C++;
    }

    memset(dp, -1, sizeof dp);    
    if (dpf(A, B, C, 0, 0)) printf("%s", ans);
    else printf("-1");
}