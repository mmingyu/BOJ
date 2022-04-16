#include <bits/stdc++.h>
using namespace std;

int cnt[30];

int main() {
    string s; cin >> s;
    for (auto c : s) cnt[c - 'A']++;
    int k = 0;
    for (int i = 0; i < 26; i++) k += (cnt[i] % 2);
    if (k > 1) {
        cout << "I'm Sorry Hansoo";
        return 0;
    }
    string ans;
    char mid = 0;
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnt[i] / 2; j++) ans.push_back(i + 'A');
        if (cnt[i] % 2) mid = i + 'A';
        cnt[i] /= 2;
    }
    if (mid) ans.push_back(mid);
    for (int i = 26; i >= 0; i--) {
        for (int j = 0; j < cnt[i]; j++) ans.push_back(i + 'A');
    }
    cout << ans;
}