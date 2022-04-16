#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define fastio cin.tie(0)->sync_with_stdio(0)

const int N = 1e5 + 5;
bool is_stack[N];
int init[N], arr[N];

int main() {
    fastio;
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> is_stack[i];
    for (int i = 0; i < n; i++) cin >> init[i];
    int m; cin >> m;
    for (int i = 0; i < m; i++) cin >> arr[i];
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--) if (!is_stack[i]) ans.push_back(init[i]);
    for (int i = 0; i < m; i++) ans.push_back(arr[i]);
    for (int i = 0; i < m; i++) printf("%d ", ans[i]);
}