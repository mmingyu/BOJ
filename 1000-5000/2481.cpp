#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define sz(x) int((x).size())

const int N = 1e5 + 5;
int arr[N], par[N], n, k; 
map<int, int> bit;
vector<int> v[N];

int main() {
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) {
        char inp[33]; scanf("%s", inp);
        int cal = 0, pw = 1;
        for (int i = k - 1; i >= 0; i--) {
            cal += (inp[i] - '0') * pw;
            pw <<= 1;
        }
        bit[cal] = i;
    }

    for (auto [num, idx] : bit) {
		for (int i = 0; i < k; i++) {
			if (bit.count(num ^ (1 << i))) {
                v[idx].push_back(bit[num ^ (1 << i)]);
            }
		}
	}

    queue<int> q;    
    q.push(1);
    par[1] = -1;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto nxt : v[cur]) {
            if (par[nxt]) continue;
            q.push(nxt);
            par[nxt] = cur;
        }         
    }

    int m; scanf("%d", &m);
    while (m--) {
        int inp; scanf("%d", &inp);
        if (!par[inp]) {
            printf("-1\n");
            continue;
        }
        vector<int> ans;
        while (inp != -1) {
            ans.push_back(inp);
            inp = par[inp];
        }
        for (int i = sz(ans) - 1; i >= 0; i--) printf("%d ", ans[i]);
        printf("\n");
    }
}

