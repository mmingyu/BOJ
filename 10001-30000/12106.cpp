#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 102;
constexpr ll MOD = 1e9 + 9;
vector<int> fail;
string p;
ll dp[N][N][N];
int n;

vector<int> getFail(const string &p) {
    int n = p.size();
    vector<int> fail(n);
    for (int i = 1, j = 0; i < n; i++) {
        while (j > 0 && p[i] != p[j]) j = fail[j - 1];
        if (p[i] == p[j]) fail[i] = ++j;
    }
    return fail;
}

ll dpf(int cur, int cnt, char c) {
    if (cur == n) return cnt == p.size();
    ll &ret = dp[cur][cnt][c - 'a'];
    if (~ret) return ret;

    ret = 0;
    for (int i = 'a'; i <= 'z'; i++) {
        if (cnt == p.size()) {
            ret += dpf(cur + 1, cnt, i);
            ret %= MOD;
            continue;
        }
        if (i == p[cnt]) {
            ret += dpf(cur + 1, cnt + 1, i);
            ret %= MOD;
        } else {
            int j = cnt;
            while (j > 0 && i != p[j]) j = fail[j - 1];
            ret += dpf(cur + 1, j + (i == p[j]), i);
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> p;
    fail = getFail(p);
    memset(dp, -1, sizeof(dp));
    cout << dpf(0, 0, 'a');
}