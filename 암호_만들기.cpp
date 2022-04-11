#include <bits/stdc++.h>
using namespace std;

vector<char> v;
int l, c; 
string ans;

bool chk(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

void solve(int cur) {
    if (cur == c || ans.size() == l) {
        if (ans.size() == l) {
            int x = 0, y = 0;
            for (auto k : ans) chk(k) ? x++ : y++;
            if (x >= 1 && y >= 2) cout << ans << "\n";
        }
        return;
    }
    ans.push_back(v[cur]);
    solve(cur + 1);
    ans.pop_back();
    solve(cur + 1);
}

int main() {
    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char inp; cin >> inp;
        v.push_back(inp);        
    }
    sort(v.begin(), v.end());
    solve(0);
}