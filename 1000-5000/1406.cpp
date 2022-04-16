#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    list<char> l;
    for (auto c : s) l.push_back(c);
    int n; cin >> n;
    auto iter = l.end();
    while (n--) {
        char inp; cin >> inp;
        if (inp == 'L') {
            if (iter != l.begin()) iter--;
        } else if (inp == 'D') {
            if (iter != l.end()) iter++;
        } else if (inp == 'B') {
            if (iter != l.begin()) {
                auto tmp = iter;
                tmp--;
                l.erase(tmp);
            }
        } else {
            char c; cin >> c;
            l.insert(iter, c);
        }
    }
    for (auto c : l) cout << c;
}