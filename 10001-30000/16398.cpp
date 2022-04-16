#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int arr[1003][1003];
int visited[1003];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> arr[i][j];
    }

    priority_queue<pii, vector<pii>, greater<>> pq;
    pq.push({0, 0});
    long long ans = 0;
    while (!pq.empty()) {
        auto [cost, cur] = pq.top();
        pq.pop();
        if (visited[cur]) continue;
        visited[cur] = true;
        ans += (long long)cost;
        // printf("%d %d\n", cur, cost);
        for (int i = 0; i < n; i++) {
            if (i == cur) continue;
            pq.push({arr[cur][i], i});
        }
    }
    cout << ans;
}