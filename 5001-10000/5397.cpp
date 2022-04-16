#include <bits/stdc++.h>
using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        list<char> li;
        string s; cin >> s;
        auto it = li.begin();
        for (auto c : s) {
            if (c == '<') {
                if (it != li.begin()) it--;
            } else if (c == '>') {
                if (it != li.end()) it++;                
            } else if (c == '-') {
                if (it != li.begin()) {
                    auto tmp = it;
                    li.erase(--tmp);
                }
            } else {
                li.insert(it, c);
            }
        }
        for (auto c : li) cout << c;
        cout << '\n';
    }
}