#include <bits/stdc++.h>
using namespace std;
#define idx !!(x & i)

struct Trie {
    Trie *trie[2];
    Trie() { trie[0] = trie[1] = nullptr; }

    void update(int x) {
        Trie *cur = this;
        for (int i = 1 << 30; i; i >>= 1) {
            if (cur->trie[idx] == nullptr) cur->trie[idx] = new Trie();
            cur = cur->trie[idx];
        }
    }

    int cal(int x) {
        int ret = 0;
        Trie *cur = this;
        for (int i = 1 << 30; i; i >>= 1) {
            if (cur->trie[!idx] != nullptr) {
                ret += i; 
                cur = cur->trie[!idx];
            } else {
                cur = cur->trie[idx];
            }
        }
        return ret;
    }
};

Trie root;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int n, x; cin >> n >> x;
    root.update(x);
    int ans = 0;
    for (int i = 0; i < n-1; i++) {
        cin >> x;
        ans = max(ans, root.cal(x));
        root.update(x);
    }
    cout << ans;
}