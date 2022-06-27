#include <bits/stdc++.h>
using namespace std;
#define mid (s + e >> 1)
#define all(x) (x).begin(), (x).end()
constexpr int N = 1e5 + 5;

vector<int> tree[4*N];
int arr[N];

void init(int node = 1, int s = 1, int e = N) {
    if (s == e) {
        tree[node].push_back(arr[s]);
        return;
    }
    init(2*node, s, mid);
    init(2*node + 1, mid + 1, e);
    for (const int &x : tree[2*node]) tree[node].push_back(x);
    for (const int &x : tree[2*node + 1]) tree[node].push_back(x);
    sort(all(tree[node]));
}

int query(int qs, int qe, int k, int node = 1, int s = 1, int e = N) {
    if (qe < s || e < qs) return 0;
    if (qs <= s && e <= qe) {
        return tree[node].end() - upper_bound(all(tree[node]), k);
    }
    int l = query(qs, qe, k, 2*node, s, mid);
    int r = query(qs, qe, k, 2*node + 1, mid + 1, e);
    return l + r;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init();
    int q; cin >> q;
    while (q--) {
        int i, j, k; cin >> i >> j >> k;
        cout << query(i, j, k) << "\n";
    }
}