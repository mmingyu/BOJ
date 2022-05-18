#include <bits/stdc++.h>
using namespace std;

constexpr int INF = -1e8;
vector<pair<int, int>> v[102];
int dp[102], par[102]; 
bool chk[102][102];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        v[a].emplace_back(b, c);
    }
    fill(dp, dp + 102, INF);
    for (int i = 1; i <= n; i++) chk[i][i] = true;
    dp[1] = 0;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int cur = 1; cur <= n; cur++) {
            for (const auto &[nxt, d] : v[cur]) {
                chk[cur][nxt] = true;           
                if (dp[cur] != INF && dp[nxt] < dp[cur] + d) {
                    if (i == n - 1 && chk[nxt][n]) flag = true;
                    dp[nxt] = dp[cur] + d;
                    par[nxt] = cur;
                }
            }
        }
    }

    if (flag) {
        cout << -1;
    } else {
        stack<int> st;
        int cur = n;
        while (cur != 1) {
            st.push(cur);
            cur = par[cur];
        }
        st.push(1);
        while (!st.empty()) {
            cout << st.top() << " ";
            st.pop();
        }
    }
    
}
