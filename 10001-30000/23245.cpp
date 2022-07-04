#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mid (s + e >> 1)
#define f first
#define s second

class SegTree {
private:
    const int N;
    vector<ll> tree;
public:
    SegTree(int N) : N(N) { tree.resize(4 * N); }
    void update(int idx, ll diff, int node, int s, int e) {
        if (idx < s || idx > e) return;
        tree[node] += diff;
        if (s == e) return;
        update(idx, diff, 2*node, s, mid);
        update(idx, diff, 2*node + 1, mid + 1, e);
    }
    void update(int idx, int diff) { update(idx, diff, 1, 0, N); }

    ll query(int qs, int qe, int node, int s, int e) {
        if (qs <= s && e <= qe) return tree[node];
        if (qe < s || e < qs) return 0;
        return query(qs, qe, 2*node, s, mid) + query(qs, qe, 2*node + 1, mid + 1, e);
    }
    ll query(int qs, int qe) { return query(qs, qe, 1, 0, N); }
};


pair<int, int> arr[100005];
long long ans;
constexpr int INF = 1e6 + 6;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    SegTree t1(INF), t2(INF);
    for (int i = 0; i < n; i++) cin >> arr[i].f;
    for (int i = 0; i < n; i++) cin >> arr[i].s, t2.update(arr[i].s, 1);
    sort(arr, arr + n);
    
    for (int i = 0; i < n; i++) {
        int s = i, e = i;
        while (e < n - 1 && arr[i].f == arr[e + 1].f) e++;
        for (int j = s; j <= e; j++) t2.update(arr[j].s, -1);
        for (int j = s; j <= e; j++) ans += t1.query(0, arr[j].s - 1) * t2.query(arr[j].s + 1, INF);
        for (int j = s; j <= e; j++) t1.update(arr[j].s, 1);
        i = e;
    }
    cout << ans;
}