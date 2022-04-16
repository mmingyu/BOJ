#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'r' && i >= 2 && s.substr(i - 2, 3) == "for") cnt++;
            if (s[i] == 'e' && i >=4 && s.substr(i - 4, 5) == "while") cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}