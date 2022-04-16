#include <bits/stdc++.h>
using namespace std;

vector<int> v[10004];
int arr[10004];
bool visited[10004];

int cnt = 0;
void dfs(int cur) {
    visited[cur] = true;
    for (const auto& nxt : v[cur]) {
        if (!visited[nxt]) {
            dfs(nxt);
            cnt++;
        }
    }
}

int main() {
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b; scanf("%d %d", &a, &b);
        v[b].push_back(a);
    }
    int mx = -1;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        memset(visited, false, sizeof(visited));
        dfs(i);
        arr[i] = cnt;
        mx = max(mx, cnt);
    }
    for (int i = 1; i <= n; i++) if (arr[i] == mx) printf("%d ", i);
}