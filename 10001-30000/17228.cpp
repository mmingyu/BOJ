#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())

constexpr int N = 5e5 + 5;
constexpr ll C = 917, M = 1e9 + 7;

vector<pair<int, char>> v[N];
vector<ll> st;
ll phash, pw = 1;
string s; 
int ans;

void dfs(int cur) {
    if (st.size() > s.size()) {
        ll hash = (st.back() - st[st.size() - s.size() - 1] * pw) % M;
        hash = (hash + M) % M;
        if (hash == phash) ans++;
    }

    for (auto [nxt, c] : v[cur]) {
        st.push_back((st.back() * C + c) % M);
        dfs(nxt);
        st.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b; char c; cin >> a >> b >> c;
        v[a].push_back({b, c});
    }
    cin >> s;

    for (auto c : s) {
        phash = (phash * C + c) % M;
        pw = (pw * C) % M;
    }

    st.push_back(0);
    dfs(1);
    cout << ans;
}