#include <bits/stdc++.h>
using namespace std;

int bit[55];
int n, k;
vector<char> alpha;
int pat;
int ans;

void solve(int cur, int cnt) {
    if (cur == alpha.size() || cnt >= k) {
        int k = 0;
        for (int i = 0; i < n; i++) if ((bit[i] & pat) == bit[i]) k++;
        ans = max(ans, k);
        return;
    }
    pat |= (1 << alpha[cur]);
    solve(cur + 1, cnt + 1);
    pat &= ~(1 << alpha[cur]);
    solve(cur + 1, cnt);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 'a'; i <= 'z'; i++) {
        if (i == 'a' || i == 'i' || i == 'n' || i == 't' || i == 'c') {
            pat |= 1 << i - 'a';
            continue;
        }
        alpha.push_back(i - 'a');
    }
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (auto c : s) bit[i] |= (1 << c - 'a');
    }
    if (k < 5) {
        cout << 0;
        return 0;
    }
    solve(0, 5);
    cout << ans;
}