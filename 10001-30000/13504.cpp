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

int pxor[100005];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        Trie root;
        int n; cin >> n;
        for (int i = 1, x; i <= n; i++) cin >> x, pxor[i] = pxor[i - 1] ^ x;
        int ans = 0;
        root.update(pxor[1]);
        for (int i = 2; i <= n; i++) {
            ans = max({ans, pxor[i], root.cal(pxor[i])});
            root.update(pxor[i]);
        }
        cout << ans << "\n";
    }
}