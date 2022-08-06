#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

bool chk[202][202];
vector<int> v;
int n, m, ans; 

void solve(int cur) {
    if (v.size() == 3) {
        for (int i = 0; i < 3; i++) {
            for (int j = i + 1; j < 3; j++) {
                if (chk[v[i]][v[j]]) return;
            }
        }
        ans++;
        return;
    }
    if (cur == n + 1) return;

    v.push_back(cur);
    solve(cur + 1);
    v.pop_back();
    solve(cur + 1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        chk[a][b] = true;
        chk[b][a] = true;
    }
    solve(1);    
    cout << ans;
}