#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 4;
vector<int> v[N];

int seq[N], lev[N], ans[N][2], par[N];

int cnt = 1;

int find_root() {
    int cur = 1;
    while (par[cur]) {
        cur = par[cur];
    }
    return cur;
}

void dfs(int cur) {
    if (v[cur][0] != -1) {
        lev[v[cur][0]] = lev[cur] + 1;
        dfs(v[cur][0]);
    }

    seq[cur] = cnt++;
    ans[lev[cur]][0] = min(seq[cur], ans[lev[cur]][0]);
    ans[lev[cur]][1] = max(seq[cur], ans[lev[cur]][1]);

    if (v[cur][1] != -1) {
        lev[v[cur][1]] = lev[cur] + 1;
        dfs(v[cur][1]);
    }
}

int main() {
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int k, l, r; scanf("%d %d %d", &k, &l, &r);
        v[k].push_back(l);
        v[k].push_back(r);
        par[l] = k;
        par[r] = k;
    }
    for (int i = 0; i < N; i++) {
        ans[i][0] = 1e9;
        ans[i][1] = -1;
    }
    int root = find_root();
    lev[root] = 1;
    dfs(root);
    // for (int i = 1; i <= n; i++) printf("%d\n", seq[i]);
    int ans_lev = -1, ans_width = -1;
    for (int i = 1; i <= n; i++) {
        int cal = ans[i][1] - ans[i][0] + 1;
        if (ans[i][0] == 1e9 || ans[i][1] == -1) cal = 1;
        if (cal > ans_width) {
            ans_lev = i;
            ans_width = cal;
        }
    }
    printf("%d %d", ans_lev, ans_width);
}