#include <bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    vector<string> v;
    for (int i = 0; i < s.size(); i++) {
        v.push_back(string(s.begin() + i, s.end()));
    }
    stable_sort(v.begin(), v.end());
    for (const auto &s : v) cout << s << "\n";
}