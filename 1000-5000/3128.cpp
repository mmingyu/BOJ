#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define all(x) (x).begin(), (x).end()
#define sz(x) int((x).size())
#define compress(v) sort(all(v)), v.erase(unique(all(v)), v.end())
inline int ord(char c) { return c - 'A'; }

int ans = 2e9;
string ans_s;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    string s, tmp; while (cin >> tmp) s += tmp;
    compress(s);
    if (sz(s) == 1) {
        cout << 1 + min(26 - ord(s[0]), ord(s[0])) << "\n";
        cout << s[0];
        return 0;
    }
    ans = ord(s.back()); ans_s = s;
    if (ans > 26 - ord(s[0])) ans = 26 - ord(s[0]), ans_s = string(s.rbegin(), s.rend());

    for (int i = 0; i + 1 < sz(s); i++) {
        int a = ord(s[i]), b = ord(s[i + 1]);
        // l : left로 b 찍고 right로 a
        // r : right로 a 찍고 left로 b
        int l = 2 * (26 - b) + a;
        int r = 2 * a + (26 - b);
        ans = min({ans, l, r});
        if (ans == l) {
            string ss;
            for (int k = sz(s) - 1; k >= 0 && s[k] != s[i + 1]; k--) ss += s[k];
            ss += s[i + 1];
            for (int k = 0; k < sz(s) && s[k] != s[i]; k++) ss += s[k];
            ss += s[i];
            ans_s = ss;
        }
        if (ans == r) {
            string ss;
            for (int k = 0; k < sz(s) && s[k] != s[i]; k++) ss += s[k];
            ss += s[i];
            for (int k = sz(s) - 1; k >= 0 && s[k] != s[i + 1]; k--) ss += s[k];
            ss += s[i + 1];
            ans_s = ss;
        }
    }
    cout << ans + sz(s) << "\n" << ans_s;
}
